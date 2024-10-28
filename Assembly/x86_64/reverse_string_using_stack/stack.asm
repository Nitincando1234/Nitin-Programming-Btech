extern printf

section .data 
     mystring db "ABCDE", 0  
     mystringLen equ $ - mystring - 1
     fmt1 db "Original String: %s",10,0
     fmt2 db "Reversed String: %s",10,0
     
section .text
    global main
    
main: 
    push rbp
    mov rbp,rsp
    
    mov rdi, fmt1
    mov rsi, mystring
    mov rax, 0
    call printf
    
    mov rcx, mystringLen
    mov r12, 0  ;character pointer
    mov rax, 0
    mov rbx, mystring
    
pushloop:
    mov al, byte[rbx +r12]
    push rax
    inc r12
    loop pushloop
    
    mov rcx, mystringLen
    mov r12, 0
    mov rbx, mystring
    
poploop:
    pop rax
    mov byte[rbx +r12], al
    inc r12
    loop poploop
    
    mov byte[rbx + r12],0
    
    mov rdi, fmt2
    mov rsi, mystring
    mov rax, 0
    call printf
    
    mov rsp,rbp
    pop rbp
    ret
