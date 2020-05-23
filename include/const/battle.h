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

#ifndef INC__CONST_BATTLE_H
#define INC__CONST_BATTLE_H

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

enum
{
	MAX_BATTLERS_COUNT = 4
};

enum /* battle_type */
{
	BATTLE_TYPE_DOUBLE      = 1 << 0,
	BATTLE_TYPE_LINK        = 1 << 1,
	BATTLE_TYPE_WILD        = 1 << 2,
	BATTLE_TYPE_TRAINER     = 1 << 3,
	BATTLE_TYPE_FIRSTBATTLE = 1 << 4,
	BATTLE_TYPE_20          = 1 << 5,
	BATTLE_TYPE_MULTI       = 1 << 6,
	BATTLE_TYPE_SAFARI      = 1 << 7,
	BATTLE_TYPE_BATTLETOWER = 1 << 8,
	BATTLE_TYPE_WALLY       = 1 << 9,
	BATTLE_TYPE_ROAMER      = 1 << 10,
	BATTLE_TYPE_EREADER     = 1 << 11,
	BATTLE_TYPE_KYOGROUD    = 1 << 12,
	BATTLE_TYPE_LEGENDARY   = 1 << 13,
	BATTLE_TYPE_REGI        = 1 << 14,
	BATTLE_TYPE_LINK_DOUBLE = BATTLE_TYPE_DOUBLE | BATTLE_TYPE_LINK |
	   BATTLE_TYPE_TRAINER | BATTLE_TYPE_MULTI,
};

enum
{
	SECRET_BASE_OPPONENT = 1 << 10,
	LINK_BATTLE_OPPONENT = 1 << 11
};

enum /* battle_outcome */
{
	BATTLE_OUTCOME_WIN = 1,
	BATTLE_OUTCOME_LOSE,
	BATTLE_OUTCOME_DRAW,
	BATTLE_OUTCOME_PLAYER_FLEE,
	BATTLE_OUTCOME_PLAYER_TP,
	BATTLE_OUTCOME_MON_FLEE,
	BATTLE_OUTCOME_CAUGHT,
	BATTLE_OUTCOME_NO_SAFARI_BALLS,
	BATTLE_OUTCOME_FORFEIT,
	BATTLE_OUTCOME_MON_TP,
	BATTLE_OUTCOME_LINK_FLEE = 128
};

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

/* Volatile status conditions (VSTAT)
 * These do not persist outside of battle or after switching out */
enum /* vstat */
{
	VSTAT_CONFUSED      = 7,
	VSTAT_FLINCH        = 1 << 3,
	VSTAT_UPROAR        = 0x70,
	VSTAT_BIDE          = ( 1 << 8 ) | ( 1 << 9 ),
	VSTAT_LOCK_CONFUSE  = ( 1 << 10 ) | ( 1 << 11 ),
	VSTAT_MULTIPLETURNS = 1 << 12,
	VSTAT_WRAPPED       = ( 1 << 13 ) | ( 1 << 14 ) | ( 1 << 15 ),
	/* NOTE: 4 bits, one for each battler */
	VSTAT_INFATUATION =
	   ( 1 << 16 ) | ( 1 << 17 ) | ( 1 << 18 ) | ( 1 << 19 ),
	VSTAT_PUMPED      = 1 << 20,
	VSTAT_TRANSFORMED = 1 << 21,
	VSTAT_RECHARGE    = 1 << 22,
	VSTAT_RAGE        = 1 << 23,
	VSTAT_SUBST       = 1 << 24,
	VSTAT_DESTINYBOND = 1 << 25,
	VSTAT_NOESCAPE    = 1 << 26,
	VSTAT_NGHTMRE     = 1 << 27,
	VSTAT_CURSED      = 1 << 28,
	VSTAT_FORESIGHT   = 1 << 29,
	VSTAT_DEFCURL     = 1 << 30,
	VSTAT_TORMENTED   = 1 << 31
};

/* Special status conditions (XSTAT) */
enum /* xstat */
{
	XSTAT_LEECHSEED_BATTLER = ( 1 << 0 ) | ( 1 << 1 ),
	XSTAT_LEECHSEED         = 1 << 2,
	XSTAT_ALWAYSHITS        = ( 1 << 3 ) | ( 1 << 4 ),
	XSTAT_PERISH_SONG       = 1 << 5,
	XSTAT_ONAIR             = 1 << 6,
	XSTAT_UNDERGROUND       = 1 << 7,
	XSTAT_MINIMIZED         = 1 << 8,
	XSTAT_CHARGED           = 1 << 9,
	XSTAT_ROOTED            = 1 << 10,
	XSTAT_YAWN              = ( 1 << 11 ) | ( 1 << 12 ),
	XSTAT_IMPRISONED_OTHERS = 1 << 13,
	XSTAT_GRUDGE            = 1 << 14,
	XSTAT_NOCRIT            = 1 << 15,
	XSTAT_MUDSPORT          = 1 << 16,
	XSTAT_WATERSPORT        = 1 << 17,
	XSTAT_UNDERWATER        = 1 << 18,
	XSTAT_INTIMIDATE        = 1 << 19,
	XSTAT_TRACE             = 1 << 20,
	XSTAT_SEMI_INVULN = XSTAT_ONAIR | XSTAT_UNDERGROUND | XSTAT_UNDERWATER
};

/* Hitmarker conditions (?) */
enum /* hmark */
{
	HMARK_10                 = 1 << 4,
	HMARK_20                 = 1 << 5,
	HMARK_DESTINYBOND        = 1 << 6,
	HMARK_NOANIM             = 1 << 7,
	HMARK_IGNORE_SUBST       = 1 << 8,
	HMARK_NOATKSTR           = 1 << 9,
	HMARK_ATKSTR_PRINT       = 1 << 10,
	HMARK_NO_PP_DEDUCT       = 1 << 11,
	HMARK_SWAP_ATK_TARGET    = 1 << 12,
	HMARK_IGNORE_SAFEG       = 1 << 13,
	HMARK_SYNC_EFFECT        = 1 << 14,
	HMARK_RUN                = 1 << 15,
	HMARK_IGNORE_ONAIR       = 1 << 16,
	HMARK_IGNORE_UNDERGROUND = 1 << 17,
	HMARK_IGNORE_UNDERWATER  = 1 << 18,
	HMARK_MOVE_DISABLED      = 1 << 19,
	HMARK_100000             = 1 << 20,
	HMARK_200000             = 1 << 21,
	HMARK_400000             = 1 << 22,
	HMARK_800000             = 1 << 23,
	HMARK_GRUDGE             = 1 << 24,
	HMARK_OBEYS              = 1 << 25,
	HMARK_4000000            = 1 << 26,
	HMARK_CHARGING           = 1 << 27
};

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

#endif /* INC__CONST_BATTLE_H */
