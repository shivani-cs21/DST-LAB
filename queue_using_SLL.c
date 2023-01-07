#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
typedef struct Node node;
node *rear=NULL;
node *front=NULL;
void insert();
void delete();
void display();
int main()
{
    int choice;
    while(1)
    {
        printf("\n1.Insert 2.Delete 3.Display 4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert();
                   break;
            case 2:delete();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
                   break;
            default:printf("\nInvalid Choice");
        }
    }
    return 0;
}

void insert()
{
    node *new;
    new=(node *)malloc(sizeof(node));
    printf("\nEnter the element:");
    scanf("%d",&new->data);
    if(rear==NULL)
    {
        rear=new;
        front=new;
        rear->link=NULL;
    }
    else
    {
        rear->link=new;
        rear=new;
        rear->link=NULL;
    }
}

void delete()
{
    node *temp;
    if(front==NULL)
    {
        printf("\nQueue is empty");
    }
    else
    {
        temp=front;
        front=front->link;
        printf("\nDeleted element:%d",temp->data);
        free(temp);
    }
}

void display()
{
    node *temp;
    if(front==NULL)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nQueue contains:\n");
        temp=front;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->link;
        }
    }
}
