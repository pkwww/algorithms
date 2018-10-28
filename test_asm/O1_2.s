	.text
	.file	"test.c"
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rax
.Ltmp0:
	.cfi_def_cfa_offset 16
	xorl	%eax, %eax
	xorl	%esi, %esi
	.align	16, 0x90
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	movl	%esi, %ecx
	movl	%eax, %esi
	andl	$1, %esi
	negl	%esi
	orl	$1, %esi
	addl	%ecx, %esi
	incl	%eax
	cmpl	$400000, %eax           # imm = 0x61A80
	jne	.LBB0_1
# BB#2:
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
