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

/* DEFINITION MODULE */

#ifndef INC__SAVEDATA_H
#define INC__SAVEDATA_H

#include "map.h"
#include "suptypes.h"
#include <uni/types/vec.h>

struct savblk1
{
	s16v2 pos;
	struct warp loc, warp1, warp2, last_heal, warp4;
	song_t music;
	u8 weather, weather_stage, flash_lvl;
	u16 map_layout, map_view[0x100];
	u8 party_ct;
};

#endif /* INC__SAVEDATA_H */
