
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct queue {
    int no;
    struct queue *next;
};
struct queue *f=0;
struct queue *r=0;
void insert();
int delete();
void display();
void main()
{
    int n, ch;
   char choice;
    // clrscr();
   printf("\n Name: Vighnesh ");
    do
    {
        printf("\n\nQueue Menu\n1. insert \n2. delete\n3. Display");
        printf("\nEnter Choice 1-3? : ");
        scanf("%d", &ch);
        switch (ch)
        {
	    case 1:
		  insert();
                break;
	    case 2:
	      printf("deleted element is %d",delete());
		break;
	    case 3:
		display();
		break;
	    }
	printf("\n Do you want to continue? y/n : ");
    scanf("%s",&choice);
    }while(choice=='y' || choice=='Y');
    exit(0);
}
void insert(){
    struct queue *node;
    node=(struct queue*)malloc(sizeof(struct queue));
    printf("Enter num ");
    scanf("%d",&node->no);
    node->next=NULL;
    if (f==0 && r==0)
    {
        f=node;
        r=node;
    }
    else{
        r->next=node;
        r=r->next;
    }
    
}
void display(){
    struct queue *temp;
    temp=f;
    if(f==0 && r==0)
    {
     printf("queue is empty");
    }
    else{
	while(temp!=0)
	{
	    printf("%d \t",temp->no);
	    temp=temp->next;
	}
 }
}
int delete(){
	struct queue *temp;
    temp=f;
	int item;
	if(f==0 && r==0)
	{
	printf("queue is empty");
	getch();
	exit(0);
	}
	else
	{
	item=temp->no;
	f=f->next;
	}
    free(temp);
	return(item);
 }
