section .data
msg1 : db "Enter number of numbers: "
len1 : equ $-msg1
num  : dd 0
num1 : dd 0
msg2: db "Enter number",10
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

      
      mov esi,[num]
      call read
      mov [num],esi


loop:
      mov eax,4
      mov ebx,1
      mov ecx,msg2
      mov edx,len2
      int 80h
         
      mov esi,[num1]
      call read
      mov [num1],esi
      
      mov edx,[num1]
      push edx 
    
      mov eax,[num]
      dec eax
      mov [num],eax
      jnz loop
     
     

      mov eax,1
      mov ebx,0
      int 80h


read:
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
      
      jmp read
stop:ret
