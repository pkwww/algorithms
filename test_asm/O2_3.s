	.text
	.file	"test.c"
	.section	.rodata.cst16,"aM",@progbits,16
	.align	16
.LCPI0_0:
	.long	0                       # 0x0
	.long	1                       # 0x1
	.long	2                       # 0x2
	.long	3                       # 0x3
.LCPI0_1:
	.long	4                       # 0x4
	.long	5                       # 0x5
	.long	6                       # 0x6
	.long	7                       # 0x7
.LCPI0_2:
	.long	2                       # 0x2
	.long	2                       # 0x2
	.long	2                       # 0x2
	.long	2                       # 0x2
	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:                                 # %overflow.checked
	pushq	%rax
.Ltmp0:
	.cfi_def_cfa_offset 16
	pxor	%xmm0, %xmm0
	xorl	%eax, %eax
	movdqa	.LCPI0_0(%rip), %xmm2
	movdqa	.LCPI0_1(%rip), %xmm3
	movdqa	.LCPI0_2(%rip), %xmm4
	pcmpeqd	%xmm5, %xmm5
	pxor	%xmm1, %xmm1
	.align	16, 0x90
.LBB0_1:                                # %vector.body
                                        # =>This Inner Loop Header: Depth=1
	movd	%eax, %xmm6
	pshufd	$0, %xmm6, %xmm6        # xmm6 = xmm6[0,0,0,0]
	movdqa	%xmm6, %xmm7
	paddd	%xmm2, %xmm7
	paddd	%xmm3, %xmm6
	paddd	%xmm7, %xmm7
	paddd	%xmm6, %xmm6
	pand	%xmm4, %xmm7
	pand	%xmm4, %xmm6
	paddd	%xmm7, %xmm0
	paddd	%xmm6, %xmm1
	paddd	%xmm5, %xmm0
	paddd	%xmm5, %xmm1
	addl	$8, %eax
	cmpl	$400000, %eax           # imm = 0x61A80
	jne	.LBB0_1
# BB#2:                                 # %middle.block
	paddd	%xmm0, %xmm1
	movdqa	%xmm1, %xmm0
	movhlps	%xmm0, %xmm0            # xmm0 = xmm0[1,1]
	paddd	%xmm1, %xmm0
	pshufd	$1, %xmm0, %xmm1        # xmm1 = xmm0[1,0,0,0]
	paddd	%xmm0, %xmm1
	movd	%xmm1, %esi
	movl	$.L.str, %edi
	xorl	%eax, %eax
	callq	printf
	xorl	%eax, %eax
	popq	%rdx
	retq
.Ltmp1:
	.size	main, .Ltmp1-main
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"%d\n"
	.size	.L.str, 4


	.ident	"clang version 3.5.0 (tags/RELEASE_350/final)"
	.section	".note.GNU-stack","",@progbits
