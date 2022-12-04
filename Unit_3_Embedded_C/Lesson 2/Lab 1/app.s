
app.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	e92d4800 	push	{fp, lr}
   4:	e28db004 	add	fp, sp, #4
   8:	e59f0004 	ldr	r0, [pc, #4]	; 14 <main+0x14>
   c:	ebfffffe 	bl	0 <Uart_Send_string>
  10:	e8bd8800 	pop	{fp, pc}
  14:	00000000 	andeq	r0, r0, r0

Disassembly of section .data:

00000000 <string_buffer>:
   0:	7261656c 	rsbvc	r6, r1, #108, 10	; 0x1b000000
   4:	6e692d6e 	cdpvs	13, 6, cr2, cr9, cr14, {3}
   8:	7065642d 	rsbvc	r6, r5, sp, lsr #8
   c:	3c3a6874 	ldccc	8, cr6, [sl], #-464	; 0xfffffe30
  10:	61726249 	cmnvs	r2, r9, asr #4
  14:	3e6d6968 	cdpcc	9, 6, cr6, cr13, cr8, {3}
	...

Disassembly of section .rodata:

00000000 <string_buffer_2>:
   0:	63206f74 	teqvs	r0, #116, 30	; 0x1d0
   4:	74616572 	strbtvc	r6, [r1], #-1394	; 0x572
   8:	20612065 	rsbcs	r2, r1, r5, rrx
   c:	61646f72 	smcvs	18162	; 0x46f2
  10:	73206174 	teqvc	r0, #116, 2
  14:	69746365 	ldmdbvs	r4!, {r0, r2, r5, r6, r8, r9, sp, lr}^
  18:	00006e6f 	andeq	r6, r0, pc, ror #28
	...

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	0000007f 	andeq	r0, r0, pc, ror r0
   4:	00000002 	andeq	r0, r0, r2
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	00000017 	andeq	r0, r0, r7, lsl r0
  10:	00009001 	andeq	r9, r0, r1
  14:	00003300 	andeq	r3, r0, r0, lsl #6
  18:	00000000 	andeq	r0, r0, r0
  1c:	00001800 	andeq	r1, r0, r0, lsl #16
  20:	00000000 	andeq	r0, r0, r0
  24:	a4010200 	strge	r0, [r1], #-512	; 0x200
  28:	01000000 	mrseq	r0, (UNDEF: 0)
  2c:	00000104 	andeq	r0, r0, r4, lsl #2
  30:	00180000 	andseq	r0, r8, r0
  34:	00000000 	andeq	r0, r0, r0
  38:	03010000 	movweq	r0, #4096	; 0x1000
  3c:	00000052 	andeq	r0, r0, r2, asr r0
  40:	0000004b 	andeq	r0, r0, fp, asr #32
  44:	00004b04 	andeq	r4, r0, r4, lsl #22
  48:	05006300 	streq	r6, [r0, #-768]	; 0x300
  4c:	000e0704 	andeq	r0, lr, r4, lsl #14
  50:	01050000 	mrseq	r0, (UNDEF: 5)
  54:	00000008 	andeq	r0, r0, r8
  58:	00960600 	addseq	r0, r6, r0, lsl #12
  5c:	02010000 	andeq	r0, r1, #0
  60:	0000003b 	andeq	r0, r0, fp, lsr r0
  64:	00030501 	andeq	r0, r3, r1, lsl #10
  68:	06000000 	streq	r0, [r0], -r0
  6c:	00000023 	andeq	r0, r0, r3, lsr #32
  70:	007d0301 	rsbseq	r0, sp, r1, lsl #6
  74:	05010000 	streq	r0, [r1, #-0]
  78:	00000003 	andeq	r0, r0, r3
  7c:	003b0700 	eorseq	r0, fp, r0, lsl #14
  80:	Address 0x00000080 is out of bounds.


Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0x101
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10011201 	andne	r1, r1, r1, lsl #4
  10:	02000006 	andeq	r0, r0, #6
  14:	0c3f002e 	ldceq	0, cr0, [pc], #-184	; ffffff64 <main+0xffffff64>
  18:	0b3a0e03 	bleq	e8382c <main+0xe8382c>
  1c:	0c270b3b 	stceq	11, cr0, [r7], #-236	; 0xffffff14
  20:	01120111 	tsteq	r2, r1, lsl r1
  24:	42960640 	addsmi	r0, r6, #64, 12	; 0x4000000
  28:	0300000c 	movweq	r0, #12
  2c:	13490101 	movtne	r0, #37121	; 0x9101
  30:	00001301 	andeq	r1, r0, r1, lsl #6
  34:	49002104 	stmdbmi	r0, {r2, r8, sp}
  38:	000b2f13 	andeq	r2, fp, r3, lsl pc
  3c:	00240500 	eoreq	r0, r4, r0, lsl #10
  40:	0b3e0b0b 	bleq	f82c74 <main+0xf82c74>
  44:	00000e03 	andeq	r0, r0, r3, lsl #28
  48:	03003406 	movweq	r3, #1030	; 0x406
  4c:	3b0b3a0e 	blcc	2ce88c <main+0x2ce88c>
  50:	3f13490b 	svccc	0x0013490b
  54:	000a020c 	andeq	r0, sl, ip, lsl #4
  58:	00260700 	eoreq	r0, r6, r0, lsl #14
  5c:	00001349 	andeq	r1, r0, r9, asr #6
	...

Disassembly of section .debug_loc:

00000000 <.debug_loc>:
   0:	00000000 	andeq	r0, r0, r0
   4:	00000004 	andeq	r0, r0, r4
   8:	007d0002 	rsbseq	r0, sp, r2
   c:	00000004 	andeq	r0, r0, r4
  10:	00000008 	andeq	r0, r0, r8
  14:	087d0002 	ldmdaeq	sp!, {r1}^
  18:	00000008 	andeq	r0, r0, r8
  1c:	00000018 	andeq	r0, r0, r8, lsl r0
  20:	047b0002 	ldrbteq	r0, [fp], #-2
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
	...
  14:	00000018 	andeq	r0, r0, r8, lsl r0
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	00000031 	andeq	r0, r0, r1, lsr r0
   4:	001c0002 	andseq	r0, ip, r2
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	00010000 	andeq	r0, r1, r0
  1c:	2e707061 	cdpcs	0, 7, cr7, cr0, cr1, {3}
  20:	00000063 	andeq	r0, r0, r3, rrx
  24:	05000000 	streq	r0, [r0, #-0]
  28:	00000002 	andeq	r0, r0, r2
  2c:	4b4c1600 	blmi	1305834 <main+0x1305834>
  30:	01000402 	tsteq	r0, r2, lsl #8
  34:	Address 0x00000034 is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
   4:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xe67
   8:	61686320 	cmnvs	r8, r0, lsr #6
   c:	69730072 	ldmdbvs	r3!, {r1, r4, r5, r6}^
  10:	7974657a 	ldmdbvc	r4!, {r1, r3, r4, r5, r6, r8, sl, sp, lr}^
  14:	47006570 	smlsdxmi	r0, r0, r5, r6
  18:	4320554e 	teqmi	r0, #327155712	; 0x13800000
  1c:	372e3420 	strcc	r3, [lr, -r0, lsr #8]!
  20:	7300322e 	movwvc	r3, #558	; 0x22e
  24:	6e697274 	mcrvs	2, 3, r7, cr9, cr4, {3}
  28:	75625f67 	strbvc	r5, [r2, #-3943]!	; 0xf67
  2c:	72656666 	rsbvc	r6, r5, #106954752	; 0x6600000
  30:	4500325f 	strmi	r3, [r0, #-607]	; 0x25f
  34:	74735c3a 	ldrbtvc	r5, [r3], #-3130	; 0xc3a
  38:	5c796475 	cfldrdpl	mvd6, [r9], #-468	; 0xfffffe2c
  3c:	63656c65 	cmnvs	r5, #25856	; 0x6500
  40:	63697274 	cmnvs	r9, #116, 4	; 0x40000007
  44:	532e455c 	teqpl	lr, #92, 10	; 0x17000000
  48:	532e4b5f 	teqpl	lr, #97280	; 0x17c00
  4c:	646f435c 	strbtvs	r4, [pc], #-860	; 54 <.debug_str+0x54>
  50:	614d5c65 	cmpvs	sp, r5, ror #24
  54:	72657473 	rsbvc	r7, r5, #1929379840	; 0x73000000
  58:	626d452d 	rsbvs	r4, sp, #188743680	; 0xb400000
  5c:	65646465 	strbvs	r6, [r4, #-1125]!	; 0x465
  60:	79532d64 	ldmdbvc	r3, {r2, r5, r6, r8, sl, fp, sp}^
  64:	6d657473 	cfstrdvs	mvd7, [r5, #-460]!	; 0xfffffe34
  68:	2e4b2d73 	mcrcs	13, 2, r2, cr11, cr3, {3}
  6c:	555c2d53 	ldrbpl	r2, [ip, #-3411]	; 0xd53
  70:	5f74696e 	svcpl	0x0074696e
  74:	6d455f33 	stclvs	15, cr5, [r5, #-204]	; 0xffffff34
  78:	64646562 	strbtvs	r6, [r4], #-1378	; 0x562
  7c:	435f6465 	cmpmi	pc, #1694498816	; 0x65000000
  80:	73654c5c 	cmnvc	r5, #92, 24	; 0x5c00
  84:	206e6f73 	rsbcs	r6, lr, r3, ror pc
  88:	614c5c32 	cmpvs	ip, r2, lsr ip
  8c:	00312062 	eorseq	r2, r1, r2, rrx
  90:	2e707061 	cdpcs	0, 7, cr7, cr0, cr1, {3}
  94:	74730063 	ldrbtvc	r0, [r3], #-99	; 0x63
  98:	676e6972 			; <UNDEFINED> instruction: 0x676e6972
  9c:	6675625f 			; <UNDEFINED> instruction: 0x6675625f
  a0:	00726566 	rsbseq	r6, r2, r6, ror #10
  a4:	6e69616d 	powvsez	f6, f1, #5.0
	...

Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	4728203a 			; <UNDEFINED> instruction: 0x4728203a
   8:	2029554e 	eorcs	r5, r9, lr, asr #10
   c:	2e372e34 	mrccs	14, 1, r2, cr7, cr4, {1}
  10:	Address 0x00000010 is out of bounds.


Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00003141 	andeq	r3, r0, r1, asr #2
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000027 	andeq	r0, r0, r7, lsr #32
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	45363239 	ldrmi	r3, [r6, #-569]!	; 0x239
  18:	00532d4a 	subseq	r2, r3, sl, asr #26
  1c:	01080506 	tsteq	r8, r6, lsl #10
  20:	04120109 	ldreq	r0, [r2], #-265	; 0x109
  24:	01150114 	tsteq	r5, r4, lsl r1
  28:	01180317 	tsteq	r8, r7, lsl r3
  2c:	011a0119 	tsteq	sl, r9, lsl r1
  30:	Address 0x00000030 is out of bounds.


Disassembly of section .debug_frame:

00000000 <.debug_frame>:
   0:	0000000c 	andeq	r0, r0, ip
   4:	ffffffff 			; <UNDEFINED> instruction: 0xffffffff
   8:	7c020001 	stcvc	0, cr0, [r2], {1}
   c:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  10:	00000018 	andeq	r0, r0, r8, lsl r0
	...
  1c:	00000018 	andeq	r0, r0, r8, lsl r0
  20:	8b080e42 	blhi	203930 <main+0x203930>
  24:	42018e02 	andmi	r8, r1, #2, 28
  28:	00040b0c 	andeq	r0, r4, ip, lsl #22
