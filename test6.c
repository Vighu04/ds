#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct rec
{
    int num;
    struct rec *left,*right;
};
struct rec *tree=NULL;

struct rec *insert(struct rec*,long);
void inorder(struct rec*);
void preorder(struct rec*);
void postorder(struct rec*);
int select();
int count=1;

void main(){
    int ch;
    long digit;
     clrscr();
    printf("\n Name:Vighnesh\nRoll No.:CS2021");
    do
    {
        ch=select();
        switch (ch)
        {
        case 1:
              printf("\n Enter integer (for quiet 0) : ");
              scanf("%d",&digit);
              while (digit!= 0)
              {
                tree =insert(tree,digit);
                printf("\n Enter integer (for quiet 0) : ");
                scanf("%d",&digit);
              }
              continue;
        case 2: printf("\n Preorder TRAversing");
                preorder(tree);
                continue;
        case 3:
              printf("\n Inorder traversing ");
              inorder(tree);
              continue;
        case 4: 
               printf("\n Postorder traversing");
               postorder(tree);
               continue;
        case 5:
                printf("\n End ");
                exit(0);                    
        }
    } while (ch!=5);
    
}
int select(){
    int selection;
    do
    {
        printf("\n1.Insert Node in Binary tree\n2.Display Preorder Binary tree");
        printf("\n3.Display Inorder Binary tree\n4.Display Postorder Binary tree");
        printf("\n5.end");
        printf("\nEnter your choice: ");
        scanf("%d",&selection);
        if ((selection>5) || (selection<1))
        {
            printf("\n!! Try Again !!");
        }
        
    } while ((selection>5) || (selection<1));
    return(selection);
}
struct rec* insert(struct rec*tree,long digit){
    if (tree==NULL)
    {
        tree=(struct rec*)malloc(sizeof(struct rec));
        tree->left=tree->right=NULL;
        tree->num=digit;
        count++;
    }
    else
    {
        if(count%2==0){
            tree->left=insert(tree->left,digit);
        }
        else
        {
            tree->right=insert(tree->right,digit);
        }  
    }
    return(tree);
}
void inorder(struct rec *tree){
    if (tree!=NULL)
    {
        inorder(tree->left);
        printf("\n%d",tree->num);
        inorder(tree->right);
    } 
}
void preorder(struct rec *tree){
    if (tree!=NULL)
    {
        printf("\n%d",tree->num);
        preorder(tree->left);
        preorder(tree->right);
    } 
}
void postorder(struct rec *tree){
    if (tree!=NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("\n%d",tree->num);
    }
}
