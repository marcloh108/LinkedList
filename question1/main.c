#include <stdio.h>
#include <stdlib.h>

struct node
{
  int num;
  struct node * preptr;
  struct node *nextptr;
}

*stnode, *ennode;

void DlListcreation(int n);
void displayDlList(int m);
void DlLinsertNodeAtBeginning(int num);

int main()
{
    int n, num1, a;
    stnode = NULL;
    ennode = NULL;

    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    DlListcreation(n);
    a = 1;
    displayDlList(a);
    printf(" Input data for the first node : ");
    scanf("%d", &num1);
    DlLinsertNodeAtBeginning(num1);
    a=2;
    displayDlList(a);
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
            printf(" Input data for node 1 : ");
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
                    fnNode ->num = num;
                    fnNode->preptr = ennode;
                    fnNode->nextptr = NULL;

                    ennode->nextptr = fnNode;
                    ennode = fnNode;
                }
                else
                {
                    printf(" Memory can not be allocated");
                }
            }
        }
    }
}

void DlLinsertNodeAtBeginning(int num)
{
    struct node * newnode;
    if(stnode == NULL)
    {
        printf(" No data found in the list\n");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->num = num;
        newnode->nextptr = stnode;
        newnode->preptr = NULL;
        stnode->preptr = newnode;
        stnode = newnode;
    }
}
void displayDlList(int m)
{
    struct node *tmp;
    int n = 1;
    if(stnode == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else {
      tmp = stnode;
      if(m == 1)
      {
          printf("\n Data entered in the list are :\n");
      }
      else
      {
          printf("\n After insertion the new list are :\n");
      }
      while(tmp!=NULL)
      {
          printf(" node %d : %d\n", n+1, tmp->num);
          n++;
          tmp = tmp->nextptr;

      }
    }
}
