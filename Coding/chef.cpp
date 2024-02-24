org 100h 

.data
n1 db 2
n2 db 3
temp db ?
msg db "The GCD is : $"
msg2 db "The LCM is : $"
ln db 13,10,"$"



.code 

;swapping n2 has bigger element
mov dl,n2
cmp n1,dl
jg k
jmp l1: 
k:
mov dl,n1
mov dh,n2
mov n1,dl
mov n2,dh 
mov dx,0 

l1:
mov al,n2  
mov bl,n1 

l3:           ;gcd part
div bl
cmp ah,0
je l4 
mov temp,bl
mov bl,ah
mov al,temp 
mov ah,0
jmp l3


l4:
mov dx,offset msg
mov ah,9h
int 21h
mov dl,bl
add dl,48 
mov ah,2h
int 21h   

mov dx,offset ln
mov ah,9h
int 21h

mov dx,offset msg2
mov ah,9h
int 21h

;lcm part 
mov ax,0
mov dx,0
mov al,n1
mul n2

div bl

mov dl,al
add dl,48
mov ah,2h
int 21h


hlt

