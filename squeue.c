#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define maxsize 2
int queue[maxsize];
void insert();
int delete();
void display();
int f=-1;
int r=-1;
void main() {
    int ch;
    char choice;
    // clrscr();
    printf("\n Name: Vighnesh  ");
    do{
    printf("\nQueue Operations");
    printf("\n1.Insertion\n2.Deletion\n3.display\n");
    printf("Enter Your Choice: ");
    scanf("%d",&ch);
    switch (ch) 
    {
    case 1:
       insert();
        break;
    case 2:
       printf("\nDeleted Element is : %d ",delete());
        break;
    case 3:
        display();
        break;
    default:
        printf("wrong choice\n");
    }
    printf("\n Do you want to continue? y/n : ");
    scanf("%s",&choice);
    }while(choice=='y' || choice=='Y');
    exit(0);
}    

void insert(){
    int value;
    printf("\n Enter Value : ");
    scanf("%d",&value);
    if(r==-1){
        f=r=0;
    }
    else{
        if(r>=maxsize-1){
           printf("\nQueue is overflow");
        }
        else{
           r++;
        }  
    }
    queue[r]=value;
}
int delete(){
    int item;
    if(f>r){
        printf("\n Underflow");
        exit(0);
        getch();
    }
    else{
        item=queue[f];
        f++;   
        }
        return(item);
}
void display(){
   int i;
   for ( i = f; i <=r; i++)
   {
    printf("%d\t",queue[i]);
   }
}
