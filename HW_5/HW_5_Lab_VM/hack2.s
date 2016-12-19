BITS 64

jmp short add_call

below:
   ;;  set up the loop
   xor rsi, rsi
   add rsi, 12      
   pop rcx         
   mov rdi, rcx      
loop:
   ;; write
   mov rcx, rdi            
   xor rax, rax              ; syscall #4 = write
   add rax, 4
   xor rbx, rbx              ; standard error (file descriptor)
   add rbx, 2
   xor rdx,rdx      
   add rdx, 21
   int 0x80                ; do the system call
   dec rsi         
   jnz loop              
    
   ;; exit
   xor rax,rax      ; exit system call number
   add rax, 1
   xor rbx,rbx      ; the return status
   int 0x80       ; do the system call

add_call:
   call below                        
   db "Saya_hack_oleh_itu_saya", 0x0a, 0x0d
