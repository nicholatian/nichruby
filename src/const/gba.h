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

#ifndef INC__NICHRUBY_CONST_GBA_H
#define INC__NICHRUBY_CONST_GBA_H

#include "ldglobls.h"

/* SBSS ("speedy BSS") is data in IWRAM */
#define SBSS __attribute__( ( section( "sbss" ) ) )
/* BSS ("block start symbol") is data in EWRAM */
#define BSS __attribute__( ( section( "bss" ) ) )
/* TEXT32 is code in IWRAM */
#define TEXT32 __attribute__( ( section( "text32" ) ) )
/* TEXT16 is code in EWRAM */
#define TEXT16 __attribute__( ( section( "text16" ) ) )

extern const ptri soundinfo_ptr;
extern const ptri irq_check;
extern const ptri irq_vector;

enum
{
	PSR_USR_MODE = 0x10,
	PSR_FIQ_MODE = 0x11,
	PSR_IRQ_MODE = 0x12,
	PSR_SVC_MODE = 0x13,
	PSR_ABT_MODE = 0x17,
	PSR_UND_MODE = 0x1B,
	PSR_SYS_MODE = 0x1F
};

enum
{
	PSR_MODE_MASK = 0x1F,
	PSR_T_BIT     = 0x20,
	PSR_F_BIT     = 0x40,
	PSR_I_BIT     = 0x80
};

enum
{
	OAM_SZ = 0x400
};

/* I/O register offsets */
enum
{
	IO_OFFS_DISPCNT = 0x0,
	IO_OFFS_DISPSTAT = 0x4,
	IO_OFFS_VCOUNT = 0x6,
	IO_OFFS_BG0CNT = 0x8,
	IO_OFFS_BG1CNT = 0xa,
	IO_OFFS_BG2CNT = 0xc,
	IO_OFFS_BG3CNT = 0xe,
	IO_OFFS_BG0HOFS = 0x10,
	IO_OFFS_BG0VOFS = 0x12,
	IO_OFFS_BG1HOFS = 0x14,
	IO_OFFS_BG1VOFS = 0x16,
	IO_OFFS_BG2HOFS = 0x18,
	IO_OFFS_BG2VOFS = 0x1a,
	IO_OFFS_BG3HOFS = 0x1c,
	IO_OFFS_BG3VOFS = 0x1e,
	IO_OFFS_BG2PA = 0x20,
	IO_OFFS_BG2PB = 0x22,
	IO_OFFS_BG2PC = 0x24,
	IO_OFFS_BG2PD = 0x26,
	IO_OFFS_BG2X_L = 0x28,
	IO_OFFS_BG2X_H = 0x2a,
	IO_OFFS_BG2Y_L = 0x2c,
	IO_OFFS_BG2Y_H = 0x2e,
	IO_OFFS_BG3PA = 0x30,
	IO_OFFS_BG3PB = 0x32,
	IO_OFFS_BG3PC = 0x34,
	IO_OFFS_BG3PD = 0x36,
	IO_OFFS_BG3X_L = 0x38,
	IO_OFFS_BG3X_H = 0x3a,
	IO_OFFS_BG3Y_L = 0x3c,
	IO_OFFS_BG3Y_H = 0x3e,
	IO_OFFS_WIN0H = 0x40,
	IO_OFFS_WIN1H = 0x42,
	IO_OFFS_WIN0V = 0x44,
	IO_OFFS_WIN1V = 0x46,
	IO_OFFS_WININ = 0x48,
	IO_OFFS_WINOUT = 0x4a,
	IO_OFFS_MOSAIC = 0x4c,
	IO_OFFS_BLDCNT = 0x50,
	IO_OFFS_BLDALPHA = 0x52,
	IO_OFFS_BLDY = 0x54,

	IO_OFFS_SOUND1CNT = 0x60,
	IO_OFFS_SOUND1CNT_L = 0x60,
	IO_OFFS_NR10 = 0x60,
	IO_OFFS_SOUND1CNT_H = 0x62,
	IO_OFFS_NR11 = 0x62,
	IO_OFFS_NR12 = 0x63,
	IO_OFFS_SOUND1CNT_X = 0x64,
	IO_OFFS_NR13 = 0x64,
	IO_OFFS_NR14 = 0x65,
	IO_OFFS_SOUND2CNT = 0x68,
	IO_OFFS_SOUND2CNT_L = 0x68,
	IO_OFFS_NR21 = 0x68,
	IO_OFFS_NR22 = 0x69,
	IO_OFFS_SOUND2CNT_H = 0x6c,
	IO_OFFS_NR23 = 0x6c,
	IO_OFFS_NR24 = 0x6d,
	IO_OFFS_SOUND3CNT = 0x70,
	IO_OFFS_SOUND3CNT_L = 0x70,
	IO_OFFS_NR30 = 0x70,
	IO_OFFS_SOUND3CNT_H = 0x72,
	IO_OFFS_NR31 = 0x72,
	IO_OFFS_NR32 = 0x73,
	IO_OFFS_SOUND3CNT_X = 0x74,
	IO_OFFS_NR33 = 0x74,
	IO_OFFS_NR34 = 0x75,
	IO_OFFS_SOUND4CNT = 0x78,
	IO_OFFS_SOUND4CNT_L = 0x78,
	IO_OFFS_NR41 = 0x78,
	IO_OFFS_NR42 = 0x79,
	IO_OFFS_SOUND4CNT_H = 0x7c,
	IO_OFFS_NR43 = 0x7c,
	IO_OFFS_NR44 = 0x7d,
	IO_OFFS_SOUNDCNT = 0x80,
	IO_OFFS_SOUNDCNT_L = 0x80,
	IO_OFFS_NR50 = 0x80,
	IO_OFFS_NR51 = 0x81,
	IO_OFFS_SOUNDCNT_H = 0x82,
	IO_OFFS_SOUNDCNT_X = 0x84,
	IO_OFFS_NR52 = 0x84,
	IO_OFFS_SOUNDBIAS = 0x88,
	IO_OFFS_WAVE_RAM = 0x90,
	IO_OFFS_WAVE_RAM0 = 0x90,
	IO_OFFS_WAVE_RAM0_L = 0x90,
	IO_OFFS_WAVE_RAM0_H = 0x92,
	IO_OFFS_WAVE_RAM1 = 0x94,
	IO_OFFS_WAVE_RAM1_L = 0x94,
	IO_OFFS_WAVE_RAM1_H = 0x96,
	IO_OFFS_WAVE_RAM2 = 0x98,
	IO_OFFS_WAVE_RAM2_L = 0x98,
	IO_OFFS_WAVE_RAM2_H = 0x9a,
	IO_OFFS_WAVE_RAM3 = 0x9c,
	IO_OFFS_WAVE_RAM3_L = 0x9c,
	IO_OFFS_WAVE_RAM3_H = 0x9e,
	IO_OFFS_FIFO = 0xa0,
	IO_OFFS_FIFO_A = 0xa0,
	IO_OFFS_FIFO_A_L = 0xa0,
	IO_OFFS_FIFO_A_H = 0xa2,
	IO_OFFS_FIFO_B = 0xa4,
	IO_OFFS_FIFO_B_L = 0xa4,
	IO_OFFS_FIFO_B_H = 0xa6,

	IO_OFFS_DMA0 = 0xb0,
	IO_OFFS_DMA0SAD = 0xb0,
	IO_OFFS_DMA0SAD_L = 0xb0,
	IO_OFFS_DMA0SAD_H = 0xb2,
	IO_OFFS_DMA0DAD = 0xb4,
	IO_OFFS_DMA0DAD_L = 0xb4,
	IO_OFFS_DMA0DAD_H = 0xb6,
	IO_OFFS_DMA0CNT = 0xb8,
	IO_OFFS_DMA0CNT_L = 0xb8,
	IO_OFFS_DMA0CNT_H = 0xba,
	IO_OFFS_DMA1 = 0xbc,
	IO_OFFS_DMA1SAD = 0xbc,
	IO_OFFS_DMA1SAD_L = 0xbc,
	IO_OFFS_DMA1SAD_H = 0xbe,
	IO_OFFS_DMA1DAD = 0xc0,
	IO_OFFS_DMA1DAD_L = 0xc0,
	IO_OFFS_DMA1DAD_H = 0xc2,
	IO_OFFS_DMA1CNT = 0xc4,
	IO_OFFS_DMA1CNT_L = 0xc4,
	IO_OFFS_DMA1CNT_H = 0xc6,
	IO_OFFS_DMA2 = 0xc8,
	IO_OFFS_DMA2SAD = 0xc8,
	IO_OFFS_DMA2SAD_L = 0xc8,
	IO_OFFS_DMA2SAD_H = 0xca,
	IO_OFFS_DMA2DAD = 0xcc,
	IO_OFFS_DMA2DAD_L = 0xcc,
	IO_OFFS_DMA2DAD_H = 0xce,
	IO_OFFS_DMA2CNT = 0xd0,
	IO_OFFS_DMA2CNT_L = 0xd0,
	IO_OFFS_DMA2CNT_H = 0xd2,
	IO_OFFS_DMA3 = 0xd4,
	IO_OFFS_DMA3SAD = 0xd4,
	IO_OFFS_DMA3SAD_L = 0xd4,
	IO_OFFS_DMA3SAD_H = 0xd6,
	IO_OFFS_DMA3DAD = 0xd8,
	IO_OFFS_DMA3DAD_L = 0xd8,
	IO_OFFS_DMA3DAD_H = 0xda,
	IO_OFFS_DMA3CNT = 0xdc,
	IO_OFFS_DMA3CNT_L = 0xdc,
	IO_OFFS_DMA3CNT_H = 0xde,

	IO_OFFS_TM0CNT = 0x100,
	IO_OFFS_TM0CNT_L = 0x100,
	IO_OFFS_TM0CNT_H = 0x102,
	IO_OFFS_TM1CNT = 0x104,
	IO_OFFS_TM1CNT_L = 0x104,
	IO_OFFS_TM1CNT_H = 0x106,
	IO_OFFS_TM2CNT = 0x108,
	IO_OFFS_TM2CNT_L = 0x108,
	IO_OFFS_TM2CNT_H = 0x10a,
	IO_OFFS_TM3CNT = 0x10c,
	IO_OFFS_TM3CNT_L = 0x10c,
	IO_OFFS_TM3CNT_H = 0x10e,

	IO_OFFS_SIOCNT = 0x128,
	IO_OFFS_SIODATA8 = 0x12a,
	IO_OFFS_SIODATA32 = 0x120,
	IO_OFFS_SIOMLT_SEND = 0x12a,
	IO_OFFS_SIOMLT_RECV = 0x120,
	IO_OFFS_SIOMULTI0 = 0x120,
	IO_OFFS_SIOMULTI1 = 0x122,
	IO_OFFS_SIOMULTI2 = 0x124,
	IO_OFFS_SIOMULTI3 = 0x126,

	IO_OFFS_KEYINPUT = 0x130,
	IO_OFFS_KEYCNT = 0x132,

	IO_OFFS_RCNT = 0x134,

	IO_OFFS_JOYCNT = 0x140,
	IO_OFFS_JOYSTAT = 0x158,
	IO_OFFS_JOY_RECV = 0x150,
	IO_OFFS_JOY_RECV_L = 0x150,
	IO_OFFS_JOY_RECV_H = 0x152,
	IO_OFFS_JOY_TRANS = 0x154,
	IO_OFFS_JOY_TRANS_L = 0x154,
	IO_OFFS_JOY_TRANS_H = 0x156,

	IO_OFFS_IME = 0x208,
	IO_OFFS_IE = 0x200,
	IO_OFFS_IF = 0x202,

	IO_OFFS_WAITCNT = 0x204
};

/* input keys */
enum
{
	KEY_A = 0,
	KEY_B,
	KEY_START,
	KEY_SEL,
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_L,
	KEY_R,
	MAX_KEY
};

/* bitmasks for keys */
enum
{
	KEYMASK_A     = 1 << KEY_A,
	KEYMASK_B     = 1 << KEY_B,
	KEYMASK_START = 1 << KEY_START,
	KEYMASK_SEL   = 1 << KEY_SEL,
	KEYMASK_UP    = 1 << KEY_UP,
	KEYMASK_DOWN  = 1 << KEY_DOWN,
	KEYMASK_LEFT  = 1 << KEY_LEFT,
	KEYMASK_RIGHT = 1 << KEY_RIGHT,
	KEYMASK_L     = 1 << KEY_L,
	KEYMASK_R     = 1 << KEY_R
};

#endif /* INC__NICHRUBY_CONST_GBA_H */
