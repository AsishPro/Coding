 
; ds - data segment register has address
    
org 100h 

.data
a db 5,4,3,2,1,6,8,9,3

.code
mov ax,@data   
mov ds,ax      ;directly cannot be moved
mov cx,9h
mov si,0h


l1:
mov dl,a[si]
add dl,48
mov ah,2h
int 21h 
mov dl,0
mov ah,2h
int 21h
inc si
loop l1

hlt
