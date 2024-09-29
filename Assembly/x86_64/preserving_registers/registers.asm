extern printf

section .data
                 pi dq 3.1415
            first   db "A",0
            second  db "B",0
            third   db "C",0
            fourth  db "E",0
            fifth   db "F",0
            sixth   db "G",0
            seventh db "H",0
            eighth  db "I",0
            nineth  db "J",0
            tenth   db "K",0
    format_string   db "Ths string is: %s%s%s%s%s%s%s%s%s%s",10,0
    format_string1  db "The value of pie: %f",10,0
    
section .bss

section .text
    global main
main:
    push        rbp
    mov rbp,    rsp
    sub rsp,    8
    
    mov rdi,    format_string
    mov rsi,    first
    mov rdx,    second
    mov rcx,    third
    mov r8,     fourth
    mov r9,     fifth
    
    push tenth
    push nineth
    push eighth
    push seventh
    push sixth
    
    mov rax, 0
    call printf
    
    ;and rsp,    0xfffffffffffffff0
    
    mov rax, 1
    movsd xmm0, qword[pi]
        
    mov rdi,    format_string1
    call printf
    
    leave
    ret