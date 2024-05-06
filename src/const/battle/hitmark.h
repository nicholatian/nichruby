/*********************************************************************\
 *    __   _ _____ _______ _     _  ______ _     _ ______ __   __    *
 *    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      *
 *    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       *
 *                             nich ruby                             *
 *                                                                   *
 *             Copyright (C) 2020-2024 Alexander Nicholi             *
 *                    Released under BSD-2-Clause                    *
\*********************************************************************/

#ifndef INC__CONST_BATTLE_HITMARK_H
#define INC__CONST_BATTLE_HITMARK_H

/* Hitmarker conditions (not sure what these are?) */

enum /* hitmark */
{
	HITMARK_10              = 1 << 4,
	HITMARK_20              = 1 << 5,
	HITMARK_DESTINYBOND     = 1 << 6,
	HITMARK_NOANIM          = 1 << 7,
	HITMARK_IGNORE_SUBST    = 1 << 8,
	HITMARK_NOATKSTR        = 1 << 9,
	HITMARK_ATKSTR_PRINT    = 1 << 10,
	HITMARK_NO_PP_DEDUCT    = 1 << 11,
	HITMARK_SWAP_ATK_TARGET = 1 << 12,
	HITMARK_IGNORE_SAFEG    = 1 << 13,
	HITMARK_SYNC_EFFECT     = 1 << 14,
	HITMARK_RUN             = 1 << 15,
	HITMARK_IGNORE_ONAIR    = 1 << 16,
	HITMARK_IGNORE_UNDGND   = 1 << 17,
	HITMARK_IGNORE_UNDWTR   = 1 << 18,
	HITMARK_MOVE_DISABLED   = 1 << 19,
	HITMARK_100000          = 1 << 20,
	HITMARK_200000          = 1 << 21,
	HITMARK_400000          = 1 << 22,
	HITMARK_800000          = 1 << 23,
	HITMARK_GRUDGE          = 1 << 24,
	HITMARK_OBEYS           = 1 << 25,
	HITMARK_4000000         = 1 << 26,
	HITMARK_CHARGING        = 1 << 27
};

#endif /* INC__CONST_BATTLE_HITMARK_H */
