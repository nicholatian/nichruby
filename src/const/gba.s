@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@    __   _ _____ _______ _     _  ______ _     _ ______ __   __    @@
@@    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      @@
@@    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       @@
@@                             nich ruby                             @@
@@                                                                   @@
@@             Copyright (C) 2020-2024 Alexander Nicholi             @@
@@                    Released under BSD-2-Clause                    @@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

@ DEFINITION MODULE

.ifndef INC__NICHRUBY_CONST_GBA_S
.equiv INC__NICHRUBY_CONST_GBA_S, 1

.include "const/ldglobls.s"

.equiv soundinfo_ptr, ld_iwram_end - 16
.equiv irq_check, ld_iwram_end - 8
.equiv irq_vector, ld_iwram_end - 4

.equiv PSR_USR_MODE, 0x00000010
.equiv PSR_FIQ_MODE, 0x00000011
.equiv PSR_IRQ_MODE, 0x00000012
.equiv PSR_SVC_MODE, 0x00000013
.equiv PSR_ABT_MODE, 0x00000017
.equiv PSR_UND_MODE, 0x0000001B
.equiv PSR_SYS_MODE, 0x0000001F
.equiv PSR_MODE_MASK, 0x0000001F
.equiv PSR_T_BIT, 0x00000020
.equiv PSR_F_BIT, 0x00000040
.equiv PSR_I_BIT, 0x00000080

.equiv IRQ_MASK_VBLANK, 1 << 0
.equiv IRQ_MASK_HBLANK, 1 << 1
.equiv IRQ_MASK_VCOUNT, 1 << 2
.equiv IRQ_MASK_TIMER0, 1 << 3
.equiv IRQ_MASK_TIMER1, 1 << 4
.equiv IRQ_MASK_TIMER2, 1 << 5
.equiv IRQ_MASK_TIMER3, 1 << 6
.equiv IRQ_MASK_SERIAL, 1 << 7
.equiv IRQ_MASK_DMA0, 1 << 8
.equiv IRQ_MASK_DMA1, 1 << 9
.equiv IRQ_MASK_DMA2, 1 << 10
.equiv IRQ_MASK_DMA3, 1 << 11
.equiv IRQ_MASK_KEYPAD, 1 << 12
.equiv IRQ_MASK_GAMEPAK, 1 << 13

.equiv VCOUNT_VBLANK, 160
.equiv TOTAL_SCANLINES, 228

@ I/O register offsets
.equiv IO_OFFS_DISPCNT, 0x0
.equiv IO_OFFS_DISPSTAT, 0x4
.equiv IO_OFFS_VCOUNT, 0x6
.equiv IO_OFFS_BG0CNT, 0x8
.equiv IO_OFFS_BG1CNT, 0xa
.equiv IO_OFFS_BG2CNT, 0xc
.equiv IO_OFFS_BG3CNT, 0xe
.equiv IO_OFFS_BG0HOFS, 0x10
.equiv IO_OFFS_BG0VOFS, 0x12
.equiv IO_OFFS_BG1HOFS, 0x14
.equiv IO_OFFS_BG1VOFS, 0x16
.equiv IO_OFFS_BG2HOFS, 0x18
.equiv IO_OFFS_BG2VOFS, 0x1a
.equiv IO_OFFS_BG3HOFS, 0x1c
.equiv IO_OFFS_BG3VOFS, 0x1e
.equiv IO_OFFS_BG2PA, 0x20
.equiv IO_OFFS_BG2PB, 0x22
.equiv IO_OFFS_BG2PC, 0x24
.equiv IO_OFFS_BG2PD, 0x26
.equiv IO_OFFS_BG2X_L, 0x28
.equiv IO_OFFS_BG2X_H, 0x2a
.equiv IO_OFFS_BG2Y_L, 0x2c
.equiv IO_OFFS_BG2Y_H, 0x2e
.equiv IO_OFFS_BG3PA, 0x30
.equiv IO_OFFS_BG3PB, 0x32
.equiv IO_OFFS_BG3PC, 0x34
.equiv IO_OFFS_BG3PD, 0x36
.equiv IO_OFFS_BG3X_L, 0x38
.equiv IO_OFFS_BG3X_H, 0x3a
.equiv IO_OFFS_BG3Y_L, 0x3c
.equiv IO_OFFS_BG3Y_H, 0x3e
.equiv IO_OFFS_WIN0H, 0x40
.equiv IO_OFFS_WIN1H, 0x42
.equiv IO_OFFS_WIN0V, 0x44
.equiv IO_OFFS_WIN1V, 0x46
.equiv IO_OFFS_WININ, 0x48
.equiv IO_OFFS_WINOUT, 0x4a
.equiv IO_OFFS_MOSAIC, 0x4c
.equiv IO_OFFS_BLDCNT, 0x50
.equiv IO_OFFS_BLDALPHA, 0x52
.equiv IO_OFFS_BLDY, 0x54

.equiv IO_OFFS_SOUND1CNT, 0x60
.equiv IO_OFFS_SOUND1CNT_L, 0x60
.equiv IO_OFFS_NR10, 0x60
.equiv IO_OFFS_SOUND1CNT_H, 0x62
.equiv IO_OFFS_NR11, 0x62
.equiv IO_OFFS_NR12, 0x63
.equiv IO_OFFS_SOUND1CNT_X, 0x64
.equiv IO_OFFS_NR13, 0x64
.equiv IO_OFFS_NR14, 0x65
.equiv IO_OFFS_SOUND2CNT, 0x68
.equiv IO_OFFS_SOUND2CNT_L, 0x68
.equiv IO_OFFS_NR21, 0x68
.equiv IO_OFFS_NR22, 0x69
.equiv IO_OFFS_SOUND2CNT_H, 0x6c
.equiv IO_OFFS_NR23, 0x6c
.equiv IO_OFFS_NR24, 0x6d
.equiv IO_OFFS_SOUND3CNT, 0x70
.equiv IO_OFFS_SOUND3CNT_L, 0x70
.equiv IO_OFFS_NR30, 0x70
.equiv IO_OFFS_SOUND3CNT_H, 0x72
.equiv IO_OFFS_NR31, 0x72
.equiv IO_OFFS_NR32, 0x73
.equiv IO_OFFS_SOUND3CNT_X, 0x74
.equiv IO_OFFS_NR33, 0x74
.equiv IO_OFFS_NR34, 0x75
.equiv IO_OFFS_SOUND4CNT, 0x78
.equiv IO_OFFS_SOUND4CNT_L, 0x78
.equiv IO_OFFS_NR41, 0x78
.equiv IO_OFFS_NR42, 0x79
.equiv IO_OFFS_SOUND4CNT_H, 0x7c
.equiv IO_OFFS_NR43, 0x7c
.equiv IO_OFFS_NR44, 0x7d
.equiv IO_OFFS_SOUNDCNT, 0x80
.equiv IO_OFFS_SOUNDCNT_L, 0x80
.equiv IO_OFFS_NR50, 0x80
.equiv IO_OFFS_NR51, 0x81
.equiv IO_OFFS_SOUNDCNT_H, 0x82
.equiv IO_OFFS_SOUNDCNT_X, 0x84
.equiv IO_OFFS_NR52, 0x84
.equiv IO_OFFS_SOUNDBIAS, 0x88
.equiv IO_OFFS_WAVE_RAM, 0x90
.equiv IO_OFFS_WAVE_RAM0, 0x90
.equiv IO_OFFS_WAVE_RAM0_L, 0x90
.equiv IO_OFFS_WAVE_RAM0_H, 0x92
.equiv IO_OFFS_WAVE_RAM1, 0x94
.equiv IO_OFFS_WAVE_RAM1_L, 0x94
.equiv IO_OFFS_WAVE_RAM1_H, 0x96
.equiv IO_OFFS_WAVE_RAM2, 0x98
.equiv IO_OFFS_WAVE_RAM2_L, 0x98
.equiv IO_OFFS_WAVE_RAM2_H, 0x9a
.equiv IO_OFFS_WAVE_RAM3, 0x9c
.equiv IO_OFFS_WAVE_RAM3_L, 0x9c
.equiv IO_OFFS_WAVE_RAM3_H, 0x9e
.equiv IO_OFFS_FIFO, 0xa0
.equiv IO_OFFS_FIFO_A, 0xa0
.equiv IO_OFFS_FIFO_A_L, 0xa0
.equiv IO_OFFS_FIFO_A_H, 0xa2
.equiv IO_OFFS_FIFO_B, 0xa4
.equiv IO_OFFS_FIFO_B_L, 0xa4
.equiv IO_OFFS_FIFO_B_H, 0xa6

.equiv IO_OFFS_DMA0, 0xb0
.equiv IO_OFFS_DMA0SAD, 0xb0
.equiv IO_OFFS_DMA0SAD_L, 0xb0
.equiv IO_OFFS_DMA0SAD_H, 0xb2
.equiv IO_OFFS_DMA0DAD, 0xb4
.equiv IO_OFFS_DMA0DAD_L, 0xb4
.equiv IO_OFFS_DMA0DAD_H, 0xb6
.equiv IO_OFFS_DMA0CNT, 0xb8
.equiv IO_OFFS_DMA0CNT_L, 0xb8
.equiv IO_OFFS_DMA0CNT_H, 0xba
.equiv IO_OFFS_DMA1, 0xbc
.equiv IO_OFFS_DMA1SAD, 0xbc
.equiv IO_OFFS_DMA1SAD_L, 0xbc
.equiv IO_OFFS_DMA1SAD_H, 0xbe
.equiv IO_OFFS_DMA1DAD, 0xc0
.equiv IO_OFFS_DMA1DAD_L, 0xc0
.equiv IO_OFFS_DMA1DAD_H, 0xc2
.equiv IO_OFFS_DMA1CNT, 0xc4
.equiv IO_OFFS_DMA1CNT_L, 0xc4
.equiv IO_OFFS_DMA1CNT_H, 0xc6
.equiv IO_OFFS_DMA2, 0xc8
.equiv IO_OFFS_DMA2SAD, 0xc8
.equiv IO_OFFS_DMA2SAD_L, 0xc8
.equiv IO_OFFS_DMA2SAD_H, 0xca
.equiv IO_OFFS_DMA2DAD, 0xcc
.equiv IO_OFFS_DMA2DAD_L, 0xcc
.equiv IO_OFFS_DMA2DAD_H, 0xce
.equiv IO_OFFS_DMA2CNT, 0xd0
.equiv IO_OFFS_DMA2CNT_L, 0xd0
.equiv IO_OFFS_DMA2CNT_H, 0xd2
.equiv IO_OFFS_DMA3, 0xd4
.equiv IO_OFFS_DMA3SAD, 0xd4
.equiv IO_OFFS_DMA3SAD_L, 0xd4
.equiv IO_OFFS_DMA3SAD_H, 0xd6
.equiv IO_OFFS_DMA3DAD, 0xd8
.equiv IO_OFFS_DMA3DAD_L, 0xd8
.equiv IO_OFFS_DMA3DAD_H, 0xda
.equiv IO_OFFS_DMA3CNT, 0xdc
.equiv IO_OFFS_DMA3CNT_L, 0xdc
.equiv IO_OFFS_DMA3CNT_H, 0xde

.equiv IO_OFFS_TM0CNT, 0x100
.equiv IO_OFFS_TM0CNT_L, 0x100
.equiv IO_OFFS_TM0CNT_H, 0x102
.equiv IO_OFFS_TM1CNT, 0x104
.equiv IO_OFFS_TM1CNT_L, 0x104
.equiv IO_OFFS_TM1CNT_H, 0x106
.equiv IO_OFFS_TM2CNT, 0x108
.equiv IO_OFFS_TM2CNT_L, 0x108
.equiv IO_OFFS_TM2CNT_H, 0x10a
.equiv IO_OFFS_TM3CNT, 0x10c
.equiv IO_OFFS_TM3CNT_L, 0x10c
.equiv IO_OFFS_TM3CNT_H, 0x10e

.equiv IO_OFFS_SIOCNT, 0x128
.equiv IO_OFFS_SIODATA8, 0x12a
.equiv IO_OFFS_SIODATA32, 0x120
.equiv IO_OFFS_SIOMLT_SEND, 0x12a
.equiv IO_OFFS_SIOMLT_RECV, 0x120
.equiv IO_OFFS_SIOMULTI0, 0x120
.equiv IO_OFFS_SIOMULTI1, 0x122
.equiv IO_OFFS_SIOMULTI2, 0x124
.equiv IO_OFFS_SIOMULTI3, 0x126

.equiv IO_OFFS_KEYINPUT, 0x130
.equiv IO_OFFS_KEYCNT, 0x132

.equiv IO_OFFS_RCNT, 0x134

.equiv IO_OFFS_JOYCNT, 0x140
.equiv IO_OFFS_JOYSTAT, 0x158
.equiv IO_OFFS_JOY_RECV, 0x150
.equiv IO_OFFS_JOY_RECV_L, 0x150
.equiv IO_OFFS_JOY_RECV_H, 0x152
.equiv IO_OFFS_JOY_TRANS, 0x154
.equiv IO_OFFS_JOY_TRANS_L, 0x154
.equiv IO_OFFS_JOY_TRANS_H, 0x156

.equiv IO_OFFS_IME, 0x208
.equiv IO_OFFS_IE, 0x200
.equiv IO_OFFS_IF, 0x202

.equiv IO_OFFS_WAITCNT, 0x204

@ DMA register constants

.equiv DMA_DEST_INC, 0x0000
.equiv DMA_DEST_DEC, 0x0020
.equiv DMA_DEST_FIXED, 0x0040
.equiv DMA_DEST_RELOAD, 0x0060
.equiv DMA_SRC_INC, 0x0000
.equiv DMA_SRC_DEC, 0x0080
.equiv DMA_SRC_FIXED, 0x0100
.equiv DMA_REPEAT, 0x0200
.equiv DMA_16BIT, 0x0000
.equiv DMA_32BIT, 0x0400
.equiv DMA_DREQ_ON, 0x0800
.equiv DMA_START_NOW, 0x0000
.equiv DMA_START_VBLANK, 0x1000
.equiv DMA_START_HBLANK, 0x2000
.equiv DMA_START_SPECIAL, 0x3000
.equiv DMA_INTR_ENABLE, 0x4000
.equiv DMA_ENABLE, 0x8000

@ OAM attribute constants

.equiv OAM_OBJ_NORMAL, 0x00000000
.equiv OAM_OBJ_BLEND, 0x00000400
.equiv OAM_OBJ_WINDOW, 0x00000800

.equiv OAM_AFFINE_NONE, 0x00000000
.equiv OAM_AFFINE_NORMAL_SIZE, 0x00000100
.equiv OAM_OBJ_DISABLED, 0x00000200
.equiv OAM_AFFINE_DOUBLE_SIZE, 0x00000300

.equiv OAM_MOSAIC_OFF, 0x00000000
.equiv OAM_MOSAIC_ON, 0x00001000

.equiv OAM_4BPP, 0x00000000
.equiv OAM_8BPP, 0x00002000

.equiv OAM_H_FLIP, 0x10000000
.equiv OAM_V_FLIP, 0x20000000

.equiv OAM_SQUARE, 0x00000000
.equiv OAM_H_RECTANGLE, 0x00004000
.equiv OAM_V_RECTANGLE, 0x00008000
.equiv OAM_SIZE_0, 0x00000000
.equiv OAM_SIZE_1, 0x40000000
.equiv OAM_SIZE_2, 0x80000000
.equiv OAM_SIZE_3, 0xc0000000

.equiv OAM_SIZE_8x8, OAM_SIZE_0 | OAM_SQUARE
.equiv OAM_SIZE_16x16, OAM_SIZE_1 | OAM_SQUARE
.equiv OAM_SIZE_32x32, OAM_SIZE_2 | OAM_SQUARE
.equiv OAM_SIZE_64x64, OAM_SIZE_3 | OAM_SQUARE

.equiv OAM_SIZE_16x8, OAM_SIZE_0 | OAM_H_RECTANGLE
.equiv OAM_SIZE_32x8, OAM_SIZE_1 | OAM_H_RECTANGLE
.equiv OAM_SIZE_32x16, OAM_SIZE_2 | OAM_H_RECTANGLE
.equiv OAM_SIZE_64x32, OAM_SIZE_3 | OAM_H_RECTANGLE

.equiv OAM_SIZE_8x16, OAM_SIZE_0 | OAM_V_RECTANGLE
.equiv OAM_SIZE_8x32, OAM_SIZE_1 | OAM_V_RECTANGLE
.equiv OAM_SIZE_16x32, OAM_SIZE_2 | OAM_V_RECTANGLE
.equiv OAM_SIZE_32x64, OAM_SIZE_3 | OAM_V_RECTANGLE

.endif @ INC__NICHRUBY_CONST_GBA_S
