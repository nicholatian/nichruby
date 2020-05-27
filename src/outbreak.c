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

#include "const/maps.h"
#include "const/moves.h"
#include "const/species.h"
#include "map.h"
#include "types.h"

struct outbreak_mon
{
	pkmnid_t species;
	move_t move[4];
	u8 level;
	mapid_t loc;
};

enum
{
	OUTBREAK_CT = 5
};

static const struct outbreak_mon outbreaks[OUTBREAK_CT] = {
	{
		SPECIES_SURSKIT,
		{
			MOVE_BUBBLE, MOVE_QUICK_ATTACK, MOVE_NONE, MOVE_NONE
		},
		3,
		MAP_ROUTE102
	}, {
		SPECIES_SURSKIT,
		{
			MOVE_BUBBLE, MOVE_QUICK_ATTACK, MOVE_NONE, MOVE_NONE
		},
		15,
		MAP_ROUTE114
	}, {
		SPECIES_SURSKIT,
		{
			MOVE_BUBBLE, MOVE_QUICK_ATTACK, MOVE_NONE, MOVE_NONE
		},
		15,
		MAP_ROUTE117
	}, {
		SPECIES_SURSKIT,
		{
			MOVE_BUBBLE, MOVE_QUICK_ATTACK, MOVE_NONE, MOVE_NONE
		},
		28,
		MAP_ROUTE120
	}, {
		SPECIES_SKITTY,
		{
			MOVE_TACKLE, MOVE_GROWL, MOVE_NONE, MOVE_NONE
		},
		15,
		MAP_ROUTE116
	}
};
