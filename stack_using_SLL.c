#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
typedef struct Node node;
node *top=NULL;
void push();
void pop();
void display();
int main()
{
    int choice;
    while(1)
    {
        printf("\n1.Push 2.Pop 3.Display 4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();
                   break;
            case 2:pop();
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

void push()
{
    node *new;
    new=(node *)malloc(sizeof(node));
    printf("\nEnter the element:");
    scanf("%d",&new->data);
    if(top==NULL)
    {
        top=new;
        top->link=NULL;
    }
    else
    {
        new->link=top;
        top=new;
    }
}

void pop()
{
    if(top==NULL)
    {
        printf("\nStack Underflow");
    }
    else
    {
        node *temp;
        temp=top;
        top=top->link;
        printf("\nPopped element:%d",temp->data);
        free(temp);
    }
}

void display()
{
    node *temp;
    if(top==NULL)
    {
        printf("\nStack is empty");
    }
    else
    {
        temp=top;
        printf("\nStack contains:\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->link;
        }
    }
}
