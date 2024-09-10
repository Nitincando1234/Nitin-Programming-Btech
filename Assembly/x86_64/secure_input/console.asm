section .data
    message1 db "Hello World !",10,0
    message2 db "Enter your Text: ",0
    message3 db "Your Text: ",0
    newline  dq 0xa
    inputLen equ 10

section .bss
    input    resb inputLen+1
section .text
    global main

main:
    push rbp
    mov rbp,    rsp

    mov rdi,    message1
    call prints
    
    mov rdi,    message2
    call prints
    mov rdi,    input
    mov rsi,    inputLen
    call reads

    mov rdi,    message3
    call prints
    mov rdi,    input
    call prints
    mov rdi,    newline
    call prints
    
    leave 
    ret
prints:
    push rbp
    mov rbp,    rsp
    push r12    ;callee saved register
    mov r12,    rdi
    mov rdx,    0; counter for the string
    .lengthloop:
    cmp byte[r12],0
    je .lengthfound
    inc r12
    inc rdx
    jmp .lengthloop
    .lengthfound:
    cmp rdx,    0
    je .done
    mov rsi,    rdi
    mov rax,    1
    mov rdi,    1
    syscall
    .done:
    pop r12
    leave
    ret

reads:
    section .data
    section .bss
    .inputchar resb 1

    section .text
    push rbp
    mov rbp,    rsp
    push r12
    push r14;   counter of characters
    push r13;   length of input buffer

    mov r12,    rdi
    mov r13,    rsi
    xor r14,    r14

    .readchar:
    mov rax,    0
    mov rdi,    0         ;syscall for input
    lea rsi,    [.inputchar]; effective address of the input buffer
    mov rdx,    1;  no. of characters to take for input
    syscall
    mov al,     [.inputchar]
    cmp al, byte[newline]
    je .done

    cmp al,     97  ;ascii value of the 'a'
    jl .readchar
    cmp al,     122
    jg .readchar

    ;increase counter and checks
    inc r14
    cmp r14,    r13
    ja .readchar;reads the input but ignored and loop will end only if the input is newline

    mov byte[r12],  al
    inc r12
    jmp .readchar
    .done: 
    inc r12
    mov byte[r12],  0;NULL terminator to the string
    pop r12
    pop r13
    pop r14
    leave
    ret