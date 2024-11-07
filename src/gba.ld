/*********************************************************************\
 *    __   _ _____ _______ _     _  ______ _     _ ______ __   __    *
 *    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      *
 *    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       *
 *                             nich ruby                             *
 *                                                                   *
 *             Copyright (C) 2020-2024 Alexander Nicholi             *
 *                    Released under BSD-2-Clause                    *
\*********************************************************************/

MEMORY
{
	ewram  : ORIGIN = 0x2000000, LENGTH = 256k
	iwram  : ORIGIN = 0x3000000, LENGTH = 32k
	io     : ORIGIN = 0x4000000, LENGTH = 1k - 1
	pal    : ORIGIN = 0x5000000, LENGTH = 1k
	vram   : ORIGIN = 0x6000000, LENGTH = 96k
	oam    : ORIGIN = 0x7000000, LENGTH = 1k
	rom    : ORIGIN = 0x8000000, LENGTH = 32M
}

ENTRY( _start );

ld_ewram_start = ORIGIN( ewram );
ld_ewram_len   = LENGTH( ewram );
ld_ewram_end   = ld_ewram_start + ld_ewram_len;
ld_iwram_start = ORIGIN( iwram );
ld_iwram_len   = LENGTH( iwram );
ld_iwram_end   = ld_iwram_start + ld_iwram_len;
ld_io_start    = ORIGIN( io );
ld_io_len      = LENGTH( io );
ld_io_end      = ld_io_start + ld_io_len;
ld_pal_start   = ORIGIN( pal );
ld_pal_len     = LENGTH( pal );
ld_pal_end     = ld_pal_start + ld_pal_len;
ld_vram_start  = ORIGIN( vram );
ld_vram_len    = LENGTH( vram );
ld_vram_end    = ld_vram_start + ld_vram_len;
ld_oam_start   = ORIGIN( oam );
ld_oam_len     = LENGTH( oam );
ld_oam_end     = ld_oam_start + ld_oam_len;
ld_rom_start   = ORIGIN( rom );
ld_rom_maxlen  = LENGTH( rom );

SECTIONS
{
	/* we start outputting at the beginning of ROM. */
	. = ORIGIN( rom );

	ld_init_start = .;

	.init :
	{
		KEEP( *( SORT_NONE( .init ) ) );
		. = ALIGN( 4 );
	} =0xFF

	ld_init_end = .;
	ld_init_len = . - ld_init_start;
	ld_text_start = .;

	.text :
	{
		*( SORT( .text ) );
		. = ALIGN( 4 );
	} =0xFF

	ld_text_end = .;
	ld_text_len = . - ld_text_start;
	ld_rodata_start = .;

	.rodata :
	{
		*( SORT( .rodata ) );
		. = ALIGN( 4 );
	} =0xFF

	ld_rodata_end = .;
	ld_rodata_len = . - ld_rodata_start;

	/* _vma suffix is Virtual Memory Address
	 * _lma suffix is Load Memory Address
	 *
	 * Basically, LMA is the ROM address these sections are stored in
	 * while VMA is where the linker will "understand" them to exist at
	 * runtime. This is dependent on a copy routine in crt0. Really,
	 * our code here is merely encoding the symbols necessary to
	 * communicate the information it calculates about where everything
	 * starts and ends, how big everything is, and doing it for both
	 * address kinds :)
	 *
	 * As an added bonus, we define a _heap_{start,end} pair that is
	 * defined as the remainder of physical EWRAM, for use by the
	 * in-house malloc implementation.
	 *
	 * nichruby specific definitions:
	 * .bss and .text16 are placed into EWRAM
	 * .sbss and .text32 are placed into IWRAM
	 * .bss = Better Save Space and are zero-initialised static data
	 *   .sbss = Small Better Save Space
	 * .text{16,32} = Code that needs to be called in RAM
	 */
	. = ORIGIN( iwram );
	ld_sbss_start_lma = ld_rodata_end;
	ld_sbss_start_vma = .;

	.sbss : AT( ld_sbss_start_lma )
	{
		*( SORT( .sbss ) );
		. = ALIGN( 4 );
	} =0xFF

	ld_sbss_end_vma = .;
	ld_sbss_len = ld_sbss_end_vma - ld_sbss_start_vma;
	ld_sbss_end_lma = ld_sbss_start_lma + ld_sbss_len;

	ld_text32_start_vma = .;
	ld_text32_start_lma = ld_sbss_end_lma;

	.text32 : AT( ld_text32_start_lma )
	{
		*( SORT( .text32 ) );
		. = ALIGN( 4 );
	} =0xFF

	ld_text32_end_vma = .;
	ld_text32_len = ld_text32_end_vma - ld_text32_start_vma;
	ld_text32_end_lma = ld_text32_start_lma + ld_text32_len;

	. = ORIGIN( ewram );
	ld_bss_start_vma = .;
	ld_bss_start_lma = ld_text32_end_lma;

	.bss : AT( ld_bss_start_lma )
	{
		*( SORT( .bss ) );
		. = ALIGN( 4 );
	} =0xFF

	ld_bss_end_vma = .;
	ld_bss_len = ld_bss_end_vma - ld_bss_start_vma;
	ld_bss_end_lma = ld_bss_start_lma + ld_bss_len;

	ld_text16_start_vma = .;
	ld_text16_start_lma = ld_bss_end_lma;

	.text16 : AT( ld_text16_start_lma )
	{
		*( SORT( .text16 ) );
		. = ALIGN( 4 );
	} =0xFF

	ld_text16_end_vma = .;
	ld_text16_len = ld_text16_end_vma - ld_text16_start_vma;
	ld_text16_end_lma = ld_text16_start_lma + ld_text16_len;
	ld_rom_end = ld_text16_end_lma;
	ld_rom_len = ld_rom_end - ld_rom_start;
	ld_rom_free = ld_rom_maxlen - ld_rom_len;

	ld_heap_start = ORIGIN( ewram ) + ( ld_bss_len + ld_text16_len );
	ld_heap_end = LENGTH( ewram ) - ( ld_bss_len + ld_text16_len );
}
