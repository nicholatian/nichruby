/*********************************************************************\
 *    __   _ _____ _______ _     _  ______ _     _ ______ __   __    *
 *    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      *
 *    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       *
 *                             nich ruby                             *
 *                                                                   *
 *             Copyright (C) 2020-2024 Alexander Nicholi             *
 *                    Released under BSD-2-Clause                    *
\*********************************************************************/

#ifndef INC__CONST_BATTLE_FLAG_H
#define INC__CONST_BATTLE_FLAG_H

enum /* bflag */
{
	BFLAG_MAKES_CONTACT      = 1 << 0,
	BFLAG_AFFECTBY_PROTECT   = 1 << 1,
	BFLAG_AFFECTBY_MAGICCOAT = 1 << 2,
	BFLAG_AFFECTBY_SNATCH    = 1 << 3,
	BFLAG_MIRRORMOVE_COMPAT  = 1 << 4,
	BFLAG_AFFECTBY_KINGSROCK = 1 << 5
};

#endif /* INC__CONST_BATTLE_FLAG_H */
