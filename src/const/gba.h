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

/* DEFINITION MODULE */

#ifndef INC__BASE_GBA_H
#define INC__BASE_GBA_H

#define EWRAM_DATA __attribute__( ( section( "ewram_data" ) ) )

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
	EWRAM_SZ = 0x40000,
	IWRAM_SZ = 0x8000,
	PAL_SZ   = 0x400,
	VRAM_SZ  = 0x18000,
	SRAM_SZ  = 0x10000
};

enum
{
	OAM_SZ = 0x400
};

enum
{
	/* Extended working RAM */
	EWRAM = 0x2000000,
	/* Internal working RAM */
	IWRAM = 0x3000000,
	/* Memory-mapped I/O */
	IO = 0x4000000,
	/* Palette RAM */
	PAL = 0x5000000,
	/* Video RAM */
	VRAM = 0x6000000,
	/* “Object Attribute Memory” */
	OAM = 0x7000000,
	/* Read only memory (Game pak) */
	ROM = 0x8000000,
	/* Static RAM (save file) */
	SRAM = 0xE000000
};

enum
{
	/* Display control */
	DISPCNT = IO + 0x0,
	/* “Green swap” (undocumented, unused) */
	GREENSWAP = IO + 0x2,
	/* Display stat (?) */
	DISPSTAT = IO + 0x4,
	/* Vertical counter for the currently drawn scanline */
	VCOUNT = IO + 0x6,
	/* BG 0 control */
	BG0CNT = IO + 0x8,
	/* BG 1 control */
	BG1CNT = IO + 0xA,
	/* BG 2 control */
	BG2CNT = IO + 0xC,
	/* BG 3 control */
	BG3CNT = IO + 0xE,
	/* BG 0 horizontal offset */
	BG0HOFS = IO + 0x10,
	/* BG 0 vertical offset */
	BG0VOFS = IO + 0x12,
	/* BG 1 horizontal offset */
	BG1HOFS = IO + 0x14,
	/* BG 1 vertical offset */
	BG1VOFS = IO + 0x16,
	/* BG 2 horizontal offset */
	BG2HOFS = IO + 0x18,
	/* BG 2 vertical offset */
	BG2VOFS = IO + 0x1A,
	/* BG 3 horizontal offset */
	BG3HOFS = IO + 0x1C,
	/* BG 3 vertical offset */
	BG3VOFS = IO + 0x1E,
	/* BG 2 rotation/scaling parameter A (dx) */
	BG2PA = IO + 0x20,
	/* BG 2 rotation/scaling parameter B (dmx) */
	BG2PB = IO + 0x22,
	/* BG 2 rotation/scaling parameter C (dy) */
	BG2PC = IO + 0x24,
	/* BG 2 rotation/scaling parameter D (dmy) */
	BG2PD = IO + 0x26,
	/* BG 2 reference point X coordinate, lower 16 bits */
	BG2X_L = IO + 0x28,
	/* BG 2 reference point X coordinate, upper 12 bits */
	BG2X_H = IO + 0x2A,
	/* BG 2 reference point Y coordinate, lower 16 bits */
	BG2Y_L = IO + 0x2C,
	/* BG 2 reference point Y coordinate, upper 12 bits */
	BG2Y_H = IO + 0x2E,
	/* BG 3 rotation/scaling parameter A (dx) */
	BG3PA = IO + 0x30,
	/* BG 3 rotation/scaling parameter B (dmx) */
	BG3PB = IO + 0x32,
	/* BG 3 rotation/scaling parameter C (dy) */
	BG3PC = IO + 0x34,
	/* BG 3 rotation/scaling parameter D (dmy) */
	BG3PD = IO + 0x36,
	/* BG 3 reference point X coordinate, lower 16 bits */
	BG3X_L = IO + 0x38,
	/* BG 3 reference point X coordinate, upper 12 bits */
	BG3X_H = IO + 0x3A,
	/* BG 3 reference point Y coordinate, lower 16 bits */
	BG3Y_L = IO + 0x3C,
	/* BG 3 reference point Y coordinate, upper 12 bits */
	BG3Y_H = IO + 0x3E,
	/* Window 0 horizontal size */
	WIN0H = IO + 0x40,
	/* Window 1 horizontal size */
	WIN1H = IO + 0x42,
	/* Window 0 vertical size */
	WIN0V = IO + 0x44,
	/* Window 1 vertical size */
	WIN1V = IO + 0x46,
	/* Window inside control */
	WININ = IO + 0x48,
	/* Window outside control */
	WINOUT = IO + 0x4A,
	/* Mosaic control register */
	MOSAIC = IO + 0x4C
};

#endif /* INC__BASE_GBA_H */
