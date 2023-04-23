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

	xor eax, eax
	lea rdi, [msg]
	call printf

	mov eax, 0
	lea rdi, [fmt]
	lea rsi, [number]
	call scanf

	xor eax, eax
	lea rdi, [msg1]
	call printf

	xor eax, eax
	lea rdi, [fmt1]
	lea rsi, [name]
	call scanf

	xor eax, eax
	lea rdi, [fmt]
	lea rsi, [number]
	call printf

	xor eax, eax
	lea rdi, [msg3]
	call printf

	xor eax, eax
	lea rdi, [fmt1]
	lea rsi, [name]
	call printf

	mov eax, 0
	add rsp, 16
	
	leave
	ret

section .data
	msg: db "Number To Print:", 10, 0
	fmt: db "%ld", 0
	msg3: db "", 10, 0
	msg: db "String To Print:", 10, 0
	fmt: db "%s", 0

