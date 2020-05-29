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

#ifndef INC__CONST_BATTLE_WHICH_H
#define INC__CONST_BATTLE_WHICH_H

/*
 * A battler may be in one of four positions on the field. The first bit
 * determines what side the battler is on (either the player’s side or the
 * opponent’s side). The second bit determines what flank the battler is on
 * (either the left or right). Note that the opponent’s flanks are drawn
 * corresponding to their perspective, so their right mon appears on the left,
 * and their left mon appears on the right. The battler ID is usually the same
 * as the position, except in the case of link battles.
 *
 *   + ------------------------- +
 *   |           Opponent's side |
 *   |            Right    Left  |
 *   |              3       1    |
 *   |                           |
 *   | Player's side             |
 *   |  Left   Right             |
 *   |   0       2               |
 *   ----------------------------+
 *   |                           |
 *   |                           |
 *   +---------------------------+
 */

/* These macros can be used with either battler ID or positions to get the
 * partner or the opposite mon */
#define WHICH_BATTLER_OPPOSITE( WHICH ) ( ( WHICH ) ^ 1 )
#define WHICH_BATTLER_PARTNER( WHICH ) ( ( WHICH ) ^ 2 )

#endif /* INC__CONST_BATTLE_WHICH_H */
