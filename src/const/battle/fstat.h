/*********************************************************************\
 *    __   _ _____ _______ _     _  ______ _     _ ______ __   __    *
 *    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      *
 *    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       *
 *                             nich ruby                             *
 *                                                                   *
 *             Copyright (C) 2020-2024 Alexander Nicholi             *
 *                    Released under BSD-2-Clause                    *
\*********************************************************************/

#ifndef INC__CONST_BATTLE_FSTAT_H
#define INC__CONST_BATTLE_FSTAT_H

/* Field-side status conditions (FSTAT). These affect one party or the
 * other */

enum /* fstat */
{
	FSTAT_REFLECT       = 1 << 0,
	FSTAT_LIGHTSCREEN   = 1 << 1,
	FSTAT_4             = 1 << 2,
	FSTAT_SPIKES        = 1 << 4,
	FSTAT_SAFEG         = 1 << 5,
	FSTAT_FUTUREATK     = 1 << 6,
	FSTAT_MIST          = 1 << 8,
	FSTAT_SPIKES_DAMAGE = 1 << 9
};

#endif /* INC__CONST_BATTLE_FSTAT_H */
