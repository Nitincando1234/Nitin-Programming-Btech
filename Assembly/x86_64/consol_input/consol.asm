section .data   
    msg1 db     "Hello World",10,0
    msgLen1 equ  $-msg1-1
    msg2 db     "Enter the text: ",0
    msgLen2 equ  $-msg2-1
    msg3 db     "Your Input: ",0
    msgLen3 equ  $-msg3-1
    inputLen equ 10

section .bss
    input resb  inputLen+1
    terminator
section .text
    global main
main:   
    push rbp
    mov rbp,    rsp

    mov rsi,    msg1
    mov rdx,    msgLen1
    call prints

    mov rsi,    msg2
    mov rdx,    msgLen2
    call prints
    mov rsi,    input
    mov rdx,    inputLen
    call reads

    mov rsi,    msg3
    mov rdx,    msgLen3
    call prints
    mov rsi,    input
    mov rdx,    inputLen
    call prints
    leave
    ret
    
prints: 
    push rbp
    mov rbp,    rsp
    
    mov rax,    1
    mov rdi,    1
    syscall
    leave
    ret
     
reads:
    push rbp
    mov rbp,    rsp
    
    mov rax,    0
    mov rdi,    0
    syscall 
    leave
    ret
    
    
    
