#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define maxsize 3
int cqueue[maxsize];
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
    printf("\nCircular Queue Operations");
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
    if(f==(r+1)%maxsize){
        printf("Overflow");
    }
    else{
        if(f==-1){
            f=r=0;
        }
        else{
           r=(r+1)%maxsize;  
        } 
        cqueue[r]=value; 
    }
}
int delete(){
    int value;
    if(f==-1){
        printf("\n Underflow");
        getch();
        exit(0);
    }
    else{
        value=cqueue[f];
        if(f==r){
            f=r=-1;
        }
        else{
            f=(f+1)%maxsize;
        }
    }
    return(value);
}
void display(){
   int i;
   for ( i = f; i !=r; i=(i+1)%maxsize)
   {
    printf("%d\t",cqueue[i]);
   }
   printf("%d",cqueue[i]);
}
