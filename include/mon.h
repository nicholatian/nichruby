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

#ifndef INC__MON_H
#define INC__MON_H

#include "types.h"

enum
{
	MON_NICK_LEN = 10,
	OT_NAME_LEN = 7,
	BATTLE_STAT_CT = 8
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
};

struct mon
{
	struct box_mon boxed;
	u32 status;
	u8 lvl, mail;
	u16 hp, max_hp, atk, def, speed, spatk, spdef;
};

struct unk_mon
{
	u16 species, item;
	move_t move[4];
	u8 lvl, pp_bonuses, hp_ev, atk_ev, def_ev, speed_ev, spatk_ev, spdef_ev;
	u32 otid;
	u32 hp_iv : 5;
	u32 atk_iv : 5;
	u32 speed_iv : 5;
	u32 spatk_iv : 5;
	u32 spdef_iv : 5;
	u32 gap : 1;
	u32 alt_abil : 1;
	u32 pid;
	char nick[MON_NICK_LEN + 1];
	u8 friendship;
};

struct battle_mon
{
	u16 species, atk, def, speed, spatk, spdef;
	move_t move[4];
	u32 hp_iv : 5;
	u32 atk_iv : 5;
	u32 speed_iv : 5;
	u32 spatk_iv : 5;
	u32 spdef_iv : 5;
	u32 is_egg : 1;
	u32 alt_abil : 1;
	s8 stat_stages[BATTLE_STAT_CT];
	u8 abil, type1, type2, unk, pp[4];
	u16 hp;
	u8 lvl, friendship;
	u16 max_hp, item;
	char nick[MON_NICK_LEN + 1];
	u8 pp_bonuses;
	char ot_name[OT_NAME_LEN + 1];
	u32 exp, pid, status1, status2, otid;
};

#endif /* INC__MON_H */
