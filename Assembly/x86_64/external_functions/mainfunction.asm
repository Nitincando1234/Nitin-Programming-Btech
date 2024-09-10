extern printf
extern c_area
extern c_circumference
extern r_area 
extern r_cicumference
global pi
section .data.
    pi dq 3.1415
    radius dq 10.0
    side1 dq 4
    side2 dq 5
    format_f db "%s %f",10,0
    format_i db "%s %d",10,0
    ca db "The Area of the circle is",10,0
    cc db "The Circumference of the circle is ",10,0
    ra db "The Area of the rectangle is",10,0
    rc db "The Circumference of the rectangle is ",10,0
    
section .text
    global main
main:
    push rbp
    mov rbp, rsp
    movsd xmm0, qword[radius]
    call c_area
    mov rdi, format_f
    mov rsi, ca
    mov rax, 1
    call printf
    movsd xmm0, qword [radius]
    call c_circumference
    mov rdi, format_f
    mov rsi, cc
    mov rax, 1
    call printf
    ;for rectangle here
    mov rsi, [side1]
    mov rdi, [side2]    
    call r_area
    mov rdi, format_i
    mov rsi, ra
    mov rdx, rax
    mov rax, 0
    call printf
    mov rsi, [side1]
    mov rdi, [side2]    
    call r_cicumference
    mov rdi, format_i
    mov rsi, rc
    mov rdx, rax
    mov rax, 0
    call printf
    
    mov rsp, rbp
    pop rbp
    ret
    