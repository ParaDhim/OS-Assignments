global main
extern printf,scanf

section .bss
	number resb 4
	name resb 360

section .txt
main:
	push rbp
	mov rbp, rsp
	sub rsp, 16

	xor rax, rax
	lea rdi, [msg]
	call printf

	mov rax, 0
	lea rdi, [fmt]
	lea rsi, [number]
	call scanf

	xor rax, rax
	lea rdi, [msg1]
	call printf

	xor rax, rax
	lea rdi, [fmt1]
	lea rsi, [name]
	call scanf

	xor rax, rax
	lea rdi, [fmt]
	lea rsi, [number]
	call printf

	xor rax, rax
	lea rdi, [msg3]
	call printf

	xor rax, rax
	lea rdi, [fmt1]
	lea rsi, [name]
	call printf

	mov rax, 0
	add rsp, 16
	leave
	ret

section .data
	msg: db "Number To Print:", 10, 0
	fmt: db "%ld", 0
	msg3: db "", 10, 0
	msg: db "String To Print:", 10, 0
	fmt: db "%s", 0

