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
void preorder(struct node *root){
  if(root==NULL)
  return;
  printf("%d ",root->data);
  preorder(root->left);
  preorder(root->right);
}
void inorder(struct node *root){
    if(root==NULL)
        return;
    
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(struct node *root){
  if(root==NULL)
  return;

  postorder(root->left);  
  postorder(root->right);
  printf("%d ",root->data);
}

int main(){
    struct node *root=NULL;
    while(1){
    int ch;
    printf("\n\nBinary Tree:\n1.Insertion of Elements\n2.Preorder Expression\n3.Inorder Expression\n4.Postorder Expression\n5.Exit\n");
    scanf("%d",&ch);
    switch(ch){
    case 1: {
      int n;
      printf("Enter the number of elements in Binary Tree:");
      scanf("%d",&n);
      int a[n];
      for(int i=0;i<n;i++){
         printf("Enter the data Element %d:",i+1);
         scanf("%d",&a[i]);
         root=insert(root,a[i]);
     }
      break;
    }
    case 2:
    preorder(root);
    break;
    case 3:
    inorder(root);
    break;
    case 4:
    postorder(root);
    break;
    case 5:
    exit(0);
    break;
    default:
    printf("\nEnter a Valid Input");
}
}
}