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

include etc/base.mk

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
LIBS    :=
LIBDIRS :=

# sources
SFILES    := \
	src/crt0.s \
	src/gbabios.s \
	src/memcpy.s \
	src/memset.s
CFILES    := \
	src/intr.c \
	src/main.c \
	src/savedata.c
PUBHFILES :=
PRVHFILES := \
	src/const/gba.h \
	src/const/items.h \
	src/const/maps.h \
	src/cchelp.h \
	src/gbabios.h \
	src/intr.h \
	src/memcpy.h \
	src/memset.h \
	src/map.h \
	src/mon.h \
	src/save.h \
	src/suptypes.h
#PALFILES := data/error.jasc

LDFLAGS += -T src/gba.ld -nostdlib

# this defines all our usual targets
include etc/targets.mk
