extern printf
section .data
    pi dq 3.141592658979
    formatText db "2 times pi is: %14f",10,0
section .text
function3:
    push rbp
    movsd xmm0, [pi]
    addsd xmm0, [pi]
    
    mov rdi, formatText
    mov rax, 1
    call printf
    
    pop rbp
    ret
function2:
    push rbp
    call function3
    pop rbp
    ret
function1:
    push rbp
    call function2
    pop rbp
    ret
global main

main:
    push rbp
    call function1
    pop rbp
    ret