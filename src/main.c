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

/* STATE MODULE */

#include "intr.h"

#include <uni/types/int.h>

#if 0
static void intr_vblank( void );
static void intr_hblank( void );
static void intr_vcount( void );
static void intr_serial( void );
static void intr_timer3( void );
static void intr_dummy( void );
#endif

enum
{
	TBL_INTR_TMPL_SZ = 14
};

#if 0
static const PFN_intr_func tbl_intr_tmpl[TBL_INTR_TMPL_SZ] = { intr_serial,
	intr_timer3,
	intr_hblank,
	intr_vblank,
	intr_vcount,
	intr_dummy,
	intr_dummy,
	intr_dummy,
	intr_dummy,
	intr_dummy,
	intr_dummy,
	intr_dummy,
	intr_dummy,
	intr_dummy };
#endif

u32 intr_table = 0;

int main( void ) { return 0; }
