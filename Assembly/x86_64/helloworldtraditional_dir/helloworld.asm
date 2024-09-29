section .data
    hello db "hello world" , 0 ;NULL terminated string
section .text
    global main
main:
    mov rax , 1
    mov rdi , 1
    mov rsi , hello
    mov rdx , 20
    syscall
    ;exit the program
    mov rax , 60
    xor rdi , rdi
    syscall