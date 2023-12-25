                             //
                             // segment_2.1 
                             // Loadable segment  [0x0 - 0x9df] (disabled execute bit)
                             // ram:00100000-ram:00100237
                             //
             assume DF = 0x0  (Default)
        00100000 7f 45 4c        Elf64_Ehdr
                 46 02 01 
                 01 00 00 
           00100000 7f              db        7Fh                     e_ident_magi
           00100001 45 4c 46        ds        "ELF"                   e_ident_magi
           00100004 02              db        2h                      e_ident_class
           00100005 01              db        1h                      e_ident_data
           00100006 01              db        1h                      e_ident_vers
           00100007 00              db        0h                      e_ident_osabi
           00100008 00              db        0h                      e_ident_abiv
           00100009 00 00 00 00 00  db[7]                             e_ident_pad
                    00 00
           00100010 03 00           dw        3h                      e_type
           00100012 3e 00           dw        3Eh                     e_machine
           00100014 01 00 00 00     ddw       1h                      e_version
           00100018 f0 05 00 00 00  dq        _start                  e_entry
                    00 00 00
           00100020 40 00 00 00 00  dq        Elf64_Phdr_ARRAY_00100  e_phoff
                    00 00 00
           00100028 c8 19 00 00 00  dq        Elf64_Shdr_ARRAY__elfS  e_shoff
                    00 00 00
           00100030 00 00 00 00     ddw       0h                      e_flags
           00100034 40 00           dw        40h                     e_ehsize
           00100036 38 00           dw        38h                     e_phentsize
           00100038 09 00           dw        9h                      e_phnum
           0010003a 40 00           dw        40h                     e_shentsize
           0010003c 1d 00           dw        1Dh                     e_shnum
           0010003e 1c 00           dw        1Ch                     e_shstrndx
                             Elf64_Phdr_ARRAY_00100040                       XREF[2]:     00100020(*), 00100050(*)  
        00100040 06 00 00        Elf64_Ph                                                    PT_PHDR - Program header table
                 00 04 00 
                 00 00 40 
                             //
                             // .interp 
                             // SHT_PROGBITS  [0x238 - 0x253]
                             // ram:00100238-ram:00100253
                             //
                             s_/lib64/ld-linux-x86-64.so.2_00100238          XREF[2]:     00100088(*), 
                                                                                          _elfSectionHeaders::00000050(*)  
        00100238 2f 6c 69        ds         "/lib64/ld-linux-x86-64.so.2"                    Initial Elf program interpreter
                 62 36 34 
                 2f 6c 64 
                             //
                             // .note.ABI-tag 
                             // SHT_NOTE  [0x254 - 0x273]
                             // ram:00100254-ram:00100273
                             //
                             NoteAbiTag_00100254                             XREF[2]:     00100168(*), 
                                                                                          _elfSectionHeaders::00000090(*)  
        00100254 04 00 00        NoteAbiTag                                                  Length of name field
                 00 10 00 
                 00 00 01 
                             //
                             // .note.gnu.build-id 
                             // SHT_NOTE  [0x274 - 0x297]
                             // ram:00100274-ram:00100297
                             //
                             GnuBuildId_00100274                             XREF[1]:     _elfSectionHeaders::000000d0(*)  
        00100274 04 00 00        GnuBuildId                                                  Length of name field
                 00 14 00 
                 00 00 03 
                             //
                             // .gnu.hash 
                             // SHT_GNU_HASH  [0x298 - 0x2b3]
                             // ram:00100298-ram:001002b3
                             //
                             __DT_GNU_HASH                                   XREF[2]:     00300e30(*), 
                                                                                          _elfSectionHeaders::00000110(*)  
        00100298 01 00 00 00     ddw        1h                                               GNU Hash Table - nbucket
        0010029c 01 00 00 00     ddw        1h                                               GNU Hash Table - symbase
        001002a0 01 00 00 00     ddw        1h                                               GNU Hash Table - bloom_size
        001002a4 00 00 00 00     ddw        0h                                               GNU Hash Table - bloom_shift
        001002a8 00 00 00        dq[1]                                                       GNU Hash Table - bloom
                 00 00 00 
                 00 00
        001002b0 00 00 00 00     ddw[1]                                                      GNU Hash Table - buckets
                             //
                             // .dynsym 
                             // SHT_DYNSYM  [0x2b8 - 0x38f]
                             // ram:001002b8-ram:0010038f
                             //
                             __DT_SYMTAB                                     XREF[2]:     00300e50(*), 
                                                                                          _elfSectionHeaders::00000150(*)  
        001002b8 00 00 00        Elf64_Sy
                 00 00 00 
                 00 00 00 
                             //
                             // .dynstr 
                             // SHT_STRTAB  [0x390 - 0x434]
                             // ram:00100390-ram:00100434
                             //
                             __DT_STRTAB                                     XREF[2]:     00300e40(*), 
                                                                                          _elfSectionHeaders::00000190(*)  
        00100390 00              ??         00h
        00100391 6c 69 62        utf8       u8"libc.so.6"
                 63 2e 73 
                 6f 2e 36 00
        0010039b 5f 5f 73        utf8       u8"__stack_chk_fail"
                 74 61 63 
                 6b 5f 63 
        001003ac 70 72 69        utf8       u8"printf"
                 6e 74 66 00
        001003b3 5f 5f 63        utf8       u8"__cxa_finalize"
                 78 61 5f 
                 66 69 6e 
        001003c2 73 63 61        utf8       u8"scanf"
                 6e 66 00
        001003c8 5f 5f 6c        utf8       u8"__libc_start_main"
                 69 62 63 
                 5f 73 74 
        001003da 47 4c 49        utf8       u8"GLIBC_2.2.5"
                 42 43 5f 
                 32 2e 32 
        001003e6 47 4c 49        utf8       u8"GLIBC_2.4"
                 42 43 5f 
                 32 2e 34 00
        001003f0 5f 49 54        utf8       u8"_ITM_deregisterTMCloneTable"
                 4d 5f 64 
                 65 72 65 
        0010040c 5f 5f 67        utf8       u8"__gmon_start__"
                 6d 6f 6e 
                 5f 73 74 
        0010041b 5f 49 54        utf8       u8"_ITM_registerTMCloneTable"
                 4d 5f 72 
                 65 67 69 
                             //
                             // .gnu.version 
                             // SHT_GNU_versym  [0x436 - 0x447]
                             // ram:00100436-ram:00100447
                             //
                             __DT_VERSYM                                     XREF[2]:     00300f40(*), 
                                                                                          _elfSectionHeaders::000001d0(*)  
        00100436 00 00           dw         0h                                               0
        00100438 00 00           dw         0h                                               _ITM_deregisterTMCloneTable
        0010043a 02 00           dw         2h                                               __stack_chk_fail
        0010043c 03 00           dw         3h                                               printf
        0010043e 03 00           dw         3h                                               __libc_start_main
        00100440 00 00           dw         0h                                               __gmon_start__
        00100442 03 00           dw         3h                                               scanf
        00100444 00 00           dw         0h                                               _ITM_registerTMCloneTable
        00100446 03 00           dw         3h                                               __cxa_finalize
                             //
                             // .gnu.version_r 
                             // SHT_GNU_verneed  [0x448 - 0x477]
                             // ram:00100448-ram:00100477
                             //
                             __DT_VERNEED                                    XREF[2]:     00300f20(*), 
                                                                                          _elfSectionHeaders::00000210(*)  
        00100448 01              ??         01h
        00100449 00              ??         00h
        0010044a 02              ??         02h
        0010044b 00              ??         00h
        0010044c 01              ??         01h
        0010044d 00              ??         00h
        0010044e 00              ??         00h                                              ?  ->  00100000
        0010044f 00              ??         00h
        00100450 10              ??         10h
        00100451 00              ??         00h
        00100452 00              ??         00h
        00100453 00              ??         00h
        00100454 00              ??         00h
        00100455 00              ??         00h
        00100456 00              ??         00h
        00100457 00              ??         00h
        00100458 75              ??         75h    u
        00100459 1a              ??         1Ah
        0010045a 69              ??         69h    i
        0010045b 09              ??         09h
        0010045c 00              ??         00h
        0010045d 00              ??         00h
        0010045e 03              ??         03h
        0010045f 00              ??         00h
        00100460 4a              ??         4Ah    J
        00100461 00              ??         00h
        00100462 00              ??         00h
        00100463 00              ??         00h
        00100464 10              ??         10h
        00100465 00              ??         00h
        00100466 00              ??         00h
        00100467 00              ??         00h
        00100468 14              ??         14h
        00100469 69              ??         69h    i
        0010046a 69              ??         69h    i
        0010046b 0d              ??         0Dh
        0010046c 00              ??         00h
        0010046d 00              ??         00h
        0010046e 02              ??         02h
        0010046f 00              ??         00h
        00100470 56              ??         56h    V
        00100471 00              ??         00h
        00100472 00              ??         00h
        00100473 00              ??         00h
        00100474 00              ??         00h
        00100475 00              ??         00h
        00100476 00              ??         00h
        00100477 00              ??         00h
                             //
                             // .rela.dyn 
                             // SHT_RELA  [0x478 - 0x537]
                             // ram:00100478-ram:00100537
                             //
                             __DT_RELA                                       XREF[2]:     00300ed0(*), 
                                                                                          _elfSectionHeaders::00000250(*)  
        00100478 a8 0d 20        Elf64_Re                                                    location to apply the relocation
                 00 00 00 
                 00 00 08 
                             //
                             // .rela.plt 
                             // SHT_RELA  [0x538 - 0x57f]
                             // ram:00100538-ram:0010057f
                             //
                             __DT_JMPREL                                     XREF[2]:     00300ec0(*), 
                                                                                          _elfSectionHeaders::00000290(*)  
        00100538 c0 0f 20        Elf64_Re                                                    location to apply the relocation
                 00 00 00 
                 00 00 07 
                             //
                             // .init 
                             // SHT_PROGBITS  [0x580 - 0x596]
                             // ram:00100580-ram:00100596
                             //
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             int __stdcall _init(EVP_PKEY_CTX * ctx)
             int               EAX:4          <RETURN>
             EVP_PKEY_CTX *    RDI:8          ctx
                             __DT_INIT                                       XREF[4]:     Entry Point(*), 
                             _init                                                        __libc_csu_init:001007fc(c), 
                                                                                          00300dd0(*), 
                                                                                          _elfSectionHeaders::000002d0(*)  
        00100580 48 83 ec 08     SUB        RSP,0x8
        00100584 48 8b 05        MOV        RAX=><EXTERNAL>::__gmon_start__,qword ptr [-><   = ??
                 5d 0a 20 00                                                                 = 00302020
        0010058b 48 85 c0        TEST       RAX,RAX
        0010058e 74 02           JZ         LAB_00100592
        00100590 ff d0           CALL       RAX=><EXTERNAL>::__gmon_start__                  undefined __gmon_start__()
                             LAB_00100592                                    XREF[1]:     0010058e(j)  
        00100592 48 83 c4 08     ADD        RSP,0x8
        00100596 c3              RET
                             //
                             // .plt 
                             // SHT_PROGBITS  [0x5a0 - 0x5df]
                             // ram:001005a0-ram:001005df
                             //
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined FUN_001005a0()
             undefined         AL:1           <RETURN>
                             FUN_001005a0                                    XREF[6]:     001005bb(c), 001005cb(c), 
                                                                                          001005db(c), 0010087c, 
                                                                                          00100908(*), 
                                                                                          _elfSectionHeaders::00000310(*)  
        001005a0 ff 35 0a        PUSH       qword ptr [PTR_00300fb0]                         = 00000000
                 0a 20 00
        001005a6 ff 25 0c        JMP        qword ptr [PTR_00300fb8]
                 0a 20 00
        001005ac 0f              ??         0Fh
        001005ad 1f              ??         1Fh
        001005ae 40              ??         40h    @
        001005af 00              ??         00h
                             **************************************************************
                             *                       THUNK FUNCTION                       *
                             **************************************************************
                             thunk noreturn undefined __stack_chk_fail()
                               Thunked-Function: <EXTERNAL>::__stack_chk
             undefined         AL:1           <RETURN>
                             <EXTERNAL>::__stack_chk_fail                    XREF[1]:     main:001007c7(c)  
        001005b0 ff 25 0a        JMP        qword ptr [-><EXTERNAL>::__stack_chk_fail]       undefined __stack_chk_fail()
                 0a 20 00
                             -- Flow Override: CALL_RETURN (COMPUTED_CALL_TERMINATOR)
        001005b6 68 00 00        PUSH       0x0
                 00 00
        001005bb e9 e0 ff        JMP        FUN_001005a0                                     undefined FUN_001005a0()
                 ff ff
                             -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
                             **************************************************************
                             *                       THUNK FUNCTION                       *
                             **************************************************************
                             thunk int printf(char * __format, ...)
                               Thunked-Function: <EXTERNAL>::printf
             int               EAX:4          <RETURN>
             char *            RDI:8          __format
                             <EXTERNAL>::printf                              XREF[2]:     main:0010074f(c), 
                                                                                          main:001007ae(c)  
        001005c0 ff 25 02        JMP        qword ptr [-><EXTERNAL>::printf]                 int printf(char * __format, ...)
                 0a 20 00
                             -- Flow Override: CALL_RETURN (COMPUTED_CALL_TERMINATOR)
        001005c6 68 01 00        PUSH       0x1
                 00 00
        001005cb e9 d0 ff        JMP        FUN_001005a0                                     undefined FUN_001005a0()
                 ff ff
                             -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
                             **************************************************************
                             *                       THUNK FUNCTION                       *
                             **************************************************************
                             thunk int scanf(char * __format, ...)
                               Thunked-Function: <EXTERNAL>::scanf
             int               EAX:4          <RETURN>
             char *            RDI:8          __format
                             <EXTERNAL>::scanf                               XREF[1]:     main:00100767(c)  
        001005d0 ff 25 fa        JMP        qword ptr [-><EXTERNAL>::scanf]                  int scanf(char * __format, ...)
                 09 20 00
                             -- Flow Override: CALL_RETURN (COMPUTED_CALL_TERMINATOR)
        001005d6 68 02 00        PUSH       0x2
                 00 00
        001005db e9 c0 ff        JMP        FUN_001005a0                                     undefined FUN_001005a0()
                 ff ff
                             -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
                             //
                             // .plt.got 
                             // SHT_PROGBITS  [0x5e0 - 0x5e7]
                             // ram:001005e0-ram:001005e7
                             //
                             **************************************************************
                             *                       THUNK FUNCTION                       *
                             **************************************************************
                             thunk undefined __cxa_finalize()
                               Thunked-Function: <EXTERNAL>::__cxa_final
             undefined         AL:1           <RETURN>
                             <EXTERNAL>::__cxa_finalize                      XREF[4]:     __do_global_dtors_aux:001006ce(c
                                                                                          00100884, 00100930(*), 
                                                                                          _elfSectionHeaders::00000350(*)  
        001005e0 ff 25 12        JMP        qword ptr [-><EXTERNAL>::__cxa_finalize]         undefined __cxa_finalize()
                 0a 20 00
                             -- Flow Override: CALL_RETURN (COMPUTED_CALL_TERMINATOR)
        001005e6 66              ??         66h    f
        001005e7 90              ??         90h
                             //
                             // .text 
                             // SHT_PROGBITS  [0x5f0 - 0x841]
                             // ram:001005f0-ram:00100841
                             //
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined processEntry _start()
             undefined         AL:1           <RETURN>
             undefined8        Stack[-0x10]:8 local_10                                XREF[1]:     001005fe(*)  
                             _start                                          XREF[5]:     Entry Point(*), 00100018(*), 
                                                                                          0010088c, 001008d8(*), 
                                                                                          _elfSectionHeaders::00000390(*)  
        001005f0 31 ed           XOR        EBP,EBP
        001005f2 49 89 d1        MOV        R9,RDX
        001005f5 5e              POP        RSI
        001005f6 48 89 e2        MOV        RDX,RSP
        001005f9 48 83 e4 f0     AND        RSP,-0x10
        001005fd 50              PUSH       RAX
        001005fe 54              PUSH       RSP=>local_10
        001005ff 4c 8d 05        LEA        R8,[__libc_csu_fini]
                 3a 02 00 00
        00100606 48 8d 0d        LEA        RCX,[__libc_csu_init]
                 c3 01 00 00
        0010060d 48 8d 3d        LEA        RDI,[main]
                 11 01 00 00
        00100614 ff 15 c6        CALL       qword ptr [-><EXTERNAL>::__libc_start_main]      undefined __libc_start_main()
                 09 20 00                                                                    = 00302018
        0010061a f4              HLT
        0010061b 0f              ??         0Fh
        0010061c 1f              ??         1Fh
        0010061d 44              ??         44h    D
        0010061e 00              ??         00h
        0010061f 00              ??         00h
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined deregister_tm_clones()
             undefined         AL:1           <RETURN>
                             deregister_tm_clones                            XREF[1]:     __do_global_dtors_aux:001006d3(c
        00100620 48 8d 3d        LEA        RDI,[__TMC_END__]
                 f1 09 20 00
        00100627 55              PUSH       RBP
        00100628 48 8d 05        LEA        RAX,[__TMC_END__]
                 e9 09 20 00
        0010062f 48 39 f8        CMP        RAX,RDI
        00100632 48 89 e5        MOV        RBP,RSP
        00100635 74 19           JZ         LAB_00100650
        00100637 48 8b 05        MOV        RAX=><EXTERNAL>::_ITM_deregisterTMCloneTable,q   = ??
                 9a 09 20 00                                                                 = 00302000
        0010063e 48 85 c0        TEST       RAX,RAX
        00100641 74 0d           JZ         LAB_00100650
        00100643 5d              POP        RBP
        00100644 ff e0           JMP        RAX=><EXTERNAL>::_ITM_deregisterTMCloneTable     undefined _ITM_deregisterTMClone
                             -- Flow Override: CALL_RETURN (COMPUTED_CALL_TERMINATOR)
        00100646 66              ??         66h    f
        00100647 2e              ??         2Eh    .
        00100648 0f              ??         0Fh
        00100649 1f              ??         1Fh
        0010064a 84              ??         84h
        0010064b 00              ??         00h
        0010064c 00              ??         00h
        0010064d 00              ??         00h
        0010064e 00              ??         00h
        0010064f 00              ??         00h
                             LAB_00100650                                    XREF[2]:     00100635(j), 00100641(j)  
        00100650 5d              POP        RBP
        00100651 c3              RET
        00100652 0f              ??         0Fh
        00100653 1f              ??         1Fh
        00100654 40              ??         40h    @
        00100655 00              ??         00h
        00100656 66              ??         66h    f
        00100657 2e              ??         2Eh    .
        00100658 0f              ??         0Fh
        00100659 1f              ??         1Fh
        0010065a 84              ??         84h
        0010065b 00              ??         00h
        0010065c 00              ??         00h
        0010065d 00              ??         00h
        0010065e 00              ??         00h
        0010065f 00              ??         00h
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined register_tm_clones()
             undefined         AL:1           <RETURN>
                             register_tm_clones                              XREF[1]:     frame_dummy:001006f5(c)  
        00100660 48 8d 3d        LEA        RDI,[__TMC_END__]
                 b1 09 20 00
        00100667 48 8d 35        LEA        RSI,[__TMC_END__]
                 aa 09 20 00
        0010066e 55              PUSH       RBP
        0010066f 48 29 fe        SUB        RSI,RDI
        00100672 48 89 e5        MOV        RBP,RSP
        00100675 48 c1 fe 03     SAR        RSI,0x3
        00100679 48 89 f0        MOV        RAX,RSI
        0010067c 48 c1 e8 3f     SHR        RAX,0x3f
        00100680 48 01 c6        ADD        RSI,RAX
        00100683 48 d1 fe        SAR        RSI,0x1
        00100686 74 18           JZ         LAB_001006a0
        00100688 48 8b 05        MOV        RAX=><EXTERNAL>::_ITM_registerTMCloneTable,qwo   = ??
                 61 09 20 00                                                                 = 00302030
        0010068f 48 85 c0        TEST       RAX,RAX
        00100692 74 0c           JZ         LAB_001006a0
        00100694 5d              POP        RBP
        00100695 ff e0           JMP        RAX=><EXTERNAL>::_ITM_registerTMCloneTable       undefined _ITM_registerTMCloneTa
                             -- Flow Override: CALL_RETURN (COMPUTED_CALL_TERMINATOR)
        00100697 66              ??         66h    f
        00100698 0f              ??         0Fh
        00100699 1f              ??         1Fh
        0010069a 84              ??         84h
        0010069b 00              ??         00h
        0010069c 00              ??         00h
        0010069d 00              ??         00h
        0010069e 00              ??         00h
        0010069f 00              ??         00h
                             LAB_001006a0                                    XREF[2]:     00100686(j), 00100692(j)  
        001006a0 5d              POP        RBP
        001006a1 c3              RET
        001006a2 0f              ??         0Fh
        001006a3 1f              ??         1Fh
        001006a4 40              ??         40h    @
        001006a5 00              ??         00h
        001006a6 66              ??         66h    f
        001006a7 2e              ??         2Eh    .
        001006a8 0f              ??         0Fh
        001006a9 1f              ??         1Fh
        001006aa 84              ??         84h
        001006ab 00              ??         00h
        001006ac 00              ??         00h
        001006ad 00              ??         00h
        001006ae 00              ??         00h
        001006af 00              ??         00h
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __do_global_dtors_aux()
             undefined         AL:1           <RETURN>
                             __do_global_dtors_aux                           XREF[3]:     Entry Point(*), 
                                                                                          __libc_csu_init:00100819(c), 
                                                                                          00300db0(*)  
        001006b0 80 3d 5d        CMP        byte ptr [completed.7697],0x0                    = ??
                 09 20 00 00
        001006b7 75 2f           JNZ        LAB_001006e8
        001006b9 48 83 3d        CMP        qword ptr [-><EXTERNAL>::__cxa_finalize],0x0     = 00302038
                 37 09 20 
                 00 00
        001006c1 55              PUSH       RBP
        001006c2 48 89 e5        MOV        RBP,RSP
        001006c5 74 0c           JZ         LAB_001006d3
        001006c7 48 8b 3d        MOV        RDI,qword ptr [->__dso_handle]                   = 00301008
                 3a 09 20 00
        001006ce e8 0d ff        CALL       <EXTERNAL>::__cxa_finalize                       undefined __cxa_finalize()
                 ff ff
                             LAB_001006d3                                    XREF[1]:     001006c5(j)  
        001006d3 e8 48 ff        CALL       deregister_tm_clones                             undefined deregister_tm_clones()
                 ff ff
        001006d8 c6 05 35        MOV        byte ptr [completed.7697],0x1                    = ??
                 09 20 00 01
        001006df 5d              POP        RBP
        001006e0 c3              RET
        001006e1 0f              ??         0Fh
        001006e2 1f              ??         1Fh
        001006e3 80              ??         80h
        001006e4 00              ??         00h
        001006e5 00              ??         00h
        001006e6 00              ??         00h
        001006e7 00              ??         00h
                             LAB_001006e8                                    XREF[1]:     001006b7(j)  
        001006e8 f3 c3           RET
        001006ea 66              ??         66h    f
        001006eb 0f              ??         0Fh
        001006ec 1f              ??         1Fh
        001006ed 44              ??         44h    D
        001006ee 00              ??         00h
        001006ef 00              ??         00h
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined frame_dummy()
             undefined         AL:1           <RETURN>
                             frame_dummy                                     XREF[3]:     Entry Point(*), 
                                                                                          __libc_csu_init:00100819(c), 
                                                                                          00300da8(*)  
        001006f0 55              PUSH       RBP
        001006f1 48 89 e5        MOV        RBP,RSP
        001006f4 5d              POP        RBP
        001006f5 e9 66 ff        JMP        register_tm_clones                               undefined register_tm_clones()
                 ff ff
                             -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined _Z1fi()
             undefined         AL:1           <RETURN>
             undefined4        Stack[-0xc]:4  local_c                                 XREF[3]:     00100708(W), 
                                                                                                   0010070f(R), 
                                                                                                   0010071a(RW)  
             undefined4        Stack[-0x10]:4 local_10                                XREF[3]:     00100701(W), 
                                                                                                   00100717(RW), 
                                                                                                   00100720(R)  
             undefined4        Stack[-0x1c]:4 local_1c                                XREF[2]:     001006fe(W), 
                                                                                                   00100712(R)  
                             _Z1fi                                           XREF[4]:     Entry Point(*), main:00100780(c), 
                                                                                          00100894, 00100948(*)  
        001006fa 55              PUSH       RBP
        001006fb 48 89 e5        MOV        RBP,RSP
        001006fe 89 7d ec        MOV        dword ptr [RBP + local_1c],EDI
        00100701 c7 45 f8        MOV        dword ptr [RBP + local_10],0x1
                 01 00 00 00
        00100708 c7 45 fc        MOV        dword ptr [RBP + local_c],0x1
                 01 00 00 00
                             LAB_0010070f                                    XREF[1]:     0010071e(j)  
        0010070f 8b 45 fc        MOV        EAX,dword ptr [RBP + local_c]
        00100712 3b 45 ec        CMP        EAX,dword ptr [RBP + local_1c]
        00100715 7f 09           JG         LAB_00100720
        00100717 d1 65 f8        SHL        dword ptr [RBP + local_10],0x1
        0010071a 83 45 fc 01     ADD        dword ptr [RBP + local_c],0x1
        0010071e eb ef           JMP        LAB_0010070f
                             LAB_00100720                                    XREF[1]:     00100715(j)  
        00100720 8b 45 f8        MOV        EAX,dword ptr [RBP + local_10]
        00100723 5d              POP        RBP
        00100724 c3              RET
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined main()
             undefined         AL:1           <RETURN>
             undefined8        Stack[-0x10]:8 local_10                                XREF[2]:     00100736(W), 
                                                                                                   001007b8(R)  
             undefined4        Stack[-0x14]:4 local_14                                XREF[4]:     0010076c(W), 
                                                                                                   00100776(R), 
                                                                                                   0010077b(R), 
                                                                                                   00100797(RW)  
             undefined4        Stack[-0x18]:4 local_18                                XREF[5]:     0010073c(W), 
                                                                                                   00100785(RW), 
                                                                                                   0010078e(R), 
                                                                                                   00100794(W), 
                                                                                                   0010079d(R)  
             undefined4        Stack[-0x1c]:4 local_1c                                XREF[2]:     00100754(*), 
                                                                                                   00100773(R)  
                             main                                            XREF[4]:     Entry Point(*), 
                                                                                          _start:0010060d(*), 0010089c, 
                                                                                          00100968(*)  
        00100725 55              PUSH       RBP
        00100726 48 89 e5        MOV        RBP,RSP
        00100729 48 83 ec 20     SUB        RSP,0x20
        0010072d 64 48 8b        MOV        RAX,qword ptr FS:[0x28]
                 04 25 28 
                 00 00 00
        00100736 48 89 45 f8     MOV        qword ptr [RBP + local_10],RAX
        0010073a 31 c0           XOR        EAX,EAX
        0010073c c7 45 f0        MOV        dword ptr [RBP + local_18],0x0
                 00 00 00 00
        00100743 48 8d 3d        LEA        RDI,[s_Enter_N:_00100854]                        = "Enter N: "
                 0a 01 00 00
        0010074a b8 00 00        MOV        EAX,0x0
                 00 00
        0010074f e8 6c fe        CALL       <EXTERNAL>::printf                               int printf(char * __format, ...)
                 ff ff
        00100754 48 8d 45 ec     LEA        RAX=>local_1c,[RBP + -0x14]
        00100758 48 89 c6        MOV        RSI,RAX
        0010075b 48 8d 3d        LEA        RDI,[DAT_0010085e]                               = 25h    %
                 fc 00 00 00
        00100762 b8 00 00        MOV        EAX,0x0
                 00 00
        00100767 e8 64 fe        CALL       <EXTERNAL>::scanf                                int scanf(char * __format, ...)
                 ff ff
        0010076c c7 45 f4        MOV        dword ptr [RBP + local_14],0x1
                 01 00 00 00
                             LAB_00100773                                    XREF[1]:     0010079b(j)  
        00100773 8b 45 ec        MOV        EAX,dword ptr [RBP + local_1c]
        00100776 39 45 f4        CMP        dword ptr [RBP + local_14],EAX
        00100779 7f 22           JG         LAB_0010079d
        0010077b 8b 45 f4        MOV        EAX,dword ptr [RBP + local_14]
        0010077e 89 c7           MOV        EDI,EAX
        00100780 e8 75 ff        CALL       _Z1fi                                            undefined _Z1fi()
                 ff ff
        00100785 01 45 f0        ADD        dword ptr [RBP + local_18],EAX
        00100788 8b 0d 82        MOV        ECX,dword ptr [mod]                              = 0000000Ah
                 08 20 00
        0010078e 8b 45 f0        MOV        EAX,dword ptr [RBP + local_18]
        00100791 99              CDQ
        00100792 f7 f9           IDIV       ECX
        00100794 89 55 f0        MOV        dword ptr [RBP + local_18],EDX
        00100797 83 45 f4 01     ADD        dword ptr [RBP + local_14],0x1
        0010079b eb d6           JMP        LAB_00100773
                             LAB_0010079d                                    XREF[1]:     00100779(j)  
        0010079d 8b 45 f0        MOV        EAX,dword ptr [RBP + local_18]
        001007a0 89 c6           MOV        ESI,EAX
        001007a2 48 8d 3d        LEA        RDI,[s_Result_is_%d_00100861]                    = "Result is %d"
                 b8 00 00 00
        001007a9 b8 00 00        MOV        EAX,0x0
                 00 00
        001007ae e8 0d fe        CALL       <EXTERNAL>::printf                               int printf(char * __format, ...)
                 ff ff
        001007b3 b8 00 00        MOV        EAX,0x0
                 00 00
        001007b8 48 8b 55 f8     MOV        RDX,qword ptr [RBP + local_10]
        001007bc 64 48 33        XOR        RDX,qword ptr FS:[0x28]
                 14 25 28 
                 00 00 00
        001007c5 74 05           JZ         LAB_001007cc
        001007c7 e8 e4 fd        CALL       <EXTERNAL>::__stack_chk_fail                     undefined __stack_chk_fail()
                 ff ff
                             -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
                             LAB_001007cc                                    XREF[1]:     001007c5(j)  
        001007cc c9              LEAVE
        001007cd c3              RET
        001007ce 66              ??         66h    f
        001007cf 90              ??         90h
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __libc_csu_init()
             undefined         AL:1           <RETURN>
                             __libc_csu_init                                 XREF[4]:     Entry Point(*), 
                                                                                          _start:00100606(*), 001008a4, 
                                                                                          00100988(*)  
        001007d0 41 57           PUSH       R15
        001007d2 41 56           PUSH       R14
        001007d4 49 89 d7        MOV        R15,RDX
        001007d7 41 55           PUSH       R13
        001007d9 41 54           PUSH       R12
        001007db 4c 8d 25        LEA        R12,[__frame_dummy_init_array_entry]             = 001006f0
                 c6 05 20 00
        001007e2 55              PUSH       RBP
        001007e3 48 8d 2d        LEA        RBP,[__do_global_dtors_aux_fini_array_entry]     = 001006b0
                 c6 05 20 00
        001007ea 53              PUSH       RBX
        001007eb 41 89 fd        MOV        R13D,EDI
        001007ee 49 89 f6        MOV        R14,RSI
        001007f1 4c 29 e5        SUB        RBP,R12
        001007f4 48 83 ec 08     SUB        RSP,0x8
        001007f8 48 c1 fd 03     SAR        RBP,0x3
        001007fc e8 7f fd        CALL       _init                                            int _init(EVP_PKEY_CTX * ctx)
                 ff ff
        00100801 48 85 ed        TEST       RBP,RBP
        00100804 74 20           JZ         LAB_00100826
        00100806 31 db           XOR        EBX,EBX
        00100808 0f 1f 84        NOP        dword ptr [RAX + RAX*0x1]
                 00 00 00 
                 00 00
                             LAB_00100810                                    XREF[1]:     00100824(j)  
        00100810 4c 89 fa        MOV        RDX,R15
        00100813 4c 89 f6        MOV        RSI,R14
        00100816 44 89 ef        MOV        EDI,R13D
        00100819 41 ff 14 dc     CALL       qword ptr [R12 + RBX*0x8]=>->frame_dummy         undefined __do_global_dtors_aux()
                                                                                             undefined frame_dummy()
                                                                                             = 001006f0
                                                                                             = 001006b0
        0010081d 48 83 c3 01     ADD        RBX,0x1
        00100821 48 39 dd        CMP        RBP,RBX
        00100824 75 ea           JNZ        LAB_00100810
                             LAB_00100826                                    XREF[1]:     00100804(j)  
        00100826 48 83 c4 08     ADD        RSP,0x8
        0010082a 5b              POP        RBX
        0010082b 5d              POP        RBP
        0010082c 41 5c           POP        R12
        0010082e 41 5d           POP        R13
        00100830 41 5e           POP        R14
        00100832 41 5f           POP        R15
        00100834 c3              RET
        00100835 90              ??         90h
        00100836 66              ??         66h    f
        00100837 2e              ??         2Eh    .
        00100838 0f              ??         0Fh
        00100839 1f              ??         1Fh
        0010083a 84              ??         84h
        0010083b 00              ??         00h
        0010083c 00              ??         00h
        0010083d 00              ??         00h
        0010083e 00              ??         00h
        0010083f 00              ??         00h
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __libc_csu_fini()
             undefined         AL:1           <RETURN>
                             __libc_csu_fini                                 XREF[4]:     Entry Point(*), 
                                                                                          _start:001005ff(*), 001008ac, 
                                                                                          001009d0(*)  
        00100840 f3 c3           RET
                             //
                             // .fini 
                             // SHT_PROGBITS  [0x844 - 0x84c]
                             // ram:00100844-ram:0010084c
                             //
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined _fini()
             undefined         AL:1           <RETURN>
                             __DT_FINI                                       XREF[3]:     Entry Point(*), 00300de0(*), 
                             _fini                                                        _elfSectionHeaders::000003d0(*)  
        00100844 48 83 ec 08     SUB        RSP,0x8
        00100848 48 83 c4 08     ADD        RSP,0x8
        0010084c c3              RET
                             //
                             // .rodata 
                             // SHT_PROGBITS  [0x850 - 0x86d]
                             // ram:00100850-ram:0010086d
                             //
                             _IO_stdin_used                                  XREF[2]:     Entry Point(*), 
                                                                                          _elfSectionHeaders::00000410(*)  
        00100850 01 00 02 00     undefined4 00020001h
                             s_Enter_N:_00100854                             XREF[1]:     main:00100743(*)  
        00100854 45 6e 74        ds         "Enter N: "
                 65 72 20 
                 4e 3a 20 00
                             DAT_0010085e                                    XREF[1]:     main:0010075b(*)  
        0010085e 25              ??         25h    %
        0010085f 64              ??         64h    d
        00100860 00              ??         00h
                             s_Result_is_%d_00100861                         XREF[1]:     main:001007a2(*)  
        00100861 52 65 73        ds         "Result is %d"
                 75 6c 74 
                 20 69 73 
                             //
                             // .eh_frame_hdr 
                             // SHT_PROGBITS  [0x870 - 0x8b3]
                             // ram:00100870-ram:001008b3
                             //
                             **************************************************************
                             * Exception Handler Frame Header                             *
                             **************************************************************
                             __GNU_EH_FRAME_HDR                              XREF[2]:     001001a0(*), 
                                                                                          _elfSectionHeaders::00000450(*)  
        00100870 01 1b 03 3b     eh_frame                                                    Exception Handler Frame Header V
        00100874 44 00 00 00     ddw        cie_001008b8                                     Encoded eh_frame_ptr
        00100878 07 00 00 00     ddw        7h                                               Encoded FDE count
                             **************************************************************
                             * Frame Description Entry Table                              *
                             **************************************************************
        0010087c 30 fd ff        fde_tabl                                                    Initial Location
                 ff 90 00 
                 00 00
        00100884 70 fd ff        fde_tabl                                                    Initial Location
                 ff b8 00 
                 00 00
        0010088c 80 fd ff        fde_tabl                                                    Initial Location
                 ff 60 00 
                 00 00
        00100894 8a fe ff        fde_tabl                                                    Initial Location
                 ff d0 00 
                 00 00
        0010089c b5 fe ff        fde_tabl                                                    Initial Location
                 ff f0 00 
                 00 00
        001008a4 60 ff ff        fde_tabl                                                    Initial Location
                 ff 10 01 
                 00 00
        001008ac d0 ff ff        fde_tabl                                                    Initial Location
                 ff 58 01 
                 00 00
                             //
                             // .eh_frame 
                             // SHT_PROGBITS  [0x8b8 - 0x9df]
                             // ram:001008b8-ram:001009df
                             //
                             **************************************************************
                             * Common Information Entry                                   *
                             **************************************************************
                             cie_001008b8                                    XREF[3]:     00100874(*), 001008d4(*), 
                                                                                          _elfSectionHeaders::00000490(*)  
        001008b8 14 00 00 00     ddw        14h                                              (CIE) Length
        001008bc 00 00 00 00     ddw        0h                                               (CIE) ID
        001008c0 01              db         1h                                               (CIE) Version
        001008c1 7a 52 00        ds         "zR"                                             (CIE) Augmentation String
        001008c4 01              uleb128    1h                                               (CIE) Code Alignment
        001008c5 78              sleb128    -8h                                              (CIE) Data Alignment
        001008c6 10              db         10h                                              (CIE) Return Address Register Co
        001008c7 01              uleb128    1h                                               (CIE) Augmentation Data Length
        001008c8 1b              dwfenc     DW_EH_PE_sdata4 | DW_EH_PE_pcrel                 (CIE Augmentation Data) FDE Enco
        001008c9 0c 07 08        db[7]                                                       (CIE) Initial Instructions
                 90 01 07 10
                             **************************************************************
                             * Frame Descriptor Entry                                     *
                             **************************************************************
                             fde_001008d0                                    XREF[1]:     00100890(*)  
        001008d0 14 00 00 00     ddw        14h                                              (FDE) Length
        001008d4 1c 00 00 00     ddw        cie_001008b8                                     (FDE) CIE Reference Pointer 
        001008d8 18 fd ff ff     ddw        _start                                           (FDE) PcBegin
        001008dc 2b 00 00        dq         2Bh                                              (FDE) PcRange
                 00 00 00 
                 00 00
        001008e4 00              uleb128    0h                                               (FDE) Augmentation Data Length
        001008e5 00 00 00        db[3]                                                       (FDE) Call Frame Instructions
                             **************************************************************
                             * Common Information Entry                                   *
                             **************************************************************
                             cie_001008e8                                    XREF[6]:     00100904(*), 0010092c(*), 
                                                                                          00100944(*), 00100964(*), 
                                                                                          00100984(*), 001009cc(*)  
        001008e8 14 00 00 00     ddw        14h                                              (CIE) Length
        001008ec 00 00 00 00     ddw        0h                                               (CIE) ID
        001008f0 01              db         1h                                               (CIE) Version
        001008f1 7a 52 00        ds         "zR"                                             (CIE) Augmentation String
        001008f4 01              uleb128    1h                                               (CIE) Code Alignment
        001008f5 78              sleb128    -8h                                              (CIE) Data Alignment
        001008f6 10              db         10h                                              (CIE) Return Address Register Co
        001008f7 01              uleb128    1h                                               (CIE) Augmentation Data Length
        001008f8 1b              dwfenc     DW_EH_PE_sdata4 | DW_EH_PE_pcrel                 (CIE Augmentation Data) FDE Enco
        001008f9 0c 07 08        db[7]                                                       (CIE) Initial Instructions
                 90 01 00 00
                             **************************************************************
                             * Frame Descriptor Entry                                     *
                             **************************************************************
                             fde_00100900                                    XREF[1]:     00100880(*)  
        00100900 24 00 00 00     ddw        24h                                              (FDE) Length
        00100904 1c 00 00 00     ddw        cie_001008e8                                     (FDE) CIE Reference Pointer 
        00100908 98 fc ff ff     ddw        FUN_001005a0                                     (FDE) PcBegin
        0010090c 40 00 00 00     ddw        40h                                              (FDE) PcRange
        00100910 00              uleb128    0h                                               (FDE) Augmentation Data Length
        00100911 0e 10 46        db[23]                                                      (FDE) Call Frame Instructions
                 0e 18 4a 
                 0f 0b 77 
                             **************************************************************
                             * Frame Descriptor Entry                                     *
                             **************************************************************
                             fde_00100928                                    XREF[1]:     00100888(*)  
        00100928 14 00 00 00     ddw        14h                                              (FDE) Length
        0010092c 44 00 00 00     ddw        cie_001008e8                                     (FDE) CIE Reference Pointer 
        00100930 b0 fc ff ff     ddw        <EXTERNAL>::__cxa_finalize                       (FDE) PcBegin
        00100934 08 00 00        dq         8h                                               (FDE) PcRange
                 00 00 00 
                 00 00
        0010093c 00              uleb128    0h                                               (FDE) Augmentation Data Length
        0010093d 00 00 00        db[3]                                                       (FDE) Call Frame Instructions
                             **************************************************************
                             * Frame Descriptor Entry                                     *
                             **************************************************************
                             fde_00100940                                    XREF[1]:     00100898(*)  
        00100940 1c 00 00 00     ddw        1Ch                                              (FDE) Length
        00100944 5c 00 00 00     ddw        cie_001008e8                                     (FDE) CIE Reference Pointer 
        00100948 b2 fd ff ff     ddw        _Z1fi                                            (FDE) PcBegin
        0010094c 2b 00 00 00     ddw        2Bh                                              (FDE) PcRange
        00100950 00              uleb128    0h                                               (FDE) Augmentation Data Length
        00100951 41 0e 10        db[15]                                                      (FDE) Call Frame Instructions
                 86 02 43 
                 0d 06 66 
                             **************************************************************
                             * Frame Descriptor Entry                                     *
                             **************************************************************
                             fde_00100960                                    XREF[1]:     001008a0(*)  
        00100960 1c 00 00 00     ddw        1Ch                                              (FDE) Length
        00100964 7c 00 00 00     ddw        cie_001008e8                                     (FDE) CIE Reference Pointer 
        00100968 bd fd ff ff     ddw        main                                             (FDE) PcBegin
        0010096c a9 00 00 00     ddw        A9h                                              (FDE) PcRange
        00100970 00              uleb128    0h                                               (FDE) Augmentation Data Length
        00100971 41 0e 10        db[15]                                                      (FDE) Call Frame Instructions
                 86 02 43 
                 0d 06 02 
                             **************************************************************
                             * Frame Descriptor Entry                                     *
                             **************************************************************
                             fde_00100980                                    XREF[1]:     001008a8(*)  
        00100980 44 00 00 00     ddw        44h                                              (FDE) Length
        00100984 9c 00 00 00     ddw        cie_001008e8                                     (FDE) CIE Reference Pointer 
        00100988 48 fe ff ff     ddw        __libc_csu_init                                  (FDE) PcBegin
        0010098c 65 00 00 00     ddw        65h                                              (FDE) PcRange
        00100990 00              uleb128    0h                                               (FDE) Augmentation Data Length
        00100991 42 0e 10        db[55]                                                      (FDE) Call Frame Instructions
                 8f 02 42 
                 0e 18 8e 
                             **************************************************************
                             * Frame Descriptor Entry                                     *
                             **************************************************************
                             fde_001009c8                                    XREF[1]:     001008b0(*)  
        001009c8 10 00 00 00     ddw        10h                                              (FDE) Length
        001009cc e4 00 00 00     ddw        cie_001008e8                                     (FDE) CIE Reference Pointer 
        001009d0 70 fe ff ff     ddw        __libc_csu_fini                                  (FDE) PcBegin
        001009d4 02 00 00        dq         2h                                               (FDE) PcRange
                 00 00 00 
                 00 00
                             **************************************************************
                             * END OF FRAME                                               *
                             **************************************************************
                             __FRAME_END__
        001009dc 00 00 00 00     ddw        0h                                               End of Frame
                             //
                             // .init_array 
                             // SHT_INIT_ARRAY  [0x200da8 - 0x200daf]
                             // ram:00300da8-ram:00300daf
                             //
                             __DT_INIT_ARRAY                                 XREF[6]:     001000f8(*), 00100210(*), 
                             __init_array_start                                           __libc_csu_init:001007db(*), 
                             __frame_dummy_init_array_entry                               __libc_csu_init:00100819(R), 
                                                                                          00300df0(*), 
                                                                                          _elfSectionHeaders::000004d0(*)  
        00300da8 f0 06 10        addr       frame_dummy
                 00 00 00 
                 00 00
                             //
                             // .fini_array 
                             // SHT_FINI_ARRAY  [0x200db0 - 0x200db7]
                             // ram:00300db0-ram:00300db7
                             //
                             __DT_FINI_ARRAY                                 XREF[4]:     __libc_csu_init:001007e3(*), 
                             __init_array_end                                             __libc_csu_init:00100819(R), 
                             __do_global_dtors_aux_fini_array_entry                       00300e10(*), 
                                                                                          _elfSectionHeaders::00000510(*)  
        00300db0 b0 06 10        addr       __do_global_dtors_aux
                 00 00 00 
                 00 00
                             //
                             // .dynamic 
                             // SHT_DYNAMIC  [0x200db8 - 0x200fa7]
                             // ram:00300db8-ram:00300fa7
                             //
                             _DYNAMIC                                        XREF[3]:     00100130(*), 00300fa8(*), 
                                                                                          _elfSectionHeaders::00000550(*)  
        00300db8 01 00 00        Elf64_Dy                                                    DT_NEEDED - Name of needed library
                 00 00 00 
                 00 00 01 
        00300f68 00              ??         00h
        00300f69 00              ??         00h
        00300f6a 00              ??         00h
        00300f6b 00              ??         00h
        00300f6c 00              ??         00h
        00300f6d 00              ??         00h
        00300f6e 00              ??         00h
        00300f6f 00              ??         00h
        00300f70 00              ??         00h
        00300f71 00              ??         00h
        00300f72 00              ??         00h
        00300f73 00              ??         00h
        00300f74 00              ??         00h
        00300f75 00              ??         00h
        00300f76 00              ??         00h
        00300f77 00              ??         00h
        00300f78 00              ??         00h
        00300f79 00              ??         00h
        00300f7a 00              ??         00h
        00300f7b 00              ??         00h
        00300f7c 00              ??         00h
        00300f7d 00              ??         00h
        00300f7e 00              ??         00h
        00300f7f 00              ??         00h
        00300f80 00              ??         00h
        00300f81 00              ??         00h
        00300f82 00              ??         00h
        00300f83 00              ??         00h
        00300f84 00              ??         00h
        00300f85 00              ??         00h
        00300f86 00              ??         00h
        00300f87 00              ??         00h
        00300f88 00              ??         00h
        00300f89 00              ??         00h
        00300f8a 00              ??         00h
        00300f8b 00              ??         00h
        00300f8c 00              ??         00h
        00300f8d 00              ??         00h
        00300f8e 00              ??         00h
        00300f8f 00              ??         00h
        00300f90 00              ??         00h
        00300f91 00              ??         00h
        00300f92 00              ??         00h
        00300f93 00              ??         00h
        00300f94 00              ??         00h
        00300f95 00              ??         00h
        00300f96 00              ??         00h
        00300f97 00              ??         00h
        00300f98 00              ??         00h
        00300f99 00              ??         00h
        00300f9a 00              ??         00h
        00300f9b 00              ??         00h
        00300f9c 00              ??         00h
        00300f9d 00              ??         00h
        00300f9e 00              ??         00h
        00300f9f 00              ??         00h
        00300fa0 00              ??         00h
        00300fa1 00              ??         00h
        00300fa2 00              ??         00h
        00300fa3 00              ??         00h
        00300fa4 00              ??         00h
        00300fa5 00              ??         00h
        00300fa6 00              ??         00h
        00300fa7 00              ??         00h
                             //
                             // .got 
                             // SHT_PROGBITS  [0x200fa8 - 0x200fff]
                             // ram:00300fa8-ram:00300fff
                             //
                             __DT_PLTGOT                                     XREF[2]:     00300e90(*), 
                             _GLOBAL_OFFSET_TABLE_                                        _elfSectionHeaders::00000590(*)  
        00300fa8 b8 0d 30        addr       _DYNAMIC
                 00 00 00 
                 00 00
                             PTR_00300fb0                                    XREF[1]:     FUN_001005a0:001005a0(R)  
        00300fb0 00 00 00        addr       00000000
                 00 00 00 
                 00 00
                             PTR_00300fb8                                    XREF[1]:     FUN_001005a0:001005a6  
        00300fb8 00 00 00        addr       00000000
                 00 00 00 
                 00 00
                             PTR___stack_chk_fail_00300fc0                   XREF[1]:     __stack_chk_fail:001005b0  
        00300fc0 08 20 30        addr       <EXTERNAL>::__stack_chk_fail                     = ??
                 00 00 00 
                 00 00
                             PTR_printf_00300fc8                             XREF[1]:     printf:001005c0  
        00300fc8 10 20 30        addr       <EXTERNAL>::printf                               = ??
                 00 00 00 
                 00 00
                             PTR_scanf_00300fd0                              XREF[1]:     scanf:001005d0  
        00300fd0 28 20 30        addr       <EXTERNAL>::scanf                                = ??
                 00 00 00 
                 00 00
                             PTR__ITM_deregisterTMCloneTable_00300fd8        XREF[1]:     deregister_tm_clones:00100637(R)  
        00300fd8 00 20 30        addr       <EXTERNAL>::_ITM_deregisterTMCloneTable          = ??
                 00 00 00 
                 00 00
                             PTR___libc_start_main_00300fe0                  XREF[1]:     _start:00100614(R)  
        00300fe0 18 20 30        addr       <EXTERNAL>::__libc_start_main                    = ??
                 00 00 00 
                 00 00
                             PTR___gmon_start___00300fe8                     XREF[1]:     _init:00100584(R)  
        00300fe8 20 20 30        addr       <EXTERNAL>::__gmon_start__                       = ??
                 00 00 00 
                 00 00
                             PTR__ITM_registerTMCloneTable_00300ff0          XREF[1]:     register_tm_clones:00100688(R)  
        00300ff0 30 20 30        addr       <EXTERNAL>::_ITM_registerTMCloneTable            = ??
                 00 00 00 
                 00 00
                             PTR___cxa_finalize_00300ff8                     XREF[2]:     __cxa_finalize:001005e0, 
                                                                                          __do_global_dtors_aux:001006b9(R
        00300ff8 38 20 30        addr       <EXTERNAL>::__cxa_finalize                       = ??
                 00 00 00 
                 00 00
                             //
                             // .data 
                             // SHT_PROGBITS  [0x201000 - 0x201013]
                             // ram:00301000-ram:00301013
                             //
                             __data_start                                    XREF[2]:     Entry Point(*), 
                             data_start                                                   _elfSectionHeaders::000005d0(*)  
        00301000 00              ??         00h
        00301001 00              ??         00h
        00301002 00              ??         00h
        00301003 00              ??         00h
        00301004 00              ??         00h
        00301005 00              ??         00h
        00301006 00              ??         00h
        00301007 00              ??         00h
                             __dso_handle                                    XREF[3]:     Entry Point(*), 
                                                                                          __do_global_dtors_aux:001006c7(R
                                                                                          00301008(*)  
        00301008 08 10 30        addr       __dso_handle                                     = 00301008
                 00 00 00 
                 00 00
                             mod                                             XREF[2]:     Entry Point(*), main:00100788(R)  
        00301010 0a 00 00 00     undefined4 0000000Ah
                             //
                             // .bss 
                             // SHT_NOBITS  [0x201014 - 0x201017]
                             // ram:00301014-ram:00301017
                             //
                             _edata                                          XREF[4]:     Entry Point(*), 
                             __bss_start                                                  __do_global_dtors_aux:001006b0(R
                             completed.7697                                               __do_global_dtors_aux:001006d8(W
                                                                                          _elfSectionHeaders::00000610(*)  
        00301014                 undefined1 ??
        00301015                 ??         ??
        00301016                 ??         ??
        00301017                 ??         ??
                             //
                             // EXTERNAL 
                             // NOTE: This block is artificial and allows ELF Relocations 
                             // ram:00302000-ram:0030203f
                             //
                             **************************************************************
                             *                       THUNK FUNCTION                       *
                             **************************************************************
                             thunk undefined _ITM_deregisterTMCloneTable()
                               Thunked-Function: <EXTERNAL>::_ITM_deregi
             undefined         AL:1           <RETURN>
                             <EXTERNAL>::_ITM_deregisterTMCloneTable         XREF[3]:     deregister_tm_clones:00100637(*), 
                                                                                          deregister_tm_clones:00100644(c), 
                                                                                          00300fd8(*)  
        00302000                 ??         ??
        00302001                 ??         ??
        00302002                 ??         ??
        00302003                 ??         ??
        00302004                 ??         ??
        00302005                 ??         ??
        00302006                 ??         ??
        00302007                 ??         ??
                             **************************************************************
                             *                       THUNK FUNCTION                       *
                             **************************************************************
                             thunk noreturn undefined __stack_chk_fail()
                               Thunked-Function: <EXTERNAL>::__stack_chk
             undefined         AL:1           <RETURN>
                             __stack_chk_fail@@GLIBC_2.4
                             <EXTERNAL>::__stack_chk_fail                    XREF[2]:     __stack_chk_fail:001005b0(T), 
                                                                                          __stack_chk_fail:001005b0(c), 
                                                                                          00300fc0(*)  
        00302008                 ??         ??
        00302009                 ??         ??
        0030200a                 ??         ??
        0030200b                 ??         ??
        0030200c                 ??         ??
        0030200d                 ??         ??
        0030200e                 ??         ??
        0030200f                 ??         ??
                             **************************************************************
                             *                       THUNK FUNCTION                       *
                             **************************************************************
                             thunk int printf(char * __format, ...)
                               Thunked-Function: <EXTERNAL>::printf
             int               EAX:4          <RETURN>
             char *            RDI:8          __format
                             printf@@GLIBC_2.2.5
                             <EXTERNAL>::printf                              XREF[2]:     printf:001005c0(T), 
                                                                                          printf:001005c0(c), 00300fc8(*)  
        00302010                 ??         ??
        00302011                 ??         ??
        00302012                 ??         ??
        00302013                 ??         ??
        00302014                 ??         ??
        00302015                 ??         ??
        00302016                 ??         ??
        00302017                 ??         ??
                             **************************************************************
                             *                       THUNK FUNCTION                       *
                             **************************************************************
                             thunk undefined __libc_start_main()
                               Thunked-Function: <EXTERNAL>::__libc_star
             undefined         AL:1           <RETURN>
                             __libc_start_main@@GLIBC_2.2.5
                             <EXTERNAL>::__libc_start_main                   XREF[2]:     _start:00100614(c), 00300fe0(*)  
        00302018                 ??         ??
        00302019                 ??         ??
        0030201a                 ??         ??
        0030201b                 ??         ??
        0030201c                 ??         ??
        0030201d                 ??         ??
        0030201e                 ??         ??
        0030201f                 ??         ??
                             **************************************************************
                             *                       THUNK FUNCTION                       *
                             **************************************************************
                             thunk undefined __gmon_start__()
                               Thunked-Function: <EXTERNAL>::__gmon_star
             undefined         AL:1           <RETURN>
                             <EXTERNAL>::__gmon_start__                      XREF[3]:     _init:00100584(*), 
                                                                                          _init:00100590(c), 00300fe8(*)  
        00302020                 ??         ??
        00302021                 ??         ??
        00302022                 ??         ??
        00302023                 ??         ??
        00302024                 ??         ??
        00302025                 ??         ??
        00302026                 ??         ??
        00302027                 ??         ??
                             **************************************************************
                             *                       THUNK FUNCTION                       *
                             **************************************************************
                             thunk int scanf(char * __format, ...)
                               Thunked-Function: <EXTERNAL>::scanf
             int               EAX:4          <RETURN>
             char *            RDI:8          __format
                             scanf@@GLIBC_2.2.5
                             <EXTERNAL>::scanf                               XREF[2]:     scanf:001005d0(T), 
                                                                                          scanf:001005d0(c), 00300fd0(*)  
        00302028                 ??         ??
        00302029                 ??         ??
        0030202a                 ??         ??
        0030202b                 ??         ??
        0030202c                 ??         ??
        0030202d                 ??         ??
        0030202e                 ??         ??
        0030202f                 ??         ??
                             **************************************************************
                             *                       THUNK FUNCTION                       *
                             **************************************************************
                             thunk undefined _ITM_registerTMCloneTable()
                               Thunked-Function: <EXTERNAL>::_ITM_regist
             undefined         AL:1           <RETURN>
                             <EXTERNAL>::_ITM_registerTMCloneTable           XREF[3]:     register_tm_clones:00100688(*), 
                                                                                          register_tm_clones:00100695(c), 
                                                                                          00300ff0(*)  
        00302030                 ??         ??
        00302031                 ??         ??
        00302032                 ??         ??
        00302033                 ??         ??
        00302034                 ??         ??
        00302035                 ??         ??
        00302036                 ??         ??
        00302037                 ??         ??
                             **************************************************************
                             *                       THUNK FUNCTION                       *
                             **************************************************************
                             thunk undefined __cxa_finalize()
                               Thunked-Function: <EXTERNAL>::__cxa_final
             undefined         AL:1           <RETURN>
                             __cxa_finalize@@GLIBC_2.2.5
                             <EXTERNAL>::__cxa_finalize                      XREF[2]:     __cxa_finalize:001005e0(T), 
                                                                                          __cxa_finalize:001005e0(c), 
                                                                                          00300ff8(*)  
        00302038                 ??         ??
        00302039                 ??         ??
        0030203a                 ??         ??
        0030203b                 ??         ??
        0030203c                 ??         ??
        0030203d                 ??         ??
        0030203e                 ??         ??
        0030203f                 ??         ??
                             //
                             // .comment 
                             // SHT_PROGBITS [not-loaded]
                             // .comment::00000000-.comment::0000002a
                             //
             assume DF = <UNKNOWN>
                             ElfComment[0]                                   XREF[1]:     _elfSectionHeaders::00000650(*)  
     t::00000000 47 43 43        utf8       u8"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
                 3a 20 28 
                 55 62 75 
                             //
                             // .shstrtab 
                             // SHT_STRTAB [not-loaded]
                             // .shstrtab::00000000-.shstrtab::000000fd
                             //
                             DAT_.shstrtab__00000000                         XREF[1]:     _elfSectionHeaders::00000710(*)  
     b::00000000 00              ??         00h
     b::00000001 2e 73 79        utf8       u8".symtab"
                 6d 74 61 
                 62 00
     b::00000009 2e 73 74        utf8       u8".strtab"
                 72 74 61 
                 62 00
     b::00000011 2e 73 68        utf8       u8".shstrtab"
                 73 74 72 
                 74 61 62 00
     b::0000001b 2e 69 6e        utf8       u8".interp"
                 74 65 72 
                 70 00
     b::00000023 2e 6e 6f        utf8       u8".note.ABI-tag"
                 74 65 2e 
                 41 42 49 
     b::00000031 2e 6e 6f        utf8       u8".note.gnu.build-id"
                 74 65 2e 
                 67 6e 75 
     b::00000044 2e 67 6e        utf8       u8".gnu.hash"
                 75 2e 68 
                 61 73 68 00
     b::0000004e 2e 64 79        utf8       u8".dynsym"
                 6e 73 79 
                 6d 00
     b::00000056 2e 64 79        utf8       u8".dynstr"
                 6e 73 74 
                 72 00
     b::0000005e 2e 67 6e        utf8       u8".gnu.version"
                 75 2e 76 
                 65 72 73 
     b::0000006b 2e 67 6e        utf8       u8".gnu.version_r"
                 75 2e 76 
                 65 72 73 
     b::0000007a 2e 72 65        utf8       u8".rela.dyn"
                 6c 61 2e 
                 64 79 6e 00
     b::00000084 2e 72 65        utf8       u8".rela.plt"
                 6c 61 2e 
                 70 6c 74 00
     b::0000008e 2e 69 6e        utf8       u8".init"
                 69 74 00
     b::00000094 2e 70 6c        utf8       u8".plt.got"
                 74 2e 67 
                 6f 74 00
     b::0000009d 2e 74 65        utf8       u8".text"
                 78 74 00
     b::000000a3 2e 66 69        utf8       u8".fini"
                 6e 69 00
     b::000000a9 2e 72 6f        utf8       u8".rodata"
                 64 61 74 
                 61 00
     b::000000b1 2e 65 68        utf8       u8".eh_frame_hdr"
                 5f 66 72 
                 61 6d 65 
     b::000000bf 2e 65 68        utf8       u8".eh_frame"
                 5f 66 72 
                 61 6d 65 00
     b::000000c9 2e 69 6e        utf8       u8".init_array"
                 69 74 5f 
                 61 72 72 
     b::000000d5 2e 66 69        utf8       u8".fini_array"
                 6e 69 5f 
                 61 72 72 
     b::000000e1 2e 64 79        utf8       u8".dynamic"
                 6e 61 6d 
                 69 63 00
     b::000000ea 2e 64 61        utf8       u8".data"
                 74 61 00
     b::000000f0 2e 62 73        utf8       u8".bss"
                 73 00
     b::000000f5 2e 63 6f        utf8       u8".comment"
                 6d 6d 65 
                 6e 74 00
                             //
                             // .strtab 
                             // SHT_STRTAB [not-loaded]
                             // .strtab::00000000-.strtab::0000023c
                             //
                             DAT_.strtab__00000000                           XREF[1]:     _elfSectionHeaders::000006d0(*)  
     b::00000000 00              ??         00h
     b::00000001 63 72 74        utf8       u8"crtstuff.c"
                 73 74 75 
                 66 66 2e 
     b::0000000c 64 65 72        utf8       u8"deregister_tm_clones"
                 65 67 69 
                 73 74 65 
     b::00000021 5f 5f 64        utf8       u8"__do_global_dtors_aux"
                 6f 5f 67 
                 6c 6f 62 
     b::00000037 63 6f 6d        utf8       u8"completed.7697"
                 70 6c 65 
                 74 65 64 
     b::00000046 5f 5f 64        utf8       u8"__do_global_dtors_aux_fini_array_entry"
                 6f 5f 67 
                 6c 6f 62 
     b::0000006d 66 72 61        utf8       u8"frame_dummy"
                 6d 65 5f 
                 64 75 6d 
     b::00000079 5f 5f 66        utf8       u8"__frame_dummy_init_array_entry"
                 72 61 6d 
                 65 5f 64 
     b::00000098 31 36 2e        utf8       u8"16.cpp"
                 63 70 70 00
     b::0000009f 5f 5f 46        utf8       u8"__FRAME_END__"
                 52 41 4d 
                 45 5f 45 
     b::000000ad 5f 5f 69        utf8       u8"__init_array_end"
                 6e 69 74 
                 5f 61 72 
     b::000000be 5f 44 59        utf8       u8"_DYNAMIC"
                 4e 41 4d 
                 49 43 00
     b::000000c7 5f 5f 69        utf8       u8"__init_array_start"
                 6e 69 74 
                 5f 61 72 
     b::000000da 5f 5f 47        utf8       u8"__GNU_EH_FRAME_HDR"
                 4e 55 5f 
                 45 48 5f 
     b::000000ed 5f 47 4c        utf8       u8"_GLOBAL_OFFSET_TABLE_"
                 4f 42 41 
                 4c 5f 4f 
     b::00000103 5f 5f 6c        utf8       u8"__libc_csu_fini"
                 69 62 63 
                 5f 63 73 
     b::00000113 6d 6f 64 00     utf8       u8"mod"
     b::00000117 5f 49 54        utf8       u8"_ITM_deregisterTMCloneTable"
                 4d 5f 64 
                 65 72 65 
     b::00000133 5f 65 64        utf8       u8"_edata"
                 61 74 61 00
     b::0000013a 5f 5f 73        utf8       u8"__stack_chk_fail@@GLIBC_2.4"
                 74 61 63 
                 6b 5f 63 
     b::00000156 70 72 69        utf8       u8"printf@@GLIBC_2.2.5"
                 6e 74 66 
                 40 40 47 
     b::0000016a 5f 5f 6c        utf8       u8"__libc_start_main@@GLIBC_2.2.5"
                 69 62 63 
                 5f 73 74 
     b::00000189 5f 5f 64        utf8       u8"__data_start"
                 61 74 61 
                 5f 73 74 
     b::00000196 5f 5f 67        utf8       u8"__gmon_start__"
                 6d 6f 6e 
                 5f 73 74 
     b::000001a5 5f 5f 64        utf8       u8"__dso_handle"
                 73 6f 5f 
                 68 61 6e 
     b::000001b2 5f 49 4f        utf8       u8"_IO_stdin_used"
                 5f 73 74 
                 64 69 6e 
     b::000001c1 5f 5a 31        utf8       u8"_Z1fi"
                 66 69 00
     b::000001c7 5f 5f 6c        utf8       u8"__libc_csu_init"
                 69 62 63 
                 5f 63 73 
     b::000001d7 5f 5f 62        utf8       u8"__bss_start"
                 73 73 5f 
                 73 74 61 
     b::000001e3 6d 61 69        utf8       u8"main"
                 6e 00
     b::000001e8 73 63 61        utf8       u8"scanf@@GLIBC_2.2.5"
                 6e 66 40 
                 40 47 4c 
     b::000001fb 5f 5f 54        utf8       u8"__TMC_END__"
                 4d 43 5f 
                 45 4e 44 
     b::00000207 5f 49 54        utf8       u8"_ITM_registerTMCloneTable"
                 4d 5f 72 
                 65 67 69 
     b::00000221 5f 5f 63        utf8       u8"__cxa_finalize@@GLIBC_2.2.5"
                 78 61 5f 
                 66 69 6e 
                             //
                             // .symtab 
                             // SHT_SYMTAB [not-loaded]
                             // .symtab::00000000-.symtab::00000647
                             //
                             Elf64_Sym_ARRAY_.symtab__00000000               XREF[1]:     _elfSectionHeaders::00000690(*)  
     b::00000000 00 00 00        Elf64_Sy
                 00 00 00 
                 00 00 00 
                             //
                             // _elfSectionHeaders 
                             // Elf Section Headers
                             // _elfSectionHeaders::00000000-_elfSectionHeaders::0000073f
                             //
                             Elf64_Shdr_ARRAY__elfSectionHeaders__00000000   XREF[1]:     00100028(*)  
     s::00000000 00 00 00        Elf64_Sh                                                    SECTION0 - SHT_NULL
                 00 00 00 
                 00 00 00 
