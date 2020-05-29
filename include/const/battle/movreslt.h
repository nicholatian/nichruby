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

#ifndef INC__CONST_BATTLE_MOVERESLT_H
#define INC__CONST_BATTLE_MOVERESLT_H

enum /* move_result */
{
	MOVRESLT_MISSED      = 1 << 0,
	MOVRESLT_SUPEREFF    = 1 << 1,
	MOVRESLT_NOTVERYEFF  = 1 << 2,
	MOVRESLT_NOTAFFECTED = 1 << 3,
	MOVRESLT_1HKO        = 1 << 4,
	MOVRESLT_FAILED      = 1 << 5,
	MOVRESLT_FOE_ENDURED = 1 << 6,
	MOVRESLT_FOE_HUNGON  = 1 << 7,
	MOVRESLT_NOEFFECT =
	   MOVRESLT_MISSED | MOVRESLT_NOTAFFECTED | MOVRESLT_FAILED
};

#endif /* INC__CONST_BATTLE_MOVERESLT_H */
