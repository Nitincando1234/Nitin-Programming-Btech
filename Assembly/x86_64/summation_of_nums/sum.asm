extern printf
section .data
	number dq 50000000000000000
	fmt db "The summation from 0 to %ld = %ld",10,0
section .text 
	global main
main:
	push rbp
	mov rbp,rsp

	mov rcx, [number]  ; loop counter
	mov rax, 0
	
bloop: 	add rax, rcx 
	loop bloop

	mov rdi, fmt
	mov rsi, [number]
	mov rdx ,rax
	xor rax, rax	
	
	call printf

	mov rsp, rbp
	pop rbp
	ret
	
