@ -*- coding: utf-8 -*-
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@       __   _ _____ _______ _     _  ______ _     _ ______  __   __       @@
@@       | \  |   |   |       |_____| |_____/ |     | |_____]   \_/         @@
@@       |  \_| __|__ |_____  |     | |    \_ |_____| |_____]    |          @@
@@                                 nichruby                                 @@
@@                                                                          @@
@@                    Copyright © 2020 Alexander Nicholi                    @@
@@                       Released under BSD-2-Clause.                       @@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

@ DEFINITION MODULE

.include "const/gba.s"
.include "const/misc.s"
.include "const/ver.s"

.syntax unified

.globl start
.globl rh_nintenpic
.globl gpio_portdata
.globl gpio_portdir
.globl gpio_portreadable
.globl init
.globl intr_main
.globl main
.globl intr_table

.text
.arm

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


@ TODO: figure out what this data is

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
	.ascii "AXVE"
	.ascii "pokemon ruby version"
	.4byte     0x1220
	.4byte     0x1340
	.4byte       0x18
	.4byte      0x938
	.4byte     0x3A8C
	.4byte       0x46
	.4byte      0x836
	.4byte      0x84C
	.4byte      0x182
	.4byte  0xA0A0A07
	.4byte  0xC060C0C
	.4byte  0xC121006
	.4byte  0x8010B0F
	.4byte        0xC
	.4byte      0x890
	.4byte     0x3AC0
	.4byte      0x234
	.4byte      0x238
	.4byte          9
	.4byte        0xA
	.4byte          0
	.4byte          8
	.4byte      0x556
	.4byte      0x557
	.4byte     0x312F
	.4byte     0x311B
	.4byte          0
	.4byte          0
	.4byte          0
	.4byte          0
	.4byte          0
	.4byte          0
	.4byte          0
	.4byte          0
	.4byte          0
	.4byte          0
	.4byte          0
	.4byte          0
	.4byte          0
	.4byte          0
	.4byte          0
	.4byte          0
	.4byte          0
	.4byte          0
	.4byte 0xFFFFFFFF

	.arm
	.balign 4, 0
init:
	mov r0, PSR_IRQ_MODE
	msr cpsr_cf, r0
	ldr sp, sp_irq
	mov r0, PSR_SYS_MODE
	msr cpsr_cf, r0
	ldr sp, sp_sys
	ldr r1, =INTR_VECTOR
	adr r0, intr_main
	str r0, [r1]
	ldr r1, =main
	mov lr, pc
	bx r1
	b init

	.balign 4, 0
sp_sys: .word IWRAM_END - 0x1a0
sp_irq: .word IWRAM_END - 0x60

	.arm
	.balign 4, 0
intr_main:
	mov r3, REG_BASE
	add r3, r3, 0x200
	ldr r2, [r3, OFFSET_REG_IE - 0x200]
	ldrh r1, [r3, OFFSET_REG_IME - 0x200]
	mrs r0, spsr
	stmdb sp!, {r0-r3,lr}
	mov r0, 1
	strh r0, [r3, OFFSET_REG_IME - 0x200]
	and r1, r2, r2, lsr 16
	mov r12, 0
	ands r0, r1, INTR_FLAG_SERIAL
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_TIMER3
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_HBLANK
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_VBLANK
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_VCOUNT
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_TIMER0
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_TIMER1
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_TIMER2
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_DMA0
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_DMA1
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_DMA2
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_DMA3
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_KEYPAD
	bne .Lfoundintr
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_GAMEPAK
	strbne r0, [r3, OFFSET_REG_SOUNDCNT_X - 0x200]
.Lloop:
	bne .Lloop
.Lfoundintr:
	strh r0, [r3, OFFSET_REG_IF - 0x200]
	mov r1, INTR_FLAG_SERIAL | INTR_FLAG_TIMER3 | INTR_FLAG_HBLANK
	bic r2, r2, r0
	and r1, r1, r2
	strh r1, [r3, OFFSET_REG_IE - 0x200]
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
	strh r2, [r3, OFFSET_REG_IE - 0x200]
	strh r1, [r3, OFFSET_REG_IME - 0x200]
	msr spsr_cf, r0
	bx lr

	.pool

	.balign 4, 0 @ don’t pad with nop.
