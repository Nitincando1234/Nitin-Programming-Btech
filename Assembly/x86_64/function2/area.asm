extern printf

section .data
    radius dq 10.0
section .text
area:
section .data   
    .pi dq 3.14
section .text 
    push rbp
    mov rbp, rsp
    movsd xmm0, [radius]
    mulsd xmm0, [radius]
    mulsd xmm0, [.pi]
    leave
    ret

circumference:
section .data
    .pi dq 3.14
section .text
    push rbp
    mov rbp, rsp
    movsd xmm0, [radius]
    addsd xmm0, [radius]
    mulsd xmm0, [.pi]
    leave
    ret
circle: 
section .data
    area_format db "The area is %f", 10,0
    circumference_format db "The circumference is %f", 10, 0
section .text
    push rbp
    mov rbp, rsp
    
    call area
    mov rdi, area_format
    mov rax, 1
    call printf
    
    call circumference
    mov rdi, circumference_format
    mov rax, 1
    call printf
    leave 
    ret
    global main
main:
    push rbp
    mov rbp, rsp
    call circle
    leave 
    ret
    
    