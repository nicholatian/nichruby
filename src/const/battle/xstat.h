/*********************************************************************\
 *    __   _ _____ _______ _     _  ______ _     _ ______ __   __    *
 *    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      *
 *    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       *
 *                             nich ruby                             *
 *                                                                   *
 *             Copyright (C) 2020-2024 Alexander Nicholi             *
 *                    Released under BSD-2-Clause                    *
\*********************************************************************/

#ifndef INC__CONST_BATTLE_XSTAT_H
#define INC__CONST_BATTLE_XSTAT_H

/* Special status conditions (XSTAT) */

enum /* xstat */
{
	XSTAT_LEECHSEED_BATTLER = ( 1 << 0 ) | ( 1 << 1 ),
	XSTAT_LEECHSEED         = 1 << 2,
	XSTAT_ALWAYSHITS        = ( 1 << 3 ) | ( 1 << 4 ),
	XSTAT_PERISH_SONG       = 1 << 5,
	XSTAT_ONAIR             = 1 << 6,
	XSTAT_UNDERGROUND       = 1 << 7,
	XSTAT_MINIMIZED         = 1 << 8,
	XSTAT_CHARGED           = 1 << 9,
	XSTAT_ROOTED            = 1 << 10,
	XSTAT_YAWN              = ( 1 << 11 ) | ( 1 << 12 ),
	XSTAT_IMPRISONED_OTHERS = 1 << 13,
	XSTAT_GRUDGE            = 1 << 14,
	XSTAT_NOCRIT            = 1 << 15,
	XSTAT_MUDSPORT          = 1 << 16,
	XSTAT_WATERSPORT        = 1 << 17,
	XSTAT_UNDERWATER        = 1 << 18,
	XSTAT_INTIMIDATE        = 1 << 19,
	XSTAT_TRACE             = 1 << 20,
	XSTAT_SEMI_INVULN =
		XSTAT_ONAIR | XSTAT_UNDERGROUND | XSTAT_UNDERWATER
};

#endif /* INC__CONST_BATTLE_XSTAT_H */
