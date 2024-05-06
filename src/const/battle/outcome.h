/*********************************************************************\
 *    __   _ _____ _______ _     _  ______ _     _ ______ __   __    *
 *    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      *
 *    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       *
 *                             nich ruby                             *
 *                                                                   *
 *             Copyright (C) 2020-2024 Alexander Nicholi             *
 *                    Released under BSD-2-Clause                    *
\*********************************************************************/

#ifndef INC__CONST_BATTLE_OUTCOME_H
#define INC__CONST_BATTLE_OUTCOME_H

enum /* boutcome */
{
	BOUTCOME_WIN = 1,
	BOUTCOME_LOSE,
	BOUTCOME_DRAW,
	BOUTCOME_PLAYER_FLEE,
	BOUTCOME_PLAYER_TP,
	BOUTCOME_MON_FLEE,
	BOUTCOME_CAUGHT,
	BOUTCOME_NO_SAFARI_BALLS,
	BOUTCOME_FORFEIT,
	BOUTCOME_MON_TP,
	BOUTCOME_LINK_FLEE = 128
};

#endif /* INC__CONST_BATTLE_OUTCOME_H */
