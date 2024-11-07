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

#ifndef INC__NICHRUBY_CONST_LDGLOBLS_H
#define INC__NICHRUBY_CONST_LDGLOBLS_H

#include "types/base.h"
#include "types/int.h"

extern const u8 ld_ewram_start TYPELESS;
extern const u8 ld_ewram_len TYPELESS;
extern const u8 ld_ewram_end TYPELESS;

extern const u8 ld_iwram_start TYPELESS;
extern const u8 ld_iwram_len TYPELESS;
extern const u8 ld_iwram_end TYPELESS;

extern const u8 ld_io_start TYPELESS;
extern const u8 ld_io_len TYPELESS;
extern const u8 ld_io_end TYPELESS;

extern const u8 ld_pal_start TYPELESS;
extern const u8 ld_pal_len TYPELESS;
extern const u8 ld_pal_end TYPELESS;

extern const u8 ld_vram_start TYPELESS;
extern const u8 ld_vram_len TYPELESS;
extern const u8 ld_vram_end TYPELESS;

extern const u8 ld_oam_start TYPELESS;
extern const u8 ld_oam_len TYPELESS;
extern const u8 ld_oam_end TYPELESS;

extern const u8 ld_rom_start TYPELESS;
extern const u8 ld_rom_len TYPELESS;
extern const u8 ld_rom_maxlen TYPELESS;
extern const u8 ld_rom_free TYPELESS;
extern const u8 ld_rom_end TYPELESS;

extern const u8 ld_init_start TYPELESS;
extern const u8 ld_init_len TYPELESS;
extern const u8 ld_init_end TYPELESS;

extern const u8 ld_text_start TYPELESS;
extern const u8 ld_text_len TYPELESS;
extern const u8 ld_text_end TYPELESS;

extern const u8 ld_rodata_start TYPELESS;
extern const u8 ld_rodata_len TYPELESS;
extern const u8 ld_rodata_end TYPELESS;

extern const u8 ld_sbss_start TYPELESS;
extern const u8 ld_sbss_len TYPELESS;
extern const u8 ld_sbss_end TYPELESS;

extern const u8 ld_text32_start TYPELESS;
extern const u8 ld_text32_len TYPELESS;
extern const u8 ld_text32_end TYPELESS;

extern const u8 ld_bss_start TYPELESS;
extern const u8 ld_bss_len TYPELESS;
extern const u8 ld_bss_end TYPELESS;

extern const u8 ld_text16_start TYPELESS;
extern const u8 ld_text16_len TYPELESS;
extern const u8 ld_text16_end TYPELESS;

extern const u8 ld_heap_start TYPELESS;
extern const u8 ld_heap_end TYPELESS;

#endif /* INC__NICHRUBY_CONST_LDGLOBLS_H */
