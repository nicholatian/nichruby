/* -*- coding: utf-8 -*- */
/****************************************************************************\
 *       __   _ _____ _______ _     _  ______ _     _ ______  __   __       *
 *       | \  |   |   |       |_____| |_____/ |     | |_____]   \_/         *
 *       |  \_| __|__ |_____  |     | |    \_ |_____| |_____]    |          *
 *                                 nichruby                                 *
 *                                                                          *
 *                    Copyright © 2020 Alexander Nicholi                    *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#include "types.h"

struct outbreak_mon
{
	pkmnid_t species;
	move_t move[4];
	u8 level;
	loc_t loc;
};

enum
{
	OUTBREAK_CT = 5
};

static const struct outbreak_mon outbreaks[OUTBREAK_CT] = {};
