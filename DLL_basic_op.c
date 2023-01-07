#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *Llink;
    struct Node *Rlink;
};
typedef struct Node node;
node *start=NULL;
void create();
void insert_left();
void delete_req();
void display();

int main()
{
    int choice;
    while(1)
    {
        printf("\n1.Create 2.Insert Left 3.Delete required element 4.Display 5.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:create();
                   break;
            case 2:insert_left();
                   break;
            case 3:delete_req();
                   break;
            case 4:display();
                   break;
            case 5:exit(0);
                   break;
            default:printf("\nInvalid Choice");
        }
    }
    return 0;
}

void create()
{
    int c;
    node *new,*curr;
    start=(node *)malloc(sizeof(node));
     printf("\nEnter the element:");
     scanf("%d",&start->data);
     start->Llink=NULL;
     curr=start;
     while(1)
     {
        printf("\nDo you want to enter another element(1/0):");
        scanf("%d",&c);
        if(c==1)
        {
            new=(node *)malloc(sizeof(node));
            printf("\nEnter element:");
            scanf("%d",&new->data);
            curr->Rlink=new;
            new->Llink=curr;
            curr=new;
        }
        else
        {
            curr->Rlink=NULL;
            break;
        }

     }
}

void insert_left()
{
        node *new;
        new=(node *)malloc(sizeof(node));
        printf("\nEnter element:");
        scanf("%d",&new->data);
        if(start==NULL)
        {
            start=new;
            start->Llink=NULL;
            start->Rlink=NULL;
        }
        else
        {
            new->Rlink=start;
            start->Llink=new;
            start=new;
            start->Llink=NULL;
        }
}

void delete_req()
{
    int ele;
    printf("\nEnter the element to be deleted:");
    scanf("%d",&ele);
    if(start==NULL)
    {
        printf("\nDoubly Linked List is Empty");
        printf("\nElement not found");
    }
    else
    if(start->data==ele)
    {
        node *temp;
        temp=start;
        start=start->Rlink;
        start->Llink=NULL;
        free(temp);
        printf("\nElement deleted");
    }
    else
    {
        node *temp;
        temp=start;
        while(temp->data!=ele&&temp->Rlink!=NULL)
        {
            temp=temp->Rlink;
        }
        if(temp->data==ele&&temp->Rlink==NULL)
        {
            temp->Llink->Rlink=NULL;
            free(temp);
            printf("\nElement deleted");
        }
        else
        if(temp->data==ele&&temp->Rlink!=NULL)
        {
            temp->Llink->Rlink=temp->Rlink;
            temp->Rlink->Llink=temp->Llink;
            free(temp);
            printf("\nElement deleted");
        }
        else
        {
            printf("\nElement not found");
        }
    }
}

void display()
{
    if(start==NULL)
    {
        printf("\nDoubly Linked List is empty");
    }
    else
    {
        node *temp;
        temp=start;
        printf("\nDoubly Linked List contains:\n");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->Rlink;
        }
    }
}
