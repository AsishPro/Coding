#include <stdio.h>
int main(){
    int n,x,count=0;   //declaring variables
    printf("Enter the Size of Array: ");
    scanf("%d",&n);    //input size
    int a[n];
    printf("Enter the Elements\n");  //input array 
    for(int i=0;i<n;i++){
        printf("Enter the Element %d: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter the Element to find Occurrence: ");
    scanf("%d",&x);      //input search element
    int i=0;
    while(i<n){          //checking for occurance
        if(a[i]==x)
        count++;
      i++;
    }
    printf("The Element %d Occurrence:%d in Given Array of Elements",x,count);
}