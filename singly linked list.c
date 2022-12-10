#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *nextptr;
}*stnode;

void create(int n);
void display();

int main()
{
    int n;
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    create(n);
    printf("\n The content of linked list is : \n");
    display();
    return 0;
}
void create(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));

    if(stnode == NULL)
    {
    printf(" Memory can not be allocated.");
    }
    else
    {


        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        stnode->num = num;
        stnode->nextptr = NULL;
        tmp = stnode;

        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);

                fnNode->num = num;
                fnNode->nextptr = NULL;

                tmp->nextptr = fnNode;
                tmp = tmp->nextptr;
            }
            }
    }
}
void display()
{
    struct node *tmp;
    if(stnode == NULL)
    {
        printf(" List is empty.");
        return;
    }
    else
    {
        tmp = stnode;

        while(tmp != NULL)
        {
            printf("%d\t", tmp->num);
            tmp = tmp->nextptr;
        }
    }
}
