#include <stdio.h>
#include <conio.h>
#include <malloc.h>
void main ()
{
    printf("\n Name: Vighnesh  ");
    struct node
    {
        int num;
        struct node *next;
    };
    typedef struct node NODE;
    NODE *start, *first, *temp;
    start = NULL;
    first = NULL;
    temp = NULL;
    int count = 0;
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
        // fflush(stdin);
        printf("\n Do you want to continue? y/n: ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    temp->next = NULL;
    temp = first;
    printf("\n ***The Status Of Linked List***\n");
    while (temp != NULL)
    {
        printf("%d\t", temp->num);
        temp = temp->next;
        count++;
    }
    printf("\n Number Of nodes: %d", count);
    getch();
}
