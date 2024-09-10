extern printf
section .data
    number1 dq 42
    number2 dq 41
    fmt1 db "Number1 < Number2" ,10,0
    fmt2 db "Number1 >= Number2" ,10,0
section .text 
    global main

main:
    push rbp
    mov rbp,rsp
    mov rax, [number1]
    mov rbx, [number2]
    cmp rax, rbx
    jge greater     ; jump to the memory location 'greater' if greater equal (j..ge)
    mov rdi, fmt1
    mov rax, 0
    call printf
    jmp exit    ; jump to the exit label
    
greater:
    mov rdi, fmt2
    xor rax, rax
    call printf
    
exit:
    mov rsp, rbp
    pop rbp
    ret