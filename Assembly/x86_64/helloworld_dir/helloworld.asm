;helloworld.asm
section .data
    msg db "hello world" , 0
section .bss
section .text
    global main
main:
    mov rax , 1 ; 1 = write
    mov rdi , 1 ; 1 = stdout
    mov rsi , msg ; string to display in rsi
    mov rdx , 20
    syscall
    mov rax , 60 ; 60 = eexit
    mov rdi , 0 ; 0 = on success exit 0
    syscall ; quit
