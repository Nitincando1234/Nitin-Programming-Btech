extern pi

section .data
section .bss
section .text
global c_area
c_area:
    push rbp 
    mov rbp, rsp
    movsd xmm1, [pi]
    mulsd xmm0, xmm0
    mulsd xmm0, xmm1
    mov rsp, rbp
    pop rbp
    ret
global c_circumference
c_circumference:
    push rbp
    mov rbp, rsp
    addsd xmm0, xmm0
    mulsd xmm0, [pi]
    mov rsp, rbp
    pop rbp
    ret