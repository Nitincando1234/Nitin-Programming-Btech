section .data
    bNum db 123
    dNum dd 12347
    wNum dw 123
    qNum1 dq 12346787876
    qNum2 dq 5665846
    qNum3 dq 3.14
	
section .bss 
section .text	
    global main
main:
    push rbp 
    mov rbp, rsp
    mov rax, -1     ; fill rax with 1s
    mov al, byte[bNum]  ;does not clear the upper bytes of the rax
    xor rax, rax
    mov al, byte[bNum] ;now rax has the correct data
    mov rax, -1
    mov ax, word[wNum]
    xor rax, rax
    mov ax, word[wNum]
    mov rax, -1
    mov rax, qword[qNum1] ;does clears the Upper bytes of the rax
    mov qword[qNum2], rax ;one operand is always a register
    mov rax, 123456 ; source register and the immediate value
    movsd xmm0, [qNum3] ; instruction for the floating point
    
    mov rsp, rbp
    pop rbp
    
    ret
    
    
