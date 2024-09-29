section .data
section .bss
section .text

global r_area
r_area:
    push rbp
    mov rbp, rsp
    mov rax, rdi
    imul rax, rsi
    mov rsp, rbp
    pop rbp
    ret
global r_cicumference
r_cicumference:
    push rbp
    mov rbp, rsp
    mov rax, rsi
    add rax, rdi
    add rax, rax
    mov rsp, rbp
    pop rbp
    ret