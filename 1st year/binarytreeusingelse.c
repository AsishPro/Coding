#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node *insert(struct node *root,int item){
  if(root==NULL){
      struct node *ptr=malloc(sizeof(struct node));
      ptr->data=item;
      ptr->left=NULL;
      ptr->right=NULL;
      return ptr;
  }
  if(root->data<item)
     root->right=insert(root->right,item);
  if(root->data>item)
    root->left=insert(root->left,item);
    return root;
  }

void inorder(struct node *root){
    if(root==NULL)
        return;
    
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main(){
    struct node *root=NULL;
    while(1){
    int ch;
    printf("\n\nBinary Tree:\n1.Insertion of Elements\n2.Inorder Expression\n3.Exit\n");
    scanf("%d",&ch);
    if(ch==1){
        int n;
      printf("Enter the number of elements in Binary Tree:");
      scanf("%d",&n);
      int a[n];
      for(int i=0;i<n;i++){
         printf("Enter the data Element %d:",i+1);
         scanf("%d",&a[i]);
         root=insert(root,a[i]);
     }
    }
    else if(ch==2)
    inorder(root);
    else
    printf("\nEnter a Valid Input");
}
}