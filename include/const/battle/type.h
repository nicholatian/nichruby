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

#ifndef INC__CONST_BATTLE_TYPE_H
#define INC__CONST_BATTLE_TYPE_H

enum /* btype */
{
	BTYPE_DOUBLE      = 1 << 0,
	BTYPE_LINK        = 1 << 1,
	BTYPE_WILD        = 1 << 2,
	BTYPE_TRAINER     = 1 << 3,
	BTYPE_FIRSTBATTLE = 1 << 4,
	BTYPE_20          = 1 << 5,
	BTYPE_MULTI       = 1 << 6,
	BTYPE_SAFARI      = 1 << 7,
	BTYPE_BATTLETOWER = 1 << 8,
	BTYPE_WALLY       = 1 << 9,
	BTYPE_ROAMER      = 1 << 10,
	BTYPE_EREADER     = 1 << 11,
	BTYPE_KYOGROUD    = 1 << 12,
	BTYPE_LEGENDARY   = 1 << 13,
	BTYPE_REGI        = 1 << 14,
	BTYPE_LINK_DOUBLE = BTYPE_DOUBLE | BTYPE_LINK |
	   BTYPE_TRAINER | BTYPE_MULTI,
};

#endif /* INC__CONST_BATTLE_TYPE_H */
