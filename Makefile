# -*- coding: utf-8 -*-
##############################################################################
##       __   _ _____ _______ _     _  ______ _     _ ______  __   __       ##
##       | \  |   |   |       |_____| |_____/ |     | |_____]   \_/         ##
##       |  \_| __|__ |_____  |     | |    \_ |_____| |_____]    |          ##
##                                 nichruby                                 ##
##                                                                          ##
##                    Copyright © 2020 Alexander Nicholi                    ##
##                       Released under BSD-2-Clause.                       ##
##############################################################################

# name of project. used in output binary naming
PROJECT := nichruby

# system utilities
AS    := arm-none-eabi-as
CC    := arm-none-eabi-gcc
LD    := arm-none-eabi-gcc
OCPY  := arm-none-eabi-objcopy
FIX   := gbafix
PY    := env python3
FMT   := clang-format

# local utilities
BIN2ASM := $(PY) util/bin2asm.py
GFX2O   := $(PY) util/gfx2o.py
DIR2SYM := $(PY) util/dir2sym.py

# flags
ASFLAGS := -mcpu=arm7tdmi -march=armv4t -mthumb-interwork -mthumb
CFLAGS  := -ansi -O2 -Wall -fno-strict-aliasing -mcpu=arm7tdmi -march=armv4t \
	-mthumb-interwork -ffreestanding
ICFLAGS := $(CFLAGS) -marm -mlong-calls
RCFLAGS := $(CFLAGS) -mthumb
LDFLAGS := -specs=$(DEVKITARM)/arm-none-eabi/lib/gba.specs

# sources
SFILES := \
	src/crt0.s
CFILES :=
HFILES := \
	include/const/ability.h \
	include/const/batanim.h \
	include/const/battle.h \
	include/const/bmovefx.h
IMGFILES :=
PCMFILES :=
OFILES := $(SFILES:.s=.s.o) $(CFILES:.c=.c.o) \
	$(IMGFILES:.png=.png.o) $(PCMFILES:.pcm=.pcm.o)

# space-separated path list for #includes
INCLUDES := include

# space-separated library name list for linking
LIBS    :=
LIBDIRS :=

# Variable transformations for command invocation
LIB := $(patsubst %,-L%,$(LIBDIRS)) $(patsubst %,-l%,$(LIBS))
INCLUDE := $(patsubst %,-I%,$(INCLUDES))

# targets
.PHONY: default clean format

default: $(PROJECT).gba

$(IMGFILES): ;
$(PCMFILES): ;

$(PROJECT).gba: $(PROJECT).elf
	$(OCPY) -O binary $< $@
	$(FIX) $@ -p -t'PROJECT TRIN' -cCTRE -m01 -r00 -d0

$(PROJECT).elf: $(OFILES)
	$(LD) $(LDFLAGS) -o $@ $^ $(LIB)

%.pcm.o: %.pcm.s
	$(AS) $(ASFLAGS) $(INCLUDE) -o $@ $<

%.pcm.s: %.pcm
	$(BIN2ASM) $< $@ -s `$(DIR2SYM) $<`_pcm

%.png.o: %.png
	$(GFX2O) $< $@

%.iwram.c.o: %.iwram.c
	$(CC) $(ICFLAGS) $(INCLUDE) -c -o $@ $<

%.c.o: %.c
	$(CC) $(RCFLAGS) $(INCLUDE) -c -o $@ $<

%.s.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	@echo 'Cleaning project...'
	@$(RM) $(PROJECT).gba
	@$(RM) $(PROJECT).elf
	@$(RM) $(OFILES)

format: $(CFILES) $(HFILES)
	for _file in $^; do \
		$(FMT) -i -style=file $$_file ; \
	done
	unset _file
