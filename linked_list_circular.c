#include <conio.h>
#include <malloc.h>
#include <stdio.h>
void del_beg();
void del_end();
void insert_beg();
void insert_end();
void traverse();
int size;
struct node {
  int num;
  struct node *next;
};
typedef struct node NODE;
NODE *rear=NULL;
NODE *first=NULL;

void main(void) {
  int ch;
  char choice;
  clrscr();
  printf("\n Name: Vighnesh Mashnu Pawar \n Roll NO: CS2021");
  do {
    printf("\nCircular Linked List Operations");
    printf("\n1.Insert at begin\n2.insert at end\n3.Delete from begin\n4.Delete from End.");
    printf("\nEnter Your Choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      insert_beg();
      break;
    case 2:
      insert_end();
      break;
    case 3:
      del_beg();
      break;
    case 4:
      del_end();
      break;  
    default:
      printf("wrong choice\n");
    }
    fflush(stdin);
    printf("\n Do you want to continue? y/n : ");
    scanf("%c", &choice);
  } while (choice == 'y' || choice == 'Y');
  exit(0);
  getch();
}
void insert_beg(){
  NODE* newnode;
  newnode=(NODE*)malloc(sizeof(NODE));
  printf("\n Enter Value to be inserted : ");
  scanf("%d",&newnode->num);
  if(first==NULL){
    first=newnode;
    newnode->next=first;
    rear=first;
  }
  else{
    newnode->next=first;
    first=newnode;
    rear->next=first;
  }
 traverse();
}
void insert_end(){
  NODE *newnode;
  newnode=(NODE*)malloc(sizeof(NODE));
  printf("\n Enter Value to be inserted : ");
  scanf("%d",&newnode->num);
  newnode->next=first;
  rear->next=newnode;
  rear=newnode;
  traverse();
}
void del_beg(){
  NODE *ptr=first;
  if (first==NULL || rear==NULL)
  {
    printf("\n Empty");
  }
  else if (first==rear)
  {
    first=rear=NULL;
    free(ptr);
  }
  else{
    first=ptr->next;
    rear->next=first;
    free(ptr);
  }
  traverse();
}
void del_end(){
  NODE *temp,*ptr;
  temp=first;
  if (rear==first)
  {
    ptr=first;
    rear=first=NULL;
    free(ptr);
  }
  else{
    while (temp->next!=rear)
    { 
      temp=temp->next;
    }
    ptr=rear;
    rear=temp;
    rear->next=first;
    free(ptr);
  } 
  traverse();
}
void traverse(){
  NODE *temp=first;
  if (temp==NULL)
  {
    printf("\n Empty");
  }
  else{
  printf("\n");
  while (temp->next!=first)
  {
    printf("%d\t",temp->num);
    temp=temp->next;
  }
   printf("%d",temp->num);
  }
}
