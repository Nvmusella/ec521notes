BITS 64

jmp short add_call

below:
   ;;  set up the loop
   mov rsi, 12      
   pop rcx         
   mov rdi, rcx      
loop:
   ;; write
   mov rcx, rdi            
   mov rax, 4              ; syscall #4 = write
   mov rbx, 2              ; standard error (file descriptor)
   mov rdx, 21      
   int 0x80                ; do the system call
   dec rsi         
   jnz loop              
    
   ;; exit
   mov rax,1      ; exit system call number
   mov rbx,0      ; the return status
   int 0x80       ; do the system call

add_call:
   call below                        
   db "Saya_hack_oleh_itu_saya", 0x0a, 0x0d
