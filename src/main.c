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

#include "const/gba.h"
#include "const/ldglobls.h"
#include "const/types/gba.h"
#include "const/types/int.h"

extern const col_t egerror_jasc;

const PFN_intr_func intr_table[] = { intr_vcount,
	intr_serial,
	intr_timer3,
	intr_hblank,
	intr_vblank,
	intr_timer0,
	intr_timer1,
	intr_timer2,
	intr_dma0,
	intr_dma1,
	intr_dma2,
	intr_dma3,
	intr_key,
	intr_gamepak };

int main( void )
{
	ptri i;
	const u16 v = 15 | ( 15 << 8 );

	intr_state_init( );

	for( i = 0; i < 0x9B00; ++i )
	{
		*(volatile u16 *)( &ld_vram_start + ( i << 1 ) ) = v;
	}

	for( i = 0; i < 0x10; ++i )
	{
		const col_t * col = ( &egerror_jasc )[i];
		*(volatile u16 *)( &ld_pal_start + ( i << 1 ) ) = col;
	}

	*(volatile u16 *)(&ld_io_start + IO_OFFS_DISPCNT) = 4 | ( 1 << 10 );

	return 0;
}
