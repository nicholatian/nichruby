#!/usr/bin/env make
#######################################################################
##    __   _ _____ _______ _     _  ______ _     _ ______ __   __    ##
##    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      ##
##    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       ##
##                             nich ruby                             ##
##                                                                   ##
##             Copyright (C) 2020-2024 Alexander Nicholi             ##
##                    Released under BSD-2-Clause                    ##
#######################################################################

# No other platform supported
TP := GBA

include $(AQ)/lib/slick/base.mk

# name of project. used in output binary naming
PROJECT := nichruby

# put a ‘1’ for the desired target types to compile
EXEFILE := 1
SOFILE  :=
AFILE   :=

# space-separated path list for #includes
# <system> includes
INCLUDES :=
# "local" includes
INCLUDEL := src

# space-separated library name list
LIBS    := uni_himem uni_err
LIBDIRS :=

# ‘3P’ are in-tree 3rd-party dependencies
# 3PLIBDIR is the base directory
# 3PLIBS is the folder names in the base directory for each library
3PLIBDIR := 3rdparty
3PLIBS   :=

# frameworks (macOS target only)
FWORKS :=

# sources
SFILES    := \
	src/crt0.s
CFILES    := \
	src/intr.c \
	src/main.c \
	src/outbreak.c \
	src/savedata.c \
	src/tv.c
CPPFILES  :=
PUBHFILES :=
PRVHFILES := \
	src/const/gba.h \
	src/const/battle/abilfx.h \
	src/const/battle/aiaction.h \
	src/const/battle/anim.h \
	src/const/battle/effect.h \
	src/const/battle/flag.h \
	src/const/battle/fstat.h \
	src/const/battle/hitmark.h \
	src/const/battle/misc.h \
	src/const/battle/movefx.h \
	src/const/battle/movreslt.h \
	src/const/battle/nvstat.h \
	src/const/battle/outcome.h \
	src/const/battle/target.h \
	src/const/battle/terrain.h \
	src/const/battle/type.h \
	src/const/battle/vstat.h \
	src/const/battle/weather.h \
	src/const/battle/which.h \
	src/const/battle/xstat.h \
	src/const/mon/ability.h \
	src/const/mon/bodycol.h \
	src/const/mon/data.h \
	src/const/mon/egggroup.h \
	src/const/mon/evo.h \
	src/const/mon/frshipev.h \
	src/const/mon/growth.h \
	src/const/mon/misc.h \
	src/const/mon/moves.h \
	src/const/mon/nature.h \
	src/const/mon/pstatus.h \
	src/const/mon/species.h \
	src/const/mon/stat.h \
	src/const/mon/type.h \
	src/const/maps.h \
	src/const/types.h \
	src/map.h \
	src/mon.h \
	src/save.h
PALFILES := data/error.jasc

# test suite sources
TES_CFILES    :=
TES_CPPFILES  :=
TES_PUBHFILES :=
TES_PRVHFILES :=

LDFLAGS := -T src/gba.ld -nostdlib

# this defines all our usual targets
include $(AQ)/lib/slick/targets.mk
