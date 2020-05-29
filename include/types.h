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

#ifndef INC__TYPES_H
#define INC__TYPES_H

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef unsigned int ptri;

typedef volatile signed char vs8;
typedef volatile signed short vs16;
typedef volatile signed int vs32;

typedef volatile unsigned char vu8;
typedef volatile unsigned short vu16;
typedef volatile unsigned int vu32;

typedef volatile unsigned int vptri;

typedef u16 col_t;
typedef u16 monid_t;
typedef u16 item_t;
typedef u16 move_t;
typedef u16 svar_t;
typedef u16 song_t;

struct s16v2
{
	s16 a, b;
};

#endif /* INC__TYPES_H */
