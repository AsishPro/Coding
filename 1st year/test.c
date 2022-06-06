/*#include <stdio.h>
struct node{
    int data;
    struct node *ptr;
};
int main(){
    struct node *head=NULL;
    printf("%p",head);
    if(head==NULL)
    printf("\nYep it works");
} */
#include <stdio.h>
int call(int k){
    static int j=0;
    printf("%d ",j);
    j++;
    if(j==7)
    return 0;
    int z=0;
    call(z);
    
}
int main(){
    int m=0;
    call(m);

}