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

SBSS struct intr_state intr_state;

void intr_state_init( void )
{
	memset( &intr_state, 0, sizeof intr_state );
}

void intr_hblank( void )
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

void intr_vblank( void )
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

void intr_vcount( void )
{
	ptri i;

	for( i = 0;
		i < MAX_CALLBACKS && intr_state.vcount_cb[i] != NULL;
		++i )
	{
		intr_state.vcount_cb[i]( &intr_state );
	}
}

void intr_serial( void )
{
	ptri i;

	for( i = 0;
		i < MAX_CALLBACKS && intr_state.serial_cb[i] != NULL;
		++i )
	{
		intr_state.serial_cb[i]( &intr_state );
	}
}

void intr_timer0( void ) {}
void intr_timer1( void ) {}
void intr_timer2( void ) {}
void intr_timer3( void ) {}

void intr_dma0( void ) {}
void intr_dma1( void ) {}
void intr_dma2( void ) {}
void intr_dma3( void ) {}

void intr_key( void ) {}
void intr_gamepak( void ) {}
