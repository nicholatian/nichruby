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

#ifndef INC__BASE_TYPES_H
#define INC__BASE_TYPES_H

/* specific-width integer types */

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* pointer-width integer */
typedef unsigned int ptri;

/* volatile variants */

typedef volatile signed char vs8;
typedef volatile signed short vs16;
typedef volatile signed int vs32;

typedef volatile unsigned char vu8;
typedef volatile unsigned short vu16;
typedef volatile unsigned int vu32;

typedef volatile unsigned int vptri;

/* repo-specific primitive typedefs */

typedef u16 col_t;
typedef u16 monid_t;
typedef u16 item_t;
typedef u16 move_t;
typedef u16 svar_t;
typedef u16 song_t;

/* vector typedefs */

struct s8v2
{
	s8 n[0x2];
};

struct s8v4
{
	s8 n[0x4];
};

struct s8v8
{
	s8 n[0x8];
};

struct s8v16
{
	s8 n[0x10];
};

struct s8v32
{
	s8 n[0x20];
};

struct s16v2
{
	s16 a, b;
};

struct s16v4
{
	s16 n[0x4];
};

struct s16v8
{
	s16 n[0x8];
};

struct s16v16
{
	s16 n[0x10];
};

struct s32v2
{
	s32 a, b;
};

struct s32v4
{
	s32 n[0x4];
};

struct s32v8
{
	s32 n[0x8];
};

struct u8v2
{
	u8 n[0x2];
};

struct u8v4
{
	u8 n[0x4];
};

struct u8v8
{
	u8 n[0x8];
};

struct u8v16
{
	u8 n[0x10];
};

struct u8v32
{
	u8 n[0x20];
};

struct u16v2
{
	u16 a, b;
};

struct u16v4
{
	u16 n[0x4];
};

struct u16v8
{
	u16 n[0x8];
};

struct u16v16
{
	u16 n[0x10];
};

struct u32v2
{
	u32 a, b;
};

struct u32v4
{
	u32 n[0x4];
};

struct u32v8
{
	u32 n[0x8];
};

#endif /* INC__BASE_TYPES_H */
