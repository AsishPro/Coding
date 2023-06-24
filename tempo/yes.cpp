org 100h

.data
a db 6,7,5,3,9,4,1,2,9
ln db 10,13,"$" 
temp dw ?


.code  
mov dx,@data
mov ds,dx       

mov cx,9h
l0: 
mov temp,cx

mov cx,temp
mov si,0  
mov di,si
inc di 
 
l1:
mov al,a[di]
cmp a[si],al
jle l2
mov bh,a[si]
mov bl,a[di]
mov a[si],bl
mov a[di],bh
l2:
inc si
inc di
         
loop l1
        
mov cx,temp

loop l0   
            
   
   
   
mov si,0 
mov dx,0  
mov cx,9
lk:
mov dl,a[si]  
add dl,48
mov ah,2h
int 21h 
inc si
loop lk





hlt

