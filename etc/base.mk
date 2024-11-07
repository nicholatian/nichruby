#######################################################################
##    __   _ _____ _______ _     _  ______ _     _ ______ __   __    ##
##    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      ##
##    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       ##
##                             nich ruby                             ##
##                                                                   ##
##             Copyright (C) 2020-2024 Alexander Nicholi             ##
##                    Released under BSD-2-Clause                    ##
#######################################################################

PL   := perl
PY   := python3
VALA := vala
FMT  := clang-format
ECHO := gecho
CP   := gcp

EGMAN    := mangledeggs
BIN2ASM  := $(PY) util/bin2asm.py
GFX2O    := $(PY) util/gfx2o.py
SCRIP2O  := $(PY) util/scrip2o.py
SNIP2O   := $(PY) util/snip2o.py
JASC2GBA := $(PY) util/jasc2gba.py

AS    := arm-none-eabi-as
CC    := arm-none-eabi-gcc
AR    := arm-none-eabi-ar
LD    := arm-none-eabi-gcc
OCPY  := arm-none-eabi-objcopy
STRIP := arm-none-eabi-strip
FIX   := gbafix
LZSS  := gbalzss

ASFLAGS := -march=armv4t -mcpu=arm7tdmi -mthumb-interwork -EL
CFLAGS  := -Wpedantic -march=armv4t -mcpu=arm7tdmi -mthumb-interwork \
	-Wno-builtin-declaration-mismatch
ARFLAGS := -rcs
LDFLAGS :=

CFLAGS.DEBUG   := -O0 -g3 -Wall
CFLAGS.RELEASE := -O3 -w
