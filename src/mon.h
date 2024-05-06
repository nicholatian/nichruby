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

#ifndef INC__MON_H
#define INC__MON_H

#include "suptypes.h"

enum
{
	MON_NICK_LEN   = 10,
	OT_NAME_LEN    = 7,
	BATTLE_STAT_CT = 8,
	PARTY_SZ       = 6
};

struct mon_substruc_a
{
	monid_t species;
	item_t item;
	u32 exp;
	u8 pp_bonus, frship;
};

struct mon_substruc_b
{
	move_t move[4];
	u8 pp[4];
};

struct mon_substruc_c
{
	u8 hp_ev, atk_ev, def_ev, spe_ev, spa_ev, spd_ev;
	u8 cool, beauty, cute, smart, tough, sheen;
};

struct mon_substruc_d
{
	u8 pkrs, met_loc;
	u16 met_lvl : 7;
	u16 met_game : 4;
	u16 ball : 4;
	u16 ot_gender : 1;

	u32 hp_iv : 5;
	u32 atk_iv : 5;
	u32 def_iv : 5;
	u32 spe_iv : 5;
	u32 spa_iv : 5;
	u32 spd_iv : 5;
	u32 is_egg : 1;
	u32 alt_abil : 1;

	u32 cool_rbn : 3;
	u32 beauty_rbn : 3;
	u32 cute_rbn : 3;
	u32 smart_rbn : 3;
	u32 tough_rbn : 3;
	u32 champ_rbn : 1;
	u32 winning_rbn : 1;
	u32 victory_rbn : 1;
	u32 artist_rbn : 1;
	u32 effort_rbn : 1;
	u32 gift1_rbn : 1;
	u32 gift2_rbn : 1;
	u32 gift3_rbn : 1;
	u32 gift4_rbn : 1;
	u32 gift5_rbn : 1;
	u32 gift6_rbn : 1;
	u32 gift7_rbn : 1;
	/* Unused in Ruby and Sapphire.
	 * NOTE: MSB must be set for Mew & Deoxys to obey in
	 * FR/LG/Emerald
	 */
	u32 fateful : 5;
};

union mon_substruc
{
	struct mon_substruc_a a;
	struct mon_substruc_b b;
	struct mon_substruc_c c;
	struct mon_substruc_d d;
	u16 raw[6];
};

struct box_mon
{
	u32 pid, otid;
	char nick[MON_NICK_LEN];
	u8 lang;
	u8 badegg : 1;
	u8 has_species : 1;
	u8 is_egg : 1;
	char ot_name[OT_NAME_LEN];
	u8 marks;
	u16 chksum, unk;
	union
	{
		u32 raw[12];
		union mon_substruc substruc[4];
	} secure;
};

struct mon
{
	struct box_mon boxed;
	u32 status;
	u8 lvl, mail;
	u16 hp, max_hp, atk, def, spe, spa, spd;
};

struct unk_mon
{
	monid_t species;
	item_t item;
	move_t move[4];
	u8 lvl, pp_bonus, hp_ev, atk_ev, def_ev, spe_ev, spa_ev, spd_ev;
	u32 otid;
	u32 hp_iv : 5;
	u32 atk_iv : 5;
	u32 spe_iv : 5;
	u32 spa_iv : 5;
	u32 spd_iv : 5;
	u32 gap : 1;
	u32 alt_abil : 1;
	u32 pid;
	char nick[MON_NICK_LEN + 1];
	u8 frship;
};

struct battle_mon
{
	monid_t species;
	u16 atk, def, spd, spa, spd;
	move_t move[4];
	u32 hp_iv : 5;
	u32 atk_iv : 5;
	u32 spe_iv : 5;
	u32 spa_iv : 5;
	u32 spd_iv : 5;
	u32 is_egg : 1;
	u32 alt_abil : 1;
	s8 stat_stages[BATTLE_STAT_CT];
	u8 abil, type1, type2, unk, pp[4];
	u16 hp;
	u8 lvl, frship;
	u16 max_hp;
	item_t item;
	char nick[MON_NICK_LEN + 1];
	u8 pp_bonus;
	char ot_name[OT_NAME_LEN + 1];
	u32 exp, pid, status1, status2, otid;
};

struct base_stats
{
	u8 base_hp, base_atk, base_def, base_spe, base_spa, base_spd;
	u8 type1, type2, catch_rate, exp_yield;
	u16 evyield_hp : 2;
	u16 evyield_atk : 2;
	u16 evyield_def : 2;
	u16 evyield_spe : 2;
	u16 evyield_spa : 2;
	u16 evyield_spd : 2;
	item_t item1, item2;
	u8 gend_ratio, egg_cycles, frship, grow_rate;
	u8 egg_grp1, egg_grp2, ability1, ability2;
	u8 safar_flee_rate;
	u8 body_col : 7;
	u8 no_flip : 1;
};

struct battle_move
{
	u8 effect, power, type, acc, pp, second_eff_odds;
	u8 target, priori, flags;
};

struct mon_storage
{
	u8 cur_box;
	struct box_mon boxed[14][30];
	char name[14][9];
	u8 wallpaper[14];
};

struct spinda_spot
{
	u8 x, y;
	u16 img[16];
};

struct __attribute__( ( packed ) ) lvlup_move
{
	u16 move : 9;
	u16 level : 7;
};

struct evolution
{
	u16 method, param, new_mon;
};

#endif /* INC__MON_H */
