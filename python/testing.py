org 100h
 
.data
arr db 8,4,3,4,5,4
s1 db ?


.code
lea dx,msg
mov ah,9h
int 21h
mov ax,@data
mov ds,ax
mov si,0h
mov cx,03h   

l1:
add bl,arr[si] 
add si,2h
loop l1 

mov s1,bl 
mov bl,0 
mov cx,03h   
mov si,01

l2:
add bl,arr[si]
add si,02
loop l2 
              
;;sub s1,s2

sub s1,bl
mov dl,s1
add dl,48
mov ah,2h
int 21h
msg db "The subtraction of even and odd index is: $"
hlt