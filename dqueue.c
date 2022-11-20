#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define maxsize 2
int f=-1;
int r=-1;
int item;
void dqinsert_queue(int [],int ,int ,int ,int );
void dqdelete_queue(int [],int ,int );
void dqinsert_front(int [],int ,int ,int );
void dqdelete_rear(int [],int ,int );
void display(int [],int, int);
int dq[maxsize];
void main() {
    int ch;
    char choice;
    // clrscr();
    printf("\n Name: Vighnesh ");
    do{
    printf("\nDeQueue Operations");
    printf("\n1.Insert from rear end  \n2.Delete element from front end");
    printf("\n3.Insert from front end\n4.Delete element from rear end \n5.Display");
    printf("\nEnter Your Choice: ");
    scanf("%d",&ch);
    switch (ch) 
    {
    case 1:
       printf("\n Enter Number :");
       scanf("%d",&item);
       dqinsert_queue(dq,f,r,item,maxsize );
        break;
    case 2:
      dqdelete_queue(dq,f,r);
        break;
    case 3:
        printf("\n Enter Number :");
        scanf("%d",&item);
        dqinsert_front(dq,f,r,item );
        break;
    case 4:
        dqdelete_rear(dq,f,r);
        break;
    case 5:
        display(dq,f,r);
        break;        
    default:
        printf("wrong choice\n");
    }
    printf("\n Do you want to continue? y/n : ");
    scanf("%s",&choice);
    }while(choice=='y' || choice=='Y');
    exit(0);
}    
void display(int dq[],int front,int rear){
   int i;
   
   for ( i =front; i <=rear; i++)
   {
    printf("%d\t",dq[i]);
   }
}
void dqinsert_queue(int dq[],int front,int rear,int value,int size)
{    
    if (rear==-1)
    {
      rear=front=0;
    }
    else{
    if (rear==size-1)
    {
        printf("\n Queue is full");
    } 
    else{
        rear=rear+1;
    }
    }
    dq[rear]=value;
    f=front;
    r=rear;
}
void dqdelete_queue(int dq[],int front,int rear)
{
    if (front>rear||front==-1)
    {
        printf("\n Queue is empty");
    }
    else{
        item=dq[front];
        front++;
    }
    f=front;
    r=rear;
}
void dqinsert_front(int dq[],int front,int rear,int value){
    if (front==-1 || rear==-1)
    {
       front++;
       rear++;
        dq[front]=value;
    }
    
    else if (front==0)
    {
        printf("\n Queue is full");
       
    }
    else{
        front--;
        dq[front]=value;
    }
    f=front;
    r=rear;
}
void dqdelete_rear(int dq[],int front,int rear)
{
    if (r<f)
    {
        printf("\n Queue is Empty");
    }
    else{
        item=dq[rear];
        rear--;
    } 
    f=front;
    r=rear;
}
