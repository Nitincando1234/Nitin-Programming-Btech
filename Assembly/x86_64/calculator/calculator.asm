extern printf

section .data
    number1 dq 123
    number2 dq 19
    neg_number dq -12
    
    fmt db "The numbers are %ld and %ld ",10,0
    fmtint db "%s %ld",10,0
    sumi db "The sum is ",0
    difi db "The difference ",0
    inci db "Number1 incremented ",0
    deci db "Number1 decremented ",0
    sali db "Number1 shifted left 2 (*4): ",0
    sari db "Number1 shifted right 2 (/4): ",0
    sariex db "Number1 shift right 2 (/4) wiht sign expression :",0
    multi db "The product is ",0
    divi db "The integer quotient is ",0
    remi db "The modulo is ",0

section .bss
    resulti resq 1
    modulo resq 1
    
section .text 
    global main
main:
    push rbp
    mov rbp, rsp
    
    ;display the numbers
    mov rdi ,fmt
    mov rsi, [number1]
    mov rdx, [number2]
    mov rax, 0
    call printf
    
    ;addition
    mov rax, [number1]
    add rax,[number2]
    mov [resulti], rax
    
    ;display result of addition
    mov rdi, fmtint
    mov rsi, sumi
    mov rdx, [resulti]
    mov rax, 0
    call printf
    
    ;subtraction
    mov rax, [number1]
    sub rax,[number2]
    mov [resulti], rax
    
    ;display result of deletion
    mov rdi, fmtint
    mov rsi, difi
    mov rdx, [resulti]
    mov rax, 0
    call printf
    
    ;incrementing number 1
    mov rax, [number1]
    inc rax
    mov [resulti], rax
    
    ;incrementing: displays the result here
    mov rdi, fmtint
    mov rsi, inci
    mov rdx, [resulti]
    mov rax, 0
    call printf
    
    ;decrementing
    mov rax, [number1]
    dec rax
    mov [resulti], rax
    
    ;decrementation: displays the result here
    mov rdi, fmtint
    mov rsi, deci
    mov rdx, [resulti]
    mov rax, 0
    call printf
    
    ;shift left
    mov rax, [number1]
    sal rax, 2          ;shit left bitwise the contents of the accumulator
    mov [resulti], rax
    
    ;display
    mov rdi, fmtint
    mov rsi, sali
    mov rdx, [resulti]
    mov rax, 0
    call printf
    
    ;shift left
    mov rax, [number1]
    sar rax, 2          ;shit right bitwise (two times ) the contents of the accumulator
    mov [resulti], rax
    
    ;display
    mov rdi, fmtint
    mov rsi, sari
    mov rdx, [resulti]
    mov rax, 0
    call printf
    
    ;shift right sign extension
    mov rax, [neg_number]
    sar rax, 2
    mov [resulti], rax
    
    ;display the result
    mov rdi, fmtint
    mov rsi, sariex
    mov rdx, [resulti]
    mov rax, 0
    call printf
    
    ;multiplication 
    mov rax, [number1]
    imul qword[number2]
    mov [resulti ], rax
    
    ;display 
    mov rdi, fmtint
    mov rsi, multi
    mov rdx, [resulti]
    mov rax, 0
    call printf
    
    ;division
    mov rax, [number1]
    mov rdx, 0          ;the register to store the result in division operation
    idiv qword[number2]
    mov [resulti], rax
    mov [modulo], rdx
    
    ;displaying the quotient
    mov rdi, fmtint
    mov rsi, divi
    mov rdx, [resulti]
    mov rax, 0
    call printf
    
    ;displaying the remainder
    mov rdi, fmtint
    mov rsi, remi
    mov rdx, [resulti]
    mov rax, 0
    call printf
    
    mov rsp,rbp
    pop rbp
    ret