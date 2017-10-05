section .data
msg1 : db "Enter number of times you want to print Hello World! : "
len1 : equ $-msg1
num1  : dd 0
msg2: db "Hello World!",10
len2: equ $-msg2
section .bss
  temp: resb 1
section .text 
  global _start

_start:
      
      mov eax,4
      mov ebx,1
      mov ecx,msg1
      mov edx,len1
      int 80h

      
      mov esi,[num1]
      call convert
      mov [num1],esi
loop:
      mov eax,4
      mov ebx,1
      mov ecx,msg2
      mov edx,len2
      int 80h
 
      mov eax,[num1]
      dec eax
      mov [num1],eax
      jnz loop
     
     

      mov eax,1
      mov ebx,0
      int 80h


convert:
      mov eax,3
      mov ebx,0
      mov ecx,temp
      mov edx,1
      int 80h
      
      mov ecx,[temp]
      cmp ecx,10
      je stop
      sub ecx,30h
      mov ebx,10
      mov eax,esi
      mul ebx
      add eax,ecx
      mov esi,eax
      
      jmp convert
stop:ret
