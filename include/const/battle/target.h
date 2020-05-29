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

#ifndef INC__CONST_BATTLE_TARGET_H
#define INC__CONST_BATTLE_TARGET_H

enum /* target */
{
	TARGET_SELECT_MON   = 0,
	TARGET_SPECIAL      = 1 << 0,
	TARGET_UNK2         = 1 << 1,
	TARGET_RANDOM       = 1 << 2,
	TARGET_BOTH_ENEMIES = 1 << 3,
	TARGET_USER         = 1 << 4,
	TARGET_ALL_BUT_USER = 1 << 5,
	TARGET_ENEMY_SIDE   = 1 << 6
};

#endif /* INC__CONST_BATTLE_TARGET_H */
