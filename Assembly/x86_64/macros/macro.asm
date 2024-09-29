extern printf

%define double_it(r) sal r,1    ;single line macro

%macro printer 2                ;2 means the two args passed
section .data
    %%arg1 db %1,0                  ; %% should be used for creation of new variables otherwise misbehave and %1 for first argument
    %%fmtint db "%s %ld",10,0
section .text
    mov rdi, %%fmtint
    mov rsi, %%arg1
    mov rdx, [%2]
    mov rax, 0
    call printf
%endmacro

section .data
    number dq 12
section .bss
section .text
    global main
main:
    push rbp
    mov rbp, rsp

    printer "The number is: ",number
    mov rax, [number]
    double_it(rax)
    mov [number], rax
    printer "The number twice itself is: ",number

    leave
    ret
    

