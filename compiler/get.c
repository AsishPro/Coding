#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("INPUT.TXT","r");
    if(fp == NULL){
        printf("Error opening file.\n");
        return 1;
    }
    int c = fgetc(fp);  

    while (c!=EOF){   // Read the first character from the file
       putchar(c);   // Print the character to the standard output
       c=fgetc(fp); // Read the next character from the file
    }

    fclose(fp);eturn 0;

    
}
