org 100h

.data 
msg db "Enter the input: $"   
ln db 13,10,"$"  
m1 db " Even$"
m2 db " Odd $" 
s1 db ? 
s2 db ?

.code 
lea dx,msg
mov ah,9h
int 21h

mov ah,1h
int 21h 
         
mov cl,al

lea dx,ln
mov ah,9h
int 21h 
        
mov dl,cl 
mov ah,2h 
int 21h 
          
sub dl,48 
mov s1,dl
       
mov ax,0
mov al,s1 
mov bl,2
div bl

mov s2,ah  

cmp s2,0
je l1  
lea dx,m2
mov ah,9h   
int 21h 
mov ah,4ch
int 21h 

l1:   
lea dx,m1
mov ah,9h   
int 21h      
mov ah,4ch 
int 21h         
          
hlt


