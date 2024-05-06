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

#ifndef INC__MAP_H
#define INC__MAP_H

#include "suptypes.h"
#include <uni/types/vec.h>

typedef u16 mapid_t;

struct warp
{
	mapid_t map;
	u8 warp;
	s16v2 pos;
};

#endif /* INC__MAP_H */
