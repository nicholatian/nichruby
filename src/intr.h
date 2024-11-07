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

#ifndef INC__NICHRUBY_INTR_H
#define INC__NICHRUBY_INTR_H

#include "const/gba.h"
#include "const/types/int.h"

struct intr_state;

typedef void ( *PFN_intr_func )( void );
typedef int ( *PFN_callback )( struct intr_state * );

enum
{
	MAX_CALLBACKS = 4
};

enum
{
	INTR_HBLANK,
	INTR_VBLANK,
	INTR_VCOUNT,
	INTR_SERIAL,
	INTR_TIMER0,
	INTR_TIMER1,
	INTR_TIMER2,
	INTR_TIMER3,
	INTR_DMA0,
	INTR_DMA1,
	INTR_DMA2,
	INTR_DMA3,
	INTR_KEY,
	INTR_GAMEPAK,
	MAX_INTR
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

extern const PFN_intr_func intr_table[MAX_INTR];
extern const u8 intr_prior[MAX_INTR];

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

#endif /* INC__NICHRUBY_INTR_H */
