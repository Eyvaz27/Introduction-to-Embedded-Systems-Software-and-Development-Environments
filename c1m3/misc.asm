	.syntax unified
	.cpu cortex-m4
	.eabi_attribute 27, 1
	.eabi_attribute 28, 1
	.fpu fpv4-sp-d16
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.thumb
	.file	"misc.c"
	.global	g5
	.data
	.align	2
	.type	g5, %object
	.size	g5, 40
g5:
	.word	0
	.word	1
	.word	2
	.word	3
	.word	4
	.word	5
	.word	6
	.word	7
	.word	8
	.word	9
	.section	.rodata
	.align	2
.LC0:
	.ascii	"Hello World!\012\000"
	.text
	.align	2
	.global	func
	.thumb
	.thumb_func
	.type	func, %function
func:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #20
	add	r7, sp, #0
	str	r0, [r7, #4]
	movs	r3, #0
	str	r3, [r7, #12]
	ldr	r3, .L5
	str	r3, [r7, #8]
	ldr	r3, .L5+4
	ldr	r3, [r3]
	adds	r3, r3, #1
	ldr	r2, .L5+4
	str	r3, [r2]
	ldr	r3, .L5+4
	ldr	r3, [r3]
	mov	r1, r3
	ldr	r3, [r7, #12]
	ldr	r2, .L5+8
	str	r3, [r2, r1, lsl #2]
	movs	r3, #0
	str	r3, [r7, #12]
	b	.L2
.L3:
	ldr	r2, [r7, #8]
	ldr	r3, [r7, #12]
	add	r3, r3, r2
	ldrb	r3, [r3]
	uxtb	r3, r3
	mov	r1, r3
	ldr	r2, .L5+8
	ldr	r3, [r7, #12]
	str	r1, [r2, r3, lsl #2]
	ldr	r3, .L5+4
	ldr	r3, [r3]
	adds	r3, r3, #1
	ldr	r2, .L5+4
	str	r3, [r2]
	ldr	r3, [r7, #12]
	adds	r3, r3, #1
	str	r3, [r7, #12]
.L2:
	ldr	r3, [r7, #12]
	cmp	r3, #5
	bls	.L3
	ldr	r3, .L5+4
	ldr	r3, [r3]
	mov	r0, r3
	adds	r7, r7, #20
	mov	sp, r7
	@ sp needed
	ldr	r7, [sp], #4
	bx	lr
.L6:
	.align	2
.L5:
	.word	.LC0
	.word	f2.4081
	.word	g5
	.size	func, .-func
	.bss
	.align	2
f2.4081:
	.space	4
	.ident	"GCC: (15:4.9.3+svn231177-1) 4.9.3 20150529 (prerelease)"
