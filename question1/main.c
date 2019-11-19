#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node * nextptr;
}
*stnode;

struct node *tail, *p, *q, *store;


void ClListcreation(int n);
void ClLinsertNodeAtEnd(int num);
void displayClList(int a);

int main()
{
    int n, num1, a;
    stnode = NULL;

    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    ClListcreation(n);
    a = 1;
    displayClList(a);
    printf(" Input data to be inserted : ");
    scanf("%d", &num1);
    ClLinsertNodeAtEnd(num1);
    a = 2;
    displayClList(a);
    return 0;
}

void ClListcreation(int n)
{
    int i, num;
    struct node *preptr, *newnode;

    if(n >= 1)
    {
            stnode = (struct node *)malloc(sizeof(struct node));
            printf(" Input data for node 1 : "); // assigning data in the first node
            scanf("%d", &num);
            stnode->num = num;
            stnode->nextptr = NULL;
            preptr = stnode;
            for(i=2; i<=n; i++)
            {
                    newnode = (struct node *)malloc(sizeof(struct node));
                    printf(" Input data for node %d : ", i);
                    scanf("%d", &num);
                    newnode->num = num;
                    newnode->nextptr = NULL;
                    preptr->nextptr = newnode;
                    preptr = newnode;
             }
                preptr->nextptr = stnode;
    }
}

void ClLinsertNodeAtEnd(int num)
{
    int a;
    a=num;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->num=a;
    p = stnode;
        while(p->nextptr!=stnode)
        {
           p=p->nextptr;
        }
        p->nextptr=temp;
        temp->nextptr=stnode;

}
void displayClList(int m)
{
    struct node * tmp;
    int n = 1;
    if(stnode == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        tmp = stnode;
        if (m==1)
        {
        printf("\n Data entered in the list are :\n");
        }
        else
        {
            printf("\n After insertion the new list are :\n");
        }
        do
        {
            printf(" Data %d : %d\n", n, tmp->num);
            n++;
            tmp = tmp->nextptr; // current pointer moves to the next node
        }while(tmp != stnode);
    }
}
