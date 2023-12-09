
16:     file format elf64-x86-64


Disassembly of section .init:

0000000000000580 <_init>:
 580:	48 83 ec 08          	sub    $0x8,%rsp
 584:	48 8b 05 5d 0a 20 00 	mov    0x200a5d(%rip),%rax        # 200fe8 <__gmon_start__>
 58b:	48 85 c0             	test   %rax,%rax
 58e:	74 02                	je     592 <_init+0x12>
 590:	ff d0                	callq  *%rax
 592:	48 83 c4 08          	add    $0x8,%rsp
 596:	c3                   	retq   

Disassembly of section .plt:

00000000000005a0 <.plt>:
 5a0:	ff 35 0a 0a 20 00    	pushq  0x200a0a(%rip)        # 200fb0 <_GLOBAL_OFFSET_TABLE_+0x8>
 5a6:	ff 25 0c 0a 20 00    	jmpq   *0x200a0c(%rip)        # 200fb8 <_GLOBAL_OFFSET_TABLE_+0x10>
 5ac:	0f 1f 40 00          	nopl   0x0(%rax)

00000000000005b0 <__stack_chk_fail@plt>:
 5b0:	ff 25 0a 0a 20 00    	jmpq   *0x200a0a(%rip)        # 200fc0 <__stack_chk_fail@GLIBC_2.4>
 5b6:	68 00 00 00 00       	pushq  $0x0
 5bb:	e9 e0 ff ff ff       	jmpq   5a0 <.plt>

00000000000005c0 <printf@plt>:
 5c0:	ff 25 02 0a 20 00    	jmpq   *0x200a02(%rip)        # 200fc8 <printf@GLIBC_2.2.5>
 5c6:	68 01 00 00 00       	pushq  $0x1
 5cb:	e9 d0 ff ff ff       	jmpq   5a0 <.plt>

00000000000005d0 <scanf@plt>:
 5d0:	ff 25 fa 09 20 00    	jmpq   *0x2009fa(%rip)        # 200fd0 <scanf@GLIBC_2.2.5>
 5d6:	68 02 00 00 00       	pushq  $0x2
 5db:	e9 c0 ff ff ff       	jmpq   5a0 <.plt>

Disassembly of section .plt.got:

00000000000005e0 <__cxa_finalize@plt>:
 5e0:	ff 25 12 0a 20 00    	jmpq   *0x200a12(%rip)        # 200ff8 <__cxa_finalize@GLIBC_2.2.5>
 5e6:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

00000000000005f0 <_start>:
 5f0:	31 ed                	xor    %ebp,%ebp
 5f2:	49 89 d1             	mov    %rdx,%r9
 5f5:	5e                   	pop    %rsi
 5f6:	48 89 e2             	mov    %rsp,%rdx
 5f9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
 5fd:	50                   	push   %rax
 5fe:	54                   	push   %rsp
 5ff:	4c 8d 05 3a 02 00 00 	lea    0x23a(%rip),%r8        # 840 <__libc_csu_fini>
 606:	48 8d 0d c3 01 00 00 	lea    0x1c3(%rip),%rcx        # 7d0 <__libc_csu_init>
 60d:	48 8d 3d 11 01 00 00 	lea    0x111(%rip),%rdi        # 725 <main>
 614:	ff 15 c6 09 20 00    	callq  *0x2009c6(%rip)        # 200fe0 <__libc_start_main@GLIBC_2.2.5>
 61a:	f4                   	hlt    
 61b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000000620 <deregister_tm_clones>:
 620:	48 8d 3d f1 09 20 00 	lea    0x2009f1(%rip),%rdi        # 201018 <__TMC_END__>
 627:	55                   	push   %rbp
 628:	48 8d 05 e9 09 20 00 	lea    0x2009e9(%rip),%rax        # 201018 <__TMC_END__>
 62f:	48 39 f8             	cmp    %rdi,%rax
 632:	48 89 e5             	mov    %rsp,%rbp
 635:	74 19                	je     650 <deregister_tm_clones+0x30>
 637:	48 8b 05 9a 09 20 00 	mov    0x20099a(%rip),%rax        # 200fd8 <_ITM_deregisterTMCloneTable>
 63e:	48 85 c0             	test   %rax,%rax
 641:	74 0d                	je     650 <deregister_tm_clones+0x30>
 643:	5d                   	pop    %rbp
 644:	ff e0                	jmpq   *%rax
 646:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 64d:	00 00 00 
 650:	5d                   	pop    %rbp
 651:	c3                   	retq   
 652:	0f 1f 40 00          	nopl   0x0(%rax)
 656:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 65d:	00 00 00 

0000000000000660 <register_tm_clones>:
 660:	48 8d 3d b1 09 20 00 	lea    0x2009b1(%rip),%rdi        # 201018 <__TMC_END__>
 667:	48 8d 35 aa 09 20 00 	lea    0x2009aa(%rip),%rsi        # 201018 <__TMC_END__>
 66e:	55                   	push   %rbp
 66f:	48 29 fe             	sub    %rdi,%rsi
 672:	48 89 e5             	mov    %rsp,%rbp
 675:	48 c1 fe 03          	sar    $0x3,%rsi
 679:	48 89 f0             	mov    %rsi,%rax
 67c:	48 c1 e8 3f          	shr    $0x3f,%rax
 680:	48 01 c6             	add    %rax,%rsi
 683:	48 d1 fe             	sar    %rsi
 686:	74 18                	je     6a0 <register_tm_clones+0x40>
 688:	48 8b 05 61 09 20 00 	mov    0x200961(%rip),%rax        # 200ff0 <_ITM_registerTMCloneTable>
 68f:	48 85 c0             	test   %rax,%rax
 692:	74 0c                	je     6a0 <register_tm_clones+0x40>
 694:	5d                   	pop    %rbp
 695:	ff e0                	jmpq   *%rax
 697:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
 69e:	00 00 
 6a0:	5d                   	pop    %rbp
 6a1:	c3                   	retq   
 6a2:	0f 1f 40 00          	nopl   0x0(%rax)
 6a6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 6ad:	00 00 00 

00000000000006b0 <__do_global_dtors_aux>:
 6b0:	80 3d 5d 09 20 00 00 	cmpb   $0x0,0x20095d(%rip)        # 201014 <completed.7697>
 6b7:	75 2f                	jne    6e8 <__do_global_dtors_aux+0x38>
 6b9:	48 83 3d 37 09 20 00 	cmpq   $0x0,0x200937(%rip)        # 200ff8 <__cxa_finalize@GLIBC_2.2.5>
 6c0:	00 
 6c1:	55                   	push   %rbp
 6c2:	48 89 e5             	mov    %rsp,%rbp
 6c5:	74 0c                	je     6d3 <__do_global_dtors_aux+0x23>
 6c7:	48 8b 3d 3a 09 20 00 	mov    0x20093a(%rip),%rdi        # 201008 <__dso_handle>
 6ce:	e8 0d ff ff ff       	callq  5e0 <__cxa_finalize@plt>
 6d3:	e8 48 ff ff ff       	callq  620 <deregister_tm_clones>
 6d8:	c6 05 35 09 20 00 01 	movb   $0x1,0x200935(%rip)        # 201014 <completed.7697>
 6df:	5d                   	pop    %rbp
 6e0:	c3                   	retq   
 6e1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
 6e8:	f3 c3                	repz retq 
 6ea:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000006f0 <frame_dummy>:
 6f0:	55                   	push   %rbp
 6f1:	48 89 e5             	mov    %rsp,%rbp
 6f4:	5d                   	pop    %rbp
 6f5:	e9 66 ff ff ff       	jmpq   660 <register_tm_clones>

00000000000006fa <_Z1fi>:
 6fa:	55                   	push   %rbp
 6fb:	48 89 e5             	mov    %rsp,%rbp
 6fe:	89 7d ec             	mov    %edi,-0x14(%rbp)
 701:	c7 45 f8 01 00 00 00 	movl   $0x1,-0x8(%rbp)
 708:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
 70f:	8b 45 fc             	mov    -0x4(%rbp),%eax
 712:	3b 45 ec             	cmp    -0x14(%rbp),%eax
 715:	7f 09                	jg     720 <_Z1fi+0x26>
 717:	d1 65 f8             	shll   -0x8(%rbp)
 71a:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
 71e:	eb ef                	jmp    70f <_Z1fi+0x15>
 720:	8b 45 f8             	mov    -0x8(%rbp),%eax
 723:	5d                   	pop    %rbp
 724:	c3                   	retq   

0000000000000725 <main>:
 725:	55                   	push   %rbp
 726:	48 89 e5             	mov    %rsp,%rbp
 729:	48 83 ec 20          	sub    $0x20,%rsp
 72d:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
 734:	00 00 
 736:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
 73a:	31 c0                	xor    %eax,%eax
 73c:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%rbp)
 743:	48 8d 3d 0a 01 00 00 	lea    0x10a(%rip),%rdi        # 854 <_IO_stdin_used+0x4>
 74a:	b8 00 00 00 00       	mov    $0x0,%eax
 74f:	e8 6c fe ff ff       	callq  5c0 <printf@plt>
 754:	48 8d 45 ec          	lea    -0x14(%rbp),%rax
 758:	48 89 c6             	mov    %rax,%rsi
 75b:	48 8d 3d fc 00 00 00 	lea    0xfc(%rip),%rdi        # 85e <_IO_stdin_used+0xe>
 762:	b8 00 00 00 00       	mov    $0x0,%eax
 767:	e8 64 fe ff ff       	callq  5d0 <scanf@plt>
 76c:	c7 45 f4 01 00 00 00 	movl   $0x1,-0xc(%rbp)
 773:	8b 45 ec             	mov    -0x14(%rbp),%eax
 776:	39 45 f4             	cmp    %eax,-0xc(%rbp)
 779:	7f 22                	jg     79d <main+0x78>
 77b:	8b 45 f4             	mov    -0xc(%rbp),%eax
 77e:	89 c7                	mov    %eax,%edi
 780:	e8 75 ff ff ff       	callq  6fa <_Z1fi>
 785:	01 45 f0             	add    %eax,-0x10(%rbp)
 788:	8b 0d 82 08 20 00    	mov    0x200882(%rip),%ecx        # 201010 <mod>
 78e:	8b 45 f0             	mov    -0x10(%rbp),%eax
 791:	99                   	cltd   
 792:	f7 f9                	idiv   %ecx
 794:	89 55 f0             	mov    %edx,-0x10(%rbp)
 797:	83 45 f4 01          	addl   $0x1,-0xc(%rbp)
 79b:	eb d6                	jmp    773 <main+0x4e>
 79d:	8b 45 f0             	mov    -0x10(%rbp),%eax
 7a0:	89 c6                	mov    %eax,%esi
 7a2:	48 8d 3d b8 00 00 00 	lea    0xb8(%rip),%rdi        # 861 <_IO_stdin_used+0x11>
 7a9:	b8 00 00 00 00       	mov    $0x0,%eax
 7ae:	e8 0d fe ff ff       	callq  5c0 <printf@plt>
 7b3:	b8 00 00 00 00       	mov    $0x0,%eax
 7b8:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
 7bc:	64 48 33 14 25 28 00 	xor    %fs:0x28,%rdx
 7c3:	00 00 
 7c5:	74 05                	je     7cc <main+0xa7>
 7c7:	e8 e4 fd ff ff       	callq  5b0 <__stack_chk_fail@plt>
 7cc:	c9                   	leaveq 
 7cd:	c3                   	retq   
 7ce:	66 90                	xchg   %ax,%ax

00000000000007d0 <__libc_csu_init>:
 7d0:	41 57                	push   %r15
 7d2:	41 56                	push   %r14
 7d4:	49 89 d7             	mov    %rdx,%r15
 7d7:	41 55                	push   %r13
 7d9:	41 54                	push   %r12
 7db:	4c 8d 25 c6 05 20 00 	lea    0x2005c6(%rip),%r12        # 200da8 <__frame_dummy_init_array_entry>
 7e2:	55                   	push   %rbp
 7e3:	48 8d 2d c6 05 20 00 	lea    0x2005c6(%rip),%rbp        # 200db0 <__do_global_dtors_aux_fini_array_entry>
 7ea:	53                   	push   %rbx
 7eb:	41 89 fd             	mov    %edi,%r13d
 7ee:	49 89 f6             	mov    %rsi,%r14
 7f1:	4c 29 e5             	sub    %r12,%rbp
 7f4:	48 83 ec 08          	sub    $0x8,%rsp
 7f8:	48 c1 fd 03          	sar    $0x3,%rbp
 7fc:	e8 7f fd ff ff       	callq  580 <_init>
 801:	48 85 ed             	test   %rbp,%rbp
 804:	74 20                	je     826 <__libc_csu_init+0x56>
 806:	31 db                	xor    %ebx,%ebx
 808:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
 80f:	00 
 810:	4c 89 fa             	mov    %r15,%rdx
 813:	4c 89 f6             	mov    %r14,%rsi
 816:	44 89 ef             	mov    %r13d,%edi
 819:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
 81d:	48 83 c3 01          	add    $0x1,%rbx
 821:	48 39 dd             	cmp    %rbx,%rbp
 824:	75 ea                	jne    810 <__libc_csu_init+0x40>
 826:	48 83 c4 08          	add    $0x8,%rsp
 82a:	5b                   	pop    %rbx
 82b:	5d                   	pop    %rbp
 82c:	41 5c                	pop    %r12
 82e:	41 5d                	pop    %r13
 830:	41 5e                	pop    %r14
 832:	41 5f                	pop    %r15
 834:	c3                   	retq   
 835:	90                   	nop
 836:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 83d:	00 00 00 

0000000000000840 <__libc_csu_fini>:
 840:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000000844 <_fini>:
 844:	48 83 ec 08          	sub    $0x8,%rsp
 848:	48 83 c4 08          	add    $0x8,%rsp
 84c:	c3                   	retq   
#include <stdio.h>

void f(int n) {
    int i = 1;
    int result = 1;
    
    while (i <= n) {
        result *= i;
        i++;
    }
    
    printf("Factorial of %d is %d\n", n, result);
}

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    f(num);
    
    return 0;
}
