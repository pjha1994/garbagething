section .data

msg1 : db "hello!",10,"Enter a number : "
len1 : equ $-msg1
msg2 : db "you have entered : "
len2 : equ $-msg2
num1  : dd 0
section .bss
  num : resb 1

section .text 
  global _start

_start:
      mov eax,4
      mov ebx,1
      mov ecx,msg1
      mov edx,len1
      int 80h
      
      mov eax,3
      mov ebx,0
      mov ecx,num
      mov edx,5
      int 80h
loop:
      mov eax,4
      mov ebx,0
      mov ecx,msg2
      mov edx,len2
      int 80h

      mov eax,4
      mov ebx,0
      mov ecx,num
      mov edx,5
      int 80h
      mov eax,[num1]
      dec eax
      mov [num1],eax
      jnz loop
      mov eax,4
      mov ebx,0
      mov ecx,10
      mov edx,1
      int 80h

      mov eax,1
      mov ebx,0
      int 80h
