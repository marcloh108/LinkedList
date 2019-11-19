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
void displayDlListRev();

int main()
{
    int n;
    stnode = NULL;
    ennode = NULL;

    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    DlListcreation(n);
    displayDlListRev();
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
void displayDlListRev()
{
    struct node *tmp;
    int n = 0;
    if(ennode == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else {
      tmp = ennode;
      printf("\n\n Data in reverse order are :\n");

      while(tmp!=NULL)
      {
          printf(" Data in node %d : %d\n", n+1, tmp->num);
          n++;
          tmp = tmp->preptr;

      }
    }
}
