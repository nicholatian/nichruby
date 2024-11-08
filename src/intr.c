/*********************************************************************\
 *    __   _ _____ _______ _     _  ______ _     _ ______ __   __    *
 *    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      *
 *    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       *
 *                             nich ruby                             *
 *                                                                   *
 *             Copyright (C) 2020-2024 Alexander Nicholi             *
 *                    Released under BSD-2-Clause                    *
\*********************************************************************/

/* STATE MODULE */

#include "intr.h"

#include "memset.h"
#include "const/types/int.h"

#include "const/gba.h"

SBSS volatile struct intr_state intr_state;

SBSS const PFN_intr_func intr_table[MAX_INTR] = {
	intr_vblank,
	intr_hblank,
	intr_vcount,
	intr_timer0,
	intr_timer1,
	intr_timer2,
	intr_timer3,
	intr_serial,
	intr_dma0,
	intr_dma1,
	intr_dma2,
	intr_dma3,
	intr_key,
	intr_gamepak
};

SBSS const u8 intr_prior[MAX_INTR] = {
	2,
	0,
	2,
	1,
	1,
	1,
	0,
	0,
	0,
	1,
	1,
	4,
	5,
	5
};

TEXT32 void intr_state_init( void )
{
	memset( &intr_state, 0, sizeof intr_state );
}

TEXT32 void intr_hblank( void )
{
	ptri i;

	intr_state.hblank_reset =
		(intr_state.hblank_i + 1) >= ( 1 << 10 ) ? 1 : 0;
	intr_state.hblank_i++;

	for( i = 0;
		i < MAX_CALLBACKS && intr_state.hblank_cb[i] != NULL;
		++i )
	{
		intr_state.hblank_cb[i]( &intr_state );
	}
}

TEXT32 void intr_vblank( void )
{
	ptri i;

	intr_state.vblank_reset =
		(intr_state.vblank_i + 1) >= ( 1 << 10 ) ? 1 : 0;
	intr_state.vblank_i++;

	for( i = 0;
		i < MAX_CALLBACKS && intr_state.vblank_cb[i] != NULL;
		++i )
	{
		intr_state.vblank_cb[i]( &intr_state );
	}
}

TEXT32 void intr_vcount( void )
{
	ptri i;

	for( i = 0;
		i < MAX_CALLBACKS && intr_state.vcount_cb[i] != NULL;
		++i )
	{
		intr_state.vcount_cb[i]( &intr_state );
	}
}

TEXT32 void intr_serial( void )
{
	ptri i;

	for( i = 0;
		i < MAX_CALLBACKS && intr_state.serial_cb[i] != NULL;
		++i )
	{
		intr_state.serial_cb[i]( &intr_state );
	}
}

TEXT32 void intr_timer0( void ) {}
TEXT32 void intr_timer1( void ) {}
TEXT32 void intr_timer2( void ) {}
TEXT32 void intr_timer3( void ) {}

TEXT32 void intr_dma0( void ) {}
TEXT32 void intr_dma1( void ) {}
TEXT32 void intr_dma2( void ) {}
TEXT32 void intr_dma3( void ) {}

TEXT32 void intr_key( void ) {}
TEXT32 void intr_gamepak( void ) {}
