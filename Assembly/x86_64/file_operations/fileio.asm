section .data
    CREATE equ 1    ; Flags
    APPEND equ 1
    READ   equ 1
    OVERWRITE equ 1
    O_WRITE equ 1   ; Write operation flags
    O_READ equ 1
    DELETE equ 1
    ;sys calls provided by the operating system for operations on the files.....
    NR_READ equ 0
    NR_WRITE equ 1
    NR_OPEN equ 2
    NR_CLOSE equ 3
    NR_LSEEK equ 8
    NR_CREATE equ 85
    NR_UNLINK equ 87

    ;file flags
    O_CREATE equ 00000100q; quad word sized flag integer for instructing operating system to create the new file if  not exists when open syscall is used
    O_APPEND equ 00002000q
    ;access modes
    O_READ_ONLY equ 000000q
    O_WRITE_ONLY equ 000001q
    O_READ_WRITE equ 000002q
    S_USER_READ equ 00400q
    S_USER_WRITE equ 00200q

    ;error messages for file i/o
    Error_open      db "File opening error occured !",NL,0
    Error_create    db "File creation error occured !",NL,0
    Error_close     db "File closing error occured !",NL,0
    Error_write     db "File write error occured !",NL,0
    Error_read      db "File read error occured !",NL,0
    Error_append    db "File append error occured !",NL,0
    Error_delete    db "File deletion error occured !",NL,0
    Error_print     db "File printing error occured !",NL,0
    Error_position  db "File positioning error occured !",NL,0

    ;operation success messages
    OK_create       db "File creation and opening: OK",NL,0
    OK_close        db "File closing: OK",NL,0
    OK_write        db "File write operation: OK",NL,0
    OK_open         db "File opening for Read/Write: OK",NL,0    
    OK_append       db "File Append: OK",NL,0
    OK_delete       db "File deletion: OK",NL,0
    OK_read         db "File read operation: OK",NL,0
    OK_position     db "File positioning of cursor: OK",NL,0

    NL equ 0xa; NL=NewLine character
    bufferLen equ 64; length of buffer
    filename db "new.txt",0

    FD      dq 0; file descripter
    msg1    db "Hello Welcome to my file !",NL,0
    msglen1 dq $-msg1-1
    msg2    db "I hope you find this file well",NL,0
    msglen2 dq $-msg2-1
    msg3    db "Where to go now...",NL,0
    msglen3 dq $-msg3-1
    msg4    db "Yeah, That's it code is working great...",NL,0
    msglen4 dq $-msg4-1
section .bss
        buffer resb bufferLen
section .text
    global main

main:
    push rbp
    mov rbp,    rsp
    %IF CREATE ; %IF => if structure
    mov rdi,    filename
    call createFile
    mov qword[FD],  rax

    mov rdi,    qword[FD]
    mov rsi,    msg1
    mov rdx,    qword[msglen1]
    call writeFile

    mov rdi,    qword[FD]
    call closeFile
    %ENDIF

    %IF OVERWRITE
    mov rdi,    filename
    call openFile
    mov qword[FD],  rax

    mov rdi,    qword[FD]
    mov rsi,    msg2
    mov rdx,    msglen2
    call writeFile

    mov rdi,    qword[FD]
    call closeFile

    %ENDIF

    %IF APPEND
    mov rdi, filename
    call appendFile
    mov qword[FD],  rax

    mov rdi, qword[FD]
    mov rsi,    msg2
    mov rdx,    qword[msglen2]
    call writeFile

    mov rdi,    qword[FD]
    call closeFile
    %ENDIF
    
    %IF O_WRITE; write at offset position
    mov rdi,    filename
    call openFile
    mov qword[FD],  rax

    mov rdi,    qword[FD]
    mov rsi,    qword[msglen2]
    mov rdx,    0       ;0 = reading / writing from the begining of the offset
    call positionFile

    mov rdi,    qword[FD]
    mov rsi,    msg4
    mov rdx,    qword[msglen4]
    call writeFile

    mov rdi,    qword[FD]
    call closeFile
    %ENDIF

    %IF READ

    mov rdi,    filename
    call openFile
    mov qword[FD],  rax

    mov rdi,    qword[FD]
    mov rsi,    buffer
    mov rdx,    bufferLen
    call readFile

    mov rdi,    qword[FD]
    call closeFile
    %ENDIF

    %IF O_READ

    mov rdi,    filename
    call openFile
    mov qword[FD],  rax
    
    mov rdi,    qword[FD]
    mov rsi,    qword[msglen2]
    mov rdx,    0       ;0 = reading / writing from the begining of the offset
    call positionFile

    mov rdi,    qword[FD]
    mov rsi,    buffer
    mov rdx,    10
    call readFile
    mov rdi,    rax
    call printString

    mov rdi,    qword[FD]
    call closeFile
    %ENDIF

    %IF DELETE

    mov rdi, filename
    call deleteFile
    %ENDIF

    mov rsp,    rbp
    pop rbp
    ret

;+++++++++++++++++++++++++File_Function++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    global readFile
readFile:
    mov rax, NR_READ
    SYSCALL

    ;check error in reading
    cmp rax,     0
    jl readerror;   jl= jump on less; beacause syscall returns negative numbers on error
    ;place NULL terminator at the end of the string read from the file
    mov byte[rsi+rax],  0
    mov rax,    rsi
    mov rdi,    OK_read
    push rax
    call printString
    pop rax
    ret
    readerror:
    mov rdi,    Error_read
    call printString

    ret

global deleteFile
deleteFile:
    mov rax,    NR_UNLINK
    SYSCALL
    cmp rax,    0
    jl deleteerror
    mov rdi,    OK_delete
    call printString
    ret
    deleteerror:
    mov rdi,    Error_delete
    call printString

    ret

global appendFile
appendFile:
    mov rax,    NR_OPEN; to open the file
    mov rsi,    O_READ_WRITE|O_APPEND; mode for openning the file , modes can be combined using the pipe operator
    cmp rax,    0
    jl appenderror
    mov rdi,    OK_append
    push rax
    call printString
    pop rax
    ret
    appenderror:
    mov rdi,    Error_append
    call printString; no need to save the rax (accumulator) here as file descriptor is not generated

    ret

global openFile
openFile:
    mov rax,    NR_OPEN
    mov rsi,    O_READ_WRITE
    SYSCALL
    cmp rax,    0
    jl openerror
    mov rdi,   OK_read
    push rax
    call printString
    pop rax
    ret
    openerror:
    mov rdi,    Error_open
    call printString

    ret

global writeFile
writeFile:
    mov rax,    NR_WRITE
    SYSCALL
    cmp rax,    0
    jl writeerror
    mov rdi,    OK_write
    call printString
    ret
    writeerror:
    mov rdi,    Error_write
    call printString

    ret

global positionFile:
positionFile:
    mov rax,    NR_LSEEK
    SYSCALL
    cmp rax,    0
    jl positionerror
    mov rdi,    OK_position
    call printString
    ret
    positionerror:
    mov rdi,    Error_position
    call printString

    ret

global createFile
createFile:
    mov rax,    NR_CREATE
    mov rsi,    S_USER_READ|S_USER_WRITE;means only user can operate on the file with r/w permission ;only for files created by this function
    SYSCALL
    cmp rax,    0
    jl creationerror
    mov rdi,    OK_create
    push rax
    call printString
    pop rax
    ret
    creationerror:
    mov rdi,    Error_create
    call printString

    ret     
global closeFile
closeFile:
    mov rax,    NR_CLOSE
    SYSCALL
    cmp rax,    0
    jl closeerror
    mov rdi,    OK_close
    call printString
    ret
    closeerror:
    mov rdi,    Error_close
    call printString
    
    ret

global printString
printString:
    mov r12,    rdi
    mov rdx,    0
    strloop:
    cmp byte[r12],  0; NULL comparision for end of the string checking
    je strdone
    inc rdx 
    inc r12
    jmp strloop
    strdone:
    cmp rdx,  0
    je exit
    mov rsi,    rdi
    mov rax,    1; for correct printing operation
    mov rdi,    1;1= file descriptor of the stdout
    SYSCALL
    exit:
    ret
    
