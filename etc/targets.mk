#######################################################################
##    __   _ _____ _______ _     _  ______ _     _ ______ __   __    ##
##    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      ##
##    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       ##
##                             nich ruby                             ##
##                                                                   ##
##             Copyright (C) 2020-2024 Alexander Nicholi             ##
##                    Released under BSD-2-Clause                    ##
#######################################################################

LIB       := $(patsubst %,-L%,$(LIBDIRS)) $(patsubst %,-l%,$(LIBS))
INCLUDE   := $(patsubst %,-isystem %,$(INCLUDES)) \
	$(patsubst %,-iquote %,$(INCLUDEL))
DEFINE    := $(patsubst %,-D%,$(DEFINES)) \
	$(patsubst %,-U%,$(UNDEFINES))
ASINCLUDE := $(patsubst %,-I%,$(INCLUDES)) \
	$(patsubst %,-I%,$(INCLUDEL))
ASDEFINE  := $(patsubst %,--defsym %=1,$(DEFINES))

OFILES := $(SFILES:.s=.s.o) \
	$(CFILES:.c=.c.o) \
	$(SNIPFILES:.snip=.snip.o) \
	$(MAPFILES:.map=.map.o) \
	$(MAPBFILES:.mapb=.mapb.o) \
	$(BSAFILES:.bsa=.bsa.o) \
	$(BSETFILES:.bset=.bset.o) \
	$(JASCFILES:.jasc=.jasc.o) \
	$(IMGFILES:.png=.png.o)

.PHONY: debug release clean format
# Remove all default implicit rules by emptying the suffixes builtin
# This causes false circular dependencies with multi-dotted file extensions
#   if we don't do this
.SUFFIXES:

## Debug build
##
# ensure NDEBUG is undefined
debug: DEFINE += -UNDEBUG
debug: CFLAGS += $(CFLAGS.DEBUG)
# nop out strip when not used, as $(REALSTRIP) is called unconditionally
debug: REALSTRIP := ':' ; # : is a no-op
debug: $(PROJECT).gba

## Release build
##
# ensure NDEBUG is defined
release: DEFINE += -DNDEBUG=1
release: ASDEFINE += --defsym NDEBUG=1
release: CFLAGS += $(CFLAGS.RELEASE)
release: REALSTRIP := $(STRIP)
release: $(PROJECT).gba

# C
%.c.o: %.c
	$(CC) -c -o $@ $(CFLAGS) $(DEFINE) $(INCLUDE) $<

# Assembly
%.s.o: %.s
	$(AS) -o $@ $(ASFLAGS) $(ASDEFINE) $(ASINCLUDE) $<

# Blockset data
%.bset.o: %.bset
	$(BIN2ASM) -s `$(EGMAN) -i $<` $< | $(AS) $(ASFLAGS) -o $@ -

# Blockset attributes
%.bsa.o: %.bsa
	$(BIN2ASM) -s `$(EGMAN) -i $<` $< | $(AS) $(ASFLAGS) -o $@ -

# Map files
%.map.o: %.map
	$(BIN2ASM) -s `$(EGMAN) -i $<` $< | $(AS) $(ASFLAGS) -o $@ -

# Map border files
%.mapb.o: %.mapb
	$(BIN2ASM) -s `$(EGMAN) -i $<` $< | $(AS) $(ASFLAGS) -o $@ -

# Palettes
%.jasc.o: %.jasc
	$(JASC2BIN) $< | $(BIN2ASM) -s `$(EGMAN) -i $<` - | \
		$(AS) $(ASFLAGS) -o $@ -

# Text snips
%.snip.o: %.snip
	$(SNIP2BIN) $< | $(BIN2ASM) -s `$(EGMAN) -i $<` - | \
		$(AS) $(ASFLAGS) -o $@ -

# Scrips
%.scrip.o: %.scrip
	$(SCRIP2O) $< $@

# Image data
%.png.o: %.png
	$(GFX2O) $< $@

$(PROJECT).elf: $(OFILES)
	$(LD) $(LDFLAGS) -o $@ $^ $(LIB)
	$(REALSTRIP) -s $@

$(PROJECT).gba: $(PROJECT).elf
	$(OCPY) -O binary $@ $<
	$(FIX) $@ $(FIXFLAGS) 1>/dev/null

clean:
	$(RM) $(OFILES)
	$(RM) $(PROJECT).elf
	$(RM) $(PROJECT).gba

format: $(CFILES) $(HFILES) $(PUBHFILES) $(PRVHFILES)
	@for _file in $^; do \
		$(FMT) -i -style=file $$_file ; \
	done
