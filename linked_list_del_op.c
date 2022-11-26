#include <conio.h>
#include <malloc.h>
#include <stdio.h>
void del_first();
void del_end();
void del_spe();
void create_list();
void traverse();
int size;
struct node {
  int num;
  struct node *next;
};
typedef struct node NODE;
NODE *start=NULL;
NODE *first=NULL;
NODE *temp=NULL;

void main(void) {
  int ch;
  char choice;
 clrscr();
  printf("\n Name: Vighnesh");
  create_list();
  do {
    printf("\nLinked List Operations");
    printf("\n1.Delete the last\n2.Delete from spec pos\n3.Delete the first");
    printf("\nEnter Your Choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      del_end();
      break;
    case 2:
      del_spe();
      break;
    case 3:
      del_first();
      break;
    default:
      printf("wrong choice\n");
    }
    fflush(stdin);
    printf("\n Do you want to continue? y/n : ");
    scanf("%c", &choice);
  } while (choice == 'y' || choice == 'Y');
  exit(0);
}
void del_first() {
  NODE *ptr;
  if (start==NULL)
  {
    printf("\n List is empty");
    return;
  } 
  else {
    ptr = first;
    first = first->next;
    free(ptr);
  }
  traverse();
}

void del_end(){
  NODE *ptr,*loc;
    if (start==NULL)
  {
    printf("\n List is empty");
    return;
  }
  else{
    if(first->next==NULL){
      ptr=first;
      temp=first=start=NULL;
      free(ptr);
    }
   else{
     loc=first;
     ptr=first->next;
     while(ptr->next!=NULL){
       loc=ptr;
       ptr=ptr->next;
     } 
     loc->next=NULL;
     free(ptr);
   }
  }
  traverse();
}
  

void del_spe(){
  NODE *ptr,*loc;
  int a;
  printf("\n Enter Element Which you want to delete : ");
  scanf("%d",&a);
  if (start==NULL)
  {
    printf("\n List is empty");
    return;
  }
  if (first->num==a)
  {
   first =first->next;
  }
  else{
    loc=first;
    ptr=loc->next;
    while (ptr!=NULL)
    {
      if (ptr->num==a)
      {
        loc->next=ptr->next;
        ptr=NULL;
      }
      else{
        loc=ptr;
        ptr=ptr->next;
      }
    }
  }
  free(ptr);
  traverse();
}    

void traverse(){
 NODE* ptr=first;
 size=0;
 printf("\n");
  while (ptr != NULL)
    {
        printf("%d\t",ptr->num);
        ptr = ptr->next;
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
