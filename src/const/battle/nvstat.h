/*********************************************************************\
 *    __   _ _____ _______ _     _  ______ _     _ ______ __   __    *
 *    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      *
 *    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       *
 *                             nich ruby                             *
 *                                                                   *
 *             Copyright (C) 2020-2024 Alexander Nicholi             *
 *                    Released under BSD-2-Clause                    *
\*********************************************************************/

#ifndef INC__CONST_BATTLE_NVSTAT_H
#define INC__CONST_BATTLE_NVSTAT_H

/* Non-volatile status conditions (NVSTAT)
 * These persist outside of battle and after switching out */

enum /* nvstat */
{
	NVSTAT_NONE,
	NVSTAT_SLP         = 0x7,
	NVSTAT_PSN         = 0x8,
	NVSTAT_BRN         = 0x10,
	NVSTAT_FRZ         = 0x20,
	NVSTAT_PAR         = 0x40,
	NVSTAT_TOX         = 0x80,
	NVSTAT_TOX_COUNTER = 0xF00,
	NVSTAT_ANY_PSN     = NVSTAT_PSN | NVSTAT_TOX,
	NVSTAT_ANY = NVSTAT_SLP | NVSTAT_PSN | NVSTAT_BRN | NVSTAT_FRZ |
		NVSTAT_PAR | NVSTAT_TOX
};

#endif /* INC__CONST_BATTLE_NVSTAT_H */
