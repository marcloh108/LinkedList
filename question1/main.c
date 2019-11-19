#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node * preptr;
    struct node * nextptr;
}
*stnode, *ennode;


void DlListcreation(int n);
int getMaxNode(struct node *stnode);
void displayDlList();

int main()
{
    int n;
    stnode = NULL;
    ennode = NULL;

    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    DlListcreation(n);
    displayDlList();
    printf("\n The Maximum Value in the Linked List : %d\n\n", getMaxNode(stnode));
    return 0;
}

void DlListcreation(int n)
{
    int i, num;
    struct node *fnNode;

    if(n >= 1)
    {
        stnode = (struct node *)malloc(sizeof(struct node));

        if(stnode != NULL)
        {
            printf(" Input data for node 1 : "); // assigning data in the first node
            scanf("%d", &num);

            stnode->num = num;
            stnode->preptr = NULL;
            stnode->nextptr = NULL;
            ennode = stnode;
            for(i=2; i<=n; i++)
            {
                fnNode = (struct node *)malloc(sizeof(struct node));
                if(fnNode != NULL)
                {
                    printf(" Input data for node %d : ", i);
                    scanf("%d", &num);
                    fnNode->num = num;
                    fnNode->preptr = ennode;    // new node is linking with the previous node
                    fnNode->nextptr = NULL;     // set next address of fnnode is NULL
                    ennode->nextptr = fnNode;   // previous node is linking with the new node
                    ennode = fnNode;            // assign new node as last node
                }
                else
                {
                    printf(" Memory can not be allocated.");
                    break;
                }
            }
        }
        else
        {
            printf(" Memory can not be allocated.");
        }
    }
}

int getMaxNode(struct node *stnode)
{
    if(stnode == NULL)
    {
        printf(" User message : Invalid Input !!!!\n");

    }
    int max = stnode->num;
    while(stnode != NULL)
    {
        if(stnode->num > max)
        {
            max = stnode->num;
        }
        stnode = stnode->nextptr;
    }
    return max;
}

void displayDlList()
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
        printf("\n Data entered in the list are :\n");

        while(tmp != NULL)
        {
            printf(" node %d : %d\n", n, tmp->num);
            n++;
            tmp = tmp->nextptr; // current pointer moves to the next node
        }
    }
}
