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

#ifndef INC__CONST_MON_EVO_H
#define INC__CONST_MON_EVO_H

/* evolution methods */

enum /* evo */
{
	EVO_FRSHIP = 1,
	EVO_FRSHIP_DAY,
	EVO_FRSHIP_NITE,
	EVO_LVLUP,
	EVO_TRADE,
	EVO_TRADEITEM,
	EVO_ITEM,
	EVO_ATK_GT_DEF,
	EVO_ATK_EQ_DEF,
	EVO_ATK_LT_DEF,
	EVO_LVLUP_SILC,
	EVO_LVLUP_CASC,
	EVO_LVLUP_NINJ,
	EVO_LVLUP_SHED,
	EVO_LVLUP_BEAUTY,
	MAX_EVO
};

#endif /* INC__CONST_MON_EVO_H */
