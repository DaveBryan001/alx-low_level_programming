section .data
hello db 'Hello, Holberton', 0

section .text
global main
extern printf
main:
; Set up the stack frame
push rbp
mov rdi, hello  ; First argument: format string
call printf     ; Call printf
mov eax, 0      ; Return 0 from main

; Clean up and exit
pop rbp
ret

