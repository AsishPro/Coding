org 100h 

.data
s1 db ?
s2 db ?


.code   



mov al,4 
mov cl,al
dec cl  

l1: 
mul cl
loop l1
 
mov s1,al

mov al,2
mov cl,al
dec cl

l2: 
mul cl
loop l2

mov s2,al


mov ax,0
mov al,s1
div s2

mov dl,al  
add dl,48
mov ah,2h
int 21h

hlt