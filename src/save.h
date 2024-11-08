/*********************************************************************\
 *    __   _ _____ _______ _     _  ______ _     _ ______ __   __    *
 *    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      *
 *    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       *
 *                             nich ruby                             *
 *                                                                   *
 *             Copyright (C) 2020-2024 Alexander Nicholi             *
 *                    Released under BSD-2-Clause                    *
\*********************************************************************/

/* DEFINITION MODULE */

#ifndef INC__NICHRUBY_SAVEDATA_H
#define INC__NICHRUBY_SAVEDATA_H

#include "map.h"
#include "suptypes.h"
#include "const/types/vec.h"

struct savblk1
{
	s16v2 pos;
	struct warp loc, warp1, warp2, last_heal, warp4;
	song_t music;
	u8 weather, weather_stage, flash_lvl;
	u16 map_layout, map_view[0x100];
	u8 party_ct;
};

#endif /* INC__NICHRUBY_SAVEDATA_H */
