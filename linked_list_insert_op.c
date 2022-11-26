#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void insert_begin(int);
void insert_end(int);
void insert_spe(int, int );
void traverse();
void create_list();
int size;
struct node
{
    int num;
    struct node *next;
};

typedef struct node NODE;
NODE *start=NULL;
NODE *first=NULL;
NODE *temp=NULL;
void main()
{  
    int ch, item;
    char choice;
    clrscr();
    
    printf("\n Name: Vighnesh");
    create_list();
    do
    {
        printf("\nlinked list Operations");
        printf("\n1.Insert at begin\n2.Insert at End\n3.Insert at specific Position\n4.traverse\n5.exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter Element :");
            scanf("%d", &item);
            insert_begin(item);
            break;
        case 2:
            printf("\nEnter Element :");
            scanf("%d", &item);
            insert_end(item);
            break;
        case 3:
            printf("\nEnter Element :");
            scanf("%d", &item);
            printf("\nEnter location :");
            scanf("%d", &ch);
            insert_spe(item, ch);
            break;
        case 4:
            traverse();
            break;
        case 5:
            exit(0);
        default:
            printf("wrong choice\n");
        }
        printf("\n Do you want to continue? y/n : ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    exit(0);
}
void insert_begin(int item)
{
    NODE *newnode = 0;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->num = item;
    if (newnode== 0)
    {
        printf("\n Memory Not Allocated");
    }
    else
    {
       newnode->next=first;
       first=newnode; 
    }
    traverse();
}
void insert_end(int item){
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->num = item;
    if (newnode== 0)
    {
        printf("\n Memory Not Allocated");
    }
    else
    {
       temp->next=newnode;
       temp=newnode;
       newnode->next=NULL; 
    }
    traverse();
}
void insert_spe(int item,int loc){
    NODE *newnode,*ptr;
    int i;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->num = item;
    ptr=first;
    if(loc<1 || loc>size){
        printf("Invalid postion");
    }
   else if (loc==1)
    {
        newnode ->next = ptr;
        first=newnode;
    }
   
    else{
    for ( i = 0; i+2< loc; i++)
    {
        ptr=ptr->next;
        if(ptr==NULL){
            printf("Node in the list less than one");
        }
    }
   newnode ->next = ptr ->next;   
   ptr ->next =newnode;
    } 
 traverse();
}
void traverse(){
 NODE* temp=first;
 size=0;
 printf("\n");
  while (temp != NULL)
    {
        printf("%d\t",temp->num);
        temp = temp->next;
        size++;
    }
}
void create_list(){
 char choice;
    do
    {
        start = (NODE *)malloc(sizeof(NODE));
        printf("\n Enter Data item : ");
        scanf("%d", &start->num);
        if (first != 0)
        {
            temp->next = start;
            temp = start;
        }
        else
        {
            first = temp = start;
        }
         fflush(stdin);
        printf("\n Do you want to continue? y/n: ");
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');
    temp->next = NULL;
    printf("\n Elements List To do Operations ");
    traverse();
}
