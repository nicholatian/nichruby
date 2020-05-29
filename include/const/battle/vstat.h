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

#ifndef INC__CONST_BATTLE_VSTAT_H
#define INC__CONST_BATTLE_VSTAT_H

/* Volatile status conditions (VSTAT)
 * These do not persist outside of battle or after switching out */

enum /* vstat */
{
	VSTAT_CONFUSED      = 7,
	VSTAT_FLINCH        = 1 << 3,
	VSTAT_UPROAR        = 0x70,
	VSTAT_BIDE          = ( 1 << 8 ) | ( 1 << 9 ),
	VSTAT_LOCK_CONFUSE  = ( 1 << 10 ) | ( 1 << 11 ),
	VSTAT_MULTIPLETURNS = 1 << 12,
	VSTAT_WRAPPED       = ( 1 << 13 ) | ( 1 << 14 ) | ( 1 << 15 ),
	/* NOTE: 4 bits, one for each battler */
	VSTAT_INFATUATION =
	   ( 1 << 16 ) | ( 1 << 17 ) | ( 1 << 18 ) | ( 1 << 19 ),
	VSTAT_PUMPED      = 1 << 20,
	VSTAT_TRANSFORMED = 1 << 21,
	VSTAT_RECHARGE    = 1 << 22,
	VSTAT_RAGE        = 1 << 23,
	VSTAT_SUBST       = 1 << 24,
	VSTAT_DESTINYBOND = 1 << 25,
	VSTAT_NOESCAPE    = 1 << 26,
	VSTAT_NGHTMRE     = 1 << 27,
	VSTAT_CURSED      = 1 << 28,
	VSTAT_FORESIGHT   = 1 << 29,
	VSTAT_DEFCURL     = 1 << 30,
	VSTAT_TORMENTED   = 1 << 31
};

#endif /* INC__CONST_BATTLE_VSTAT_H */
