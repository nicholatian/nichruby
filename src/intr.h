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

#ifndef INC__INTR_H
#define INC__INTR_H

#include <uni/types/int.h>

#include "const/gba.h"

struct intr_state;

typedef void (*PFN_intr_func)( void );
typedef int (*PFN_callback)( struct intr_state* );

enum
{
	MAX_CALLBACKS = 4
};

struct intr_state
{
	unsigned hblank_i : 10;
	unsigned vblank_i : 10;
	unsigned hblank_reset : 1;
	unsigned vblank_reset : 1;
	unsigned keys : MAX_KEY;
	PFN_callback vblank_cb[MAX_CALLBACKS];
	PFN_callback hblank_cb[MAX_CALLBACKS];
	PFN_callback vcount_cb[MAX_CALLBACKS];
	PFN_callback serial_cb[MAX_CALLBACKS];
};

extern struct intr_state intr_state;

void intr_state_init( void );
void intr_hblank( void );
void intr_vblank( void );
void intr_vcount( void );
void intr_serial( void );
void intr_timer0( void );
void intr_timer1( void );
void intr_timer2( void );
void intr_timer3( void );
void intr_dma0( void );
void intr_dma1( void );
void intr_dma2( void );
void intr_dma3( void );
void intr_key( void );
void intr_gamepak( void );

#endif /* INC__INTR_H */
