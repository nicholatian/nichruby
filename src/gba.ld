MEMORY
{
	ewram : ORIGIN = 0x2000000, LENGTH = 262144 /* 256 KiB */
	iwram : ORIGIN = 0x3000000, LENGTH = 32768 /* 32 KiB */
	pal : ORIGIN = 0x5000000, LENGTH = 512
	vram : ORIGIN = 0x6000000, LENGTH = 98304 /* 96 KiB */
	oam : ORIGIN = 0x7000000, LENGTH = 512
	rom : ORIGIN = 0x8000000, LENGTH = 33554432 /* 32 MiB */
}

ENTRY(_start)

__iwram_start = ORIGIN(iwram);
__ewram_start = ORIGIN(ewram);
__pal_start   = ORIGIN(pal);
__vram_start  = ORIGIN(vram);
__oam_start   = ORIGIN(oam);
__rom_start   = ORIGIN(rom);
__iwram_end   = __iwram_start + LENGTH(iwram);
__ewram_end   = __ewram_start + LENGTH(ewram);
__pal_end     = __pal_start + LENGTH(pal);
__vram_end    = __vram_start + LENGTH(vram);
__oam_end     = __oam_start + LENGTH(oam);
/* note no __rom_end (yet) */

SECTIONS
{
	. = __rom_start;

	.init :
	{
		KEEP(*(SORT_NONE(.init)))
		. = ALIGN(4);
	} >rom =0xFF

	__text_start = .;

	.text :
	{
		*(EXCLUDE_FILE(*.iwram*) .text*)
		. = ALIGN(4);
	} >rom =0xFF

	__text_end = .;
	__rodata_start = .;

	.rodata :
	{
		*(.rodata)
		. = ALIGN(4);
	} >rom =0xFF

	__rodata_end = .;
	__rom_end = __rodata_end;
	_end = __rodata_end;

	__iwram_lma = .;

	.iwram __iwram_start : AT(__iwram_start)
	{
		__iwram_start__ = ABSOLUTE(.);
		*(.iwram)
		*iwram.*(.text*)
		. = ALIGN(4);
		__iwram_end__ = ABSOLUTE(.);
	} >iwram

	__data_lma = __iwram_lma + SIZEOF(.iwram);

	.data ALIGN(4) : AT(__data_lma)
	{
		__data_start__ = ABSOLUTE(.);
		*(.data)
		*(.data.*)
		*(.data)
		*data.*(.text*)
		. = ALIGN(4);
	} >iwram =0xFF

	.bss ALIGN(4) (NOLOAD) :
	{
		__bss_start = ABSOLUTE(.);
		__bss_start__ = ABSOLUTE(.);
		*(.bss)
		*bss.*(.text*)
		. = ALIGN(4);
		__bss_end__ = ABSOLUTE(.);
	} AT>iwram

	.ewram __ewram_start : AT(__ewram_start)
	{
		__ewram_start__ = ABSOLUTE(.);
		*(.ewram)
		*ewram.*(.text*)
		. = ALIGN(4);
		__ewram_end__ = ABSOLUTE(.);
	} >ewram

	.sbss ALIGN(4) (NOLOAD) :
	{
		__sbss_start = ABSOLUTE(.);
		__sbss_start__ = ABSOLUTE(.);
		*(.sbss)
		*sbss.*(.text*)
		. = ALIGN(4);
		__sbss_end__ = ABSOLUTE(.);
	} AT>ewram
}
