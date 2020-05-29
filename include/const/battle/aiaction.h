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

#ifndef INC__CONST_BATTLE_AIACTION_H
#define INC__CONST_BATTLE_AIACTION_H

enum /* aiaction */
{
	AIACTION_DONE = 1 << 0,
	AIACTION_FLEE = 1 << 1,
	AIACTION_WATCH = 1 << 2,
	AIACTION_DONOTATK = 1 << 3,
	AIACTION_UNK5 = 1 << 4,
	AIACTION_UNK6 = 1 << 5,
	AIACTION_UNK7 = 1 << 6,
	AIACTION_UNK8 = 1 << 7
};

#endif /* INC__CONST_BATTLE_AIACTION_H */
