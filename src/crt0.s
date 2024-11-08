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
.globl intr_prior

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
	MOV     R0, PSR_IRQ_MODE
	MSR     CPSR, R0
	MOV     R0, #0x3000000
	MOV     R1, #0x7F00
	ORR     SP, R0, R1
	MOV     R0, PSR_SYS_MODE
	MSR     CPSR, R0
	MOV     R0, #0x3000000
	MOV     R1, #0x7D00
	ORR     SP, R0, R1

	@ branch to Thumb-1 since we're done MSRing
	ADD     R0, PC, #1
	BX      R0

.code 16
	@ turn off the display
	MOV     R0, #4      @
	LSL     R0, R0, #24 @ ~LDR R0, #0x4000000
	MOV     R1, #0x80
	STRH    R1, [R0]
	@ fix the waitcnt
	MOV     R1, #0x20
	LSL     R1, R1, #4
	ADD     R1, R1, #4
	ADD     R0, R0, R1
	MOV     R1, #0x43  @
	MOV     R2, #0x17  @
	LSL     R1, R1, #8 @
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

	@ load the interrupt routine
	MOV     R1, #4      @
	LSL     R1, R1, #24 @
	SUB     R1, #4      @ ~LDR #0x3FFFFFC
	@ #0x3FFFFFC is a mirror of #0x3007FFC
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

	@ restore R2 as the count before continuing as it was trashed
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

@ overview of the nichruby interrupt routine
@
@ - interrupts are not nesting
@
@ this assembly routine is stored in IWRAM at runtime and physically
@ handles interrupts.
@ it passes control to a fixed list of "core interrupt handlers" which
@ are known C routines corresponding to each kind of interrupt possible
@ on the GBA.
@ for sanity's sake, it switches to system mode (with system stack)
@ before branching into these routines.
@ these "core handlers" serve as the bridge to nichruby's higher-level
@ interrupt system, upon which the asynchronous event system of the
@ engine is built, including callbacks and so on.
@ this assembly routine will iterate through all "core handlers" for
@ each interrupt requested by the hardware, one by one, until all are
@ acknowledged.
@ additionally, it will prioritise which ones to handle first using the
@ values given in the intr_prior symbol, which is an array of u8s. 0 is
@ the highest priority and 255 is the lowest - it will iterate through
@ the whole list, handle all of the highest-priority ones, then the
@ next highest, and so on, until they are all clear. interrupts of the
@ same priority will be handled indeterminate relative to each other.

intr_main:
	PUSH    {R4-R5}
	MOV     R0, #0x4000000
	ADD     R0, R0, #0x200
	@ disable IME
	MOV     R1, #0
	STR     R1, [R0, #8]

.Lenumerate_irqs:
	@ load IE and IF
	LDRH    R1, [R0] @ IE
	LDRH    R2, [R0, #2] @ IF
	LDR     R3, =intr_prior
	MOV     R4, #0xFF @ current lowest active priority

.Lcheck_vblank:
	ANDS    R0, R1, IRQ_MASK_VBLANK
	BEQ     .Lcheck_hblank
	ANDS    R0, R2, IRQ_MASK_VBLANK
	BEQ     .Lcheck_hblank

	LDRB    R5, [R3, #0]
	CMP     R5, R4
	MOVLT   R4, R5 @ lower it if it is lower

.Lcheck_hblank:
	ANDS    R0, R1, IRQ_MASK_HBLANK
	BEQ     .Lcheck_vcount
	ANDS    R0, R2, IRQ_MASK_HBLANK
	BEQ     .Lcheck_vcount

	LDRB    R5, [R3, #1]
	CMP     R5, R4
	MOVLT   R4, R5 @ lower it if it is lower

.Lcheck_vcount:
	ANDS    R0, R1, IRQ_MASK_VCOUNT
	BEQ     .Lcheck_timer0
	ANDS    R0, R2, IRQ_MASK_VCOUNT
	BEQ     .Lcheck_timer0

	LDRB    R5, [R3, #2]
	CMP     R5, R4
	MOVLT   R4, R5 @ lower it if it is lower

.Lcheck_timer0:
	ANDS    R0, R1, IRQ_MASK_TIMER0
	BEQ     .Lcheck_timer1
	ANDS    R0, R2, IRQ_MASK_TIMER0
	BEQ     .Lcheck_timer1

	LDRB    R5, [R3, #3]
	CMP     R5, R4
	MOVLT   R4, R5 @ lower it if it is lower

.Lcheck_timer1:
	ANDS    R0, R1, IRQ_MASK_TIMER1
	BEQ     .Lcheck_timer2
	ANDS    R0, R2, IRQ_MASK_TIMER1
	BEQ     .Lcheck_timer2

	LDRB    R5, [R3, #4]
	CMP     R5, R4
	MOVLT   R4, R5 @ lower it if it is lower

.Lcheck_timer2:
	ANDS    R0, R1, IRQ_MASK_TIMER2
	BEQ     .Lcheck_timer3
	ANDS    R0, R2, IRQ_MASK_TIMER2
	BEQ     .Lcheck_timer3

	LDRB    R5, [R3, #5]
	CMP     R5, R4
	MOVLT   R4, R5 @ lower it if it is lower

.Lcheck_timer3:
	ANDS    R0, R1, IRQ_MASK_TIMER3
	BEQ     .Lcheck_serial
	ANDS    R0, R2, IRQ_MASK_TIMER3
	BEQ     .Lcheck_serial

	LDRB    R5, [R3, #6]
	CMP     R5, R4
	MOVLT   R4, R5 @ lower it if it is lower

.Lcheck_serial:
	ANDS    R0, R1, IRQ_MASK_SERIAL
	BEQ     .Lcheck_dma0
	ANDS    R0, R2, IRQ_MASK_SERIAL
	BEQ     .Lcheck_dma0

	LDRB    R5, [R3, #7]
	CMP     R5, R4
	MOVLT   R4, R5 @ lower it if it is lower

.Lcheck_dma0:
	ANDS    R0, R1, IRQ_MASK_DMA0
	BEQ     .Lcheck_dma1
	ANDS    R0, R2, IRQ_MASK_DMA0
	BEQ     .Lcheck_dma1

	LDRB    R5, [R3, #8]
	CMP     R5, R4
	MOVLT   R4, R5 @ lower it if it is lower

.Lcheck_dma1:
	ANDS    R0, R1, IRQ_MASK_DMA1
	BEQ     .Lcheck_dma2
	ANDS    R0, R2, IRQ_MASK_DMA1
	BEQ     .Lcheck_dma2

	LDRB    R5, [R3, #9]
	CMP     R5, R4
	MOVLT   R4, R5 @ lower it if it is lower

.Lcheck_dma2:
	ANDS    R0, R1, IRQ_MASK_DMA2
	BEQ     .Lcheck_dma3
	ANDS    R0, R2, IRQ_MASK_DMA2
	BEQ     .Lcheck_dma3

	LDR     R5, [R3, #10]
	CMP     R5, R4
	MOVLT   R4, R5 @ lower it if it is lower

.Lcheck_dma3:
	ANDS    R0, R1, IRQ_MASK_DMA3
	BEQ     .Lcheck_key
	ANDS    R0, R2, IRQ_MASK_DMA3
	BEQ     .Lcheck_key

	LDRB    R5, [R3, #11]
	CMP     R5, R4
	MOVLT   R4, R5 @ lower it if it is lower

.Lcheck_key:
	ANDS    R0, R1, IRQ_MASK_KEY
	BEQ     .Lcheck_gamepak
	ANDS    R0, R2, IRQ_MASK_KEY
	BEQ     .Lcheck_gamepak

	LDRB    R5, [R3, #12]
	CMP     R5, R4
	MOVLT   R4, R5 @ lower it if it is lower

.Lcheck_gamepak:
	ANDS    R0, R1, IRQ_MASK_GAMEPAK
	BEQ     .Lexec_vblank
	ANDS    R0, R2, IRQ_MASK_GAMEPAK
	BEQ     .Lexec_vblank

	LDRB    R5, [R3, #13]
	CMP     R5, R4
	MOVLT   R4, R5 @ lower it if it is lower

.Lexec_vblank:
	ANDS    R0, R1, IRQ_MASK_VBLANK
	BEQ     .Lexec_hblank
	ANDS    R0, R2, IRQ_MASK_VBLANK
	BEQ     .Lexec_hblank

	LDRB    R5, [R3, #0]
	CMP     R5, R4
	BNE     .Lexec_hblank

	LDR     R5, =intr_table
	CMP     R5, #0
	BXEQ    LR @ don't execute it if the handler is NULL

	@ save the old values of IME, SPSR, and LR for nesting IRQs
	MOV     R5, #0x4000000
	ADD     R5, R5, #0x200
	LDR     R0, [R5, #8] @ IME is now in R0
	MOV     R6, #0
	STR     R6, [R5, #8]

	MRS     R7, SPSR
	PUSH    {R0,R7,LR}

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
