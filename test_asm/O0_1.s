	.text
	.file	"test.c"
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
.Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	$0, -12(%rbp)
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	cmpl	$400000, -12(%rbp)      # imm = 0x61A80
	jae	.LBB0_4
# BB#2:                                 #   in Loop: Header=BB0_1 Depth=1
	movl	$1, %eax
	movl	$4294967295, %ecx       # imm = 0xFFFFFFFF
	movl	-12(%rbp), %edx
	andl	$1, %edx
	cmpl	$0, %edx
	cmovnel	%ecx, %eax
	movl	-8(%rbp), %ecx
	addl	%eax, %ecx
	movl	%ecx, -8(%rbp)
# BB#3:                                 #   in Loop: Header=BB0_1 Depth=1
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	jmp	.LBB0_1
.LBB0_4:
	movabsq	$.L.str, %rdi
	movl	-8(%rbp), %esi
	movb	$0, %al
	callq	printf
	movl	$0, %esi
	movl	%eax, -16(%rbp)         # 4-byte Spill
	movl	%esi, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
.Ltmp3:
	.size	main, .Ltmp3-main
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"%d\n"
	.size	.L.str, 4


	.ident	"clang version 3.5.0 (tags/RELEASE_350/final)"
	.section	".note.GNU-stack","",@progbits
