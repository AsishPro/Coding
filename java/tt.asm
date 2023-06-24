org 100h   
  
MOV AH, 1   ;AH=1,Single key input
INT 21H  

MOV AH,02H
ADD AH,03H 
ADD AH,02H

MOV Dl,AH  
ADD Dl,48 
MOV AH,2 



INT 21H
HLT