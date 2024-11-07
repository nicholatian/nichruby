@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@    __   _ _____ _______ _     _  ______ _     _ ______ __   __    @@
@@    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      @@
@@    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       @@
@@                             nich ruby                             @@
@@                                                                   @@
@@             Copyright (C) 2020-2024 Alexander Nicholi             @@
@@                    Released under BSD-2-Clause                    @@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.ifndef INC__NICHRUBY_CONST_LDGLOBLS_S
.equiv INC__NICHRUBY_CONST_LDGLOBLS_S, 1

.globl ld_ewram_start
.globl ld_ewram_len
.globl ld_ewram_end

.globl ld_iwram_start
.globl ld_iwram_len
.globl ld_iwram_end

.globl ld_io_start
.globl ld_io_len
.globl ld_io_end

.globl ld_pal_start
.globl ld_pal_len
.globl ld_pal_end

.globl ld_vram_start
.globl ld_vram_len
.globl ld_vram_end

.globl ld_oam_start
.globl ld_oam_len
.globl ld_oam_end

.globl ld_rom_start
.globl ld_rom_len
.globl ld_rom_maxlen
.globl ld_rom_free
.globl ld_rom_end

.globl ld_init_start
.globl ld_init_len
.globl ld_init_end

.globl ld_text_start
.globl ld_text_len
.globl ld_text_end

.globl ld_rodata_start
.globl ld_rodata_len
.globl ld_rodata_end

.globl ld_sbss_start
.globl ld_sbss_len
.globl ld_sbss_end

.globl ld_text32_start
.globl ld_text32_len
.globl ld_text32_end

.globl ld_bss_start
.globl ld_bss_len
.globl ld_bss_end

.globl ld_text16_start
.globl ld_text16_len
.globl ld_text16_end

.globl ld_heap_start
.globl ld_heap_end

.endif @ INC__NICHRUBY_CONST_LDGLOBLS_S
