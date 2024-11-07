@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@    __   _ _____ _______ _     _  ______ _     _ ______ __   __    @@
@@    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      @@
@@    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       @@
@@                             nich ruby                             @@
@@                                                                   @@
@@             Copyright (C) 2020-2024 Alexander Nicholi             @@
@@                    Released under BSD-2-Clause                    @@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

@ DEFINITION MODULE

.include "const/gba.s"
.include "const/misc.s"

.syntax unified

.globl _start
.globl rh_nintenpic
.globl gpio_portdata
.globl gpio_portdir
.globl gpio_portreadable
.globl init
.globl intr_main
.globl main
.globl intr_table

.section .init
.code 32

_start:
	b init

	@ the following is set by gbafix

rh_nintenpic:
	.space 0x9C

	@ game title
	.space 12

	@ game code
	.byte 0, 0, 0, 0

	@ maker code
	.byte 0, 0

	@ magic
	.byte 0x96

	@ main unit code
	.byte 0

	@ device type
	.byte 0

	@ reserved
	.space 7

	@ software version
	.byte 0

	@ checksum
	.byte 0

	@ reserved
	.space 2

	@ we are now at ROM:080000C0
	.word 0

gpio_portdata:
	.hword 0

gpio_portdir:
	.hword 0

gpio_portreadable:
	.hword 0

	.space 6

	@ we are now at ROM:080000D0

	.4byte 0xFFFFFFFF
	.4byte 0xFFFFFFFF
	.4byte 0xFFFFFFFF
	.4byte 0xFFFFFFFF
	.4byte 0xFFFFFFFF
	.4byte 0xFFFFFFFF
	.4byte 0xFFFFFFFF
	.4byte 0xFFFFFFFF
	.4byte 0xFFFFFFFF
	.4byte 0xFFFFFFFF
	.4byte 0xFFFFFFFF
	.4byte 0xFFFFFFFF
	.ascii "CXVE"

.section .init
.code 32
.balign 4, 0

init:
	ADD     R0, pc, #1
	BX      R0

.code 16
	@ turn off the display
	MOV     R0, #0x40
	LSL     R0, R0, #24 @ ~LDR R0, #0x4000000
	MOV     R1, #0x80
	STRH    R1, [R0]
	@ fix the waitcnt
	MOV     R1, #0x20
	LSL     R1, R1, #4
	ADD     R1, R1, #4
	ADD     R0, R0, R1
	MOV     R1, #0x43
	MOV     R2, #0x17
	LSL     R1, R1, #8
	ORR     R1, R1, R2 @ ~LDR R1, #0x4317
	STRH    R1, [R0]
	@ copy over speedy BSS
	LDR     R0, =ld_sbss_start_vma @ actually IWRAM
	LDR     R1, =ld_sbss_start_lma @ phantom copy in ROM
	LDR     R2, =ld_sbss_len
	BL      .Lmemcpy
	@ copy over 32-bit RAM code
	LDR     R0, =ld_text32_start_vma @ actually IWRAM
	LDR     R1, =ld_text32_start_lma @ phantom copy in ROM
	LDR     R2, =ld_text32_len
	BL      .Lmemcpy
	@ copy over BSS
	LDR     R0, =ld_bss_start_vma @ actually EWRAM
	LDR     R1, =ld_bss_start_lma @ phantom copy in ROM
	LDR     R2, =ld_bss_len
	BL      .Lmemcpy
	@ copy over 16-bit RAM code
	LDR     R0, =ld_text16_start_vma @ actually EWRAM
	LDR     R1, =ld_text16_start_lma @ phantom copy in ROM
	LDR     R2, =ld_text16_len
	BL      .Lmemcpy

	MOV     R0, PSR_IRQ_MODE
	MSR     cpsr_cf, R0
	LDR     SP, sp_irq
	MOV     R0, PSR_SYS_MODE
	MSR     cpsr_cf, R0
	LDR     SP, sp_sys
	LDR     R1, =intr_vector
	ADR     R0, intr_main
	STR     R0, [R1]
	MOV     R0, #0
	MOV     R1, #0
	MOV     R2, #0
	MOV     R3, #0
	LDR     R4, =main
	MOV     LR, PC
	BX      R4
	B       init

.balign 4, 0
sp_sys: .word ld_iwram_end - 0x1A0
sp_irq: .word ld_iwram_end - 0x60
.pool

@ memcpy
@ A fast memcpy implementation in Thumb-1 assembly for the GBA.
@
@ R0: destination address.
@ R1: source address.
@ R2: number of bytes to fill, in total.
@
@ internally:
@ 24 bytes are copied at a time if possible.
@ this is done by moving the number of bytes to count into R8, and
@ putting the constant 24 into R9 so that hi-register CMPs can be used
@ in place of cumbersome MOVs trashing the lo-registers twice. Thumb-1
@ does not permit ADD/SUB on hi-registers by an immediate, but it does
@ permit ADD/SUB from one hi-register to another.

.Lmemcpy:
	PUSH    {LR}
	MOV     R8, R2
	@ save the original value of R2 so it can be compared against later
	@ to properly pop the stack
	MOV     R10, R2
	CMP     R2, #24
	BLT     .Lcpybyword

.Lcpyby24:
	PUSH    {R4-R7}
	@ put the constant batch size (24 octets) into R9
	MOV     R2, #24
	MOV     R9, R2
	LDMIA   R1!, {R2-R7}
	STMIA   R0!, {R2-R7}
	ADD     R0, R9
	ADD     R1, R9
	@ ADD can do hi-registers but not SUB :/
	MOV     R2, R8
	SUB     R2, #24
	MOV     R8, R2
	CMP     R8, R9
	BGE     .Lcpyby24

	@ restore R2 as size before continuing as it was trashed
	MOV     R2, R8

.Lcpybyword:
	CMP     R2, #4
	BLT     .Lcpybybyte

.Lwordloop:
	LDR     R3, [R1]
	STR     R3, [R0]
	ADDS    R0, #4
	SUBS    R2, #4
	BGE     .Lwordloop

.Lcpybybyte:
	LDRB    R3, [R1]
	STRB    R3, [R0]
	ADDS    R0, #1
	SUBS    R2, #1
	BGE     .Lcpybybyte

.Lcpy_end:
	CMP     R10, R9
	BLT     .Lcpy_popend

	POP     {R4-R7}
.Lcpy_popend:
	POP     {PC}

.code 32
.balign 4, 0
.section text32

intr_main:
	ldr r3, =ld_io_start
	add r3, r3, 0x200
	ldr r2, [r3, IO_OFFS_IE - 0x200]
	ldrh r1, [r3, IO_OFFS_IME - 0x200]
	mrs r0, spsr
	stmdb sp!, {r0-r3,lr}
	mov r0, 1
	strh r0, [r3, IO_OFFS_IME - 0x200]
	and r1, r2, r2, lsr 16
	mov r12, 0
	ands r0, r1, IRQ_MASK_SERIAL
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, IRQ_MASK_TIMER3
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, IRQ_MASK_HBLANK
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, IRQ_MASK_VBLANK
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, IRQ_MASK_VCOUNT
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, IRQ_MASK_TIMER0
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, IRQ_MASK_TIMER1
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, IRQ_MASK_TIMER2
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, IRQ_MASK_DMA0
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, IRQ_MASK_DMA1
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, IRQ_MASK_DMA2
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, IRQ_MASK_DMA3
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, IRQ_MASK_KEYPAD
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, IRQ_MASK_GAMEPAK
	strbne r0, [r3, IO_OFFS_SOUNDCNT_X - 0x200]
.Lloop:
	bne .Lloop
.Lfoundintr:
	strh r0, [r3, IO_OFFS_IF - 0x200]
	mov r1, IRQ_MASK_SERIAL | IRQ_MASK_TIMER3 | IRQ_MASK_HBLANK
	bic r2, r2, r0
	and r1, r1, r2
	strh r1, [r3, IO_OFFS_IE - 0x200]
	mrs r3, cpsr
	bic r3, r3, PSR_I_BIT | PSR_F_BIT | PSR_MODE_MASK
	orr r3, r3, PSR_SYS_MODE
	msr cpsr_cf, r3
	ldr r1, =intr_table
	add r1, r1, r12
	ldr r0, [r1]
	stmdb sp!, {lr}
	adr lr, .Lretaddr
	bx r0
.Lretaddr:
	ldmia sp!, {lr}
	mrs r3, cpsr
	bic r3, r3, PSR_I_BIT | PSR_F_BIT | PSR_MODE_MASK
	orr r3, r3, PSR_I_BIT | PSR_IRQ_MODE
	msr cpsr_cf, r3
	ldmia sp!, {r0-r3,lr}
	strh r2, [r3, IO_OFFS_IE - 0x200]
	strh r1, [r3, IO_OFFS_IME - 0x200]
	msr spsr_cf, r0
	bx lr

.pool

.balign 4, 0 @ don't pad with nop.
