#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct Node
{
 int data;
 struct Node *link;
};
typedef struct Node node;
node *start1=NULL;
node *start2=NULL;
void create();
void create1();
void sort();
void reverse();
void concatenate();

int main()
{
 int choice;

 while(1)
 {
  printf("\n1.Create linked list1 2.Create linked list2 3.Sort 4.Reverse 5.Concatenate 6.Exit\n");
  printf("enter your choice\n");
  scanf("%d",&choice);
  switch(choice)
 {
  case 1:create();
         break;
  case 2:create1();
         break;
  case 3:sort();
         break;
  case 4:reverse();
         break;
  case 5:concatenate();
         break;
  case 6:exit(0);
         break;
  default:printf("Invalid Choice\n");
}
}
return 0;
}

void create()
{
    int c;
    node *new,*curr;
    start1=(node *) malloc(sizeof(node));

    printf("Enter element\n");
    scanf("%d",&start1->data);
    curr=start1;
    while(1)
    {
        printf("Do you want to add another element(1/0)\n");
        scanf("%d",&c);
        if(c==1)
        {
            new=(node *) malloc(sizeof(node));
            printf("Enter element\n");
            scanf("%d",&new->data);
            curr->link = new;
            curr=new;
        }
        else
        {
            curr->link=NULL;
            break;
        }
    }
}

void create1()
{
    int c;
    node *new,*curr;
    start2=(node *) malloc(sizeof(node));

    printf("Enter element\n");
    scanf("%d",&start2->data);
    curr=start2;
    while(1)
    {
        printf("Do you want to add another element(1/0)\n");
        scanf("%d",&c);
        if(c==1)
        {
            new=(node *) malloc(sizeof(node));
            printf("Enter element\n");
            scanf("%d",&new->data);
            curr->link = new;
            curr=new;
        }
        else
        {
            curr->link=NULL;
            break;
        }
    }
}

void sort()
{
 int t,n,i,j,count=0;
 node *a,*b,*temp,*te;
 temp=start1;
 while(temp!=NULL)
 {
     count++;
     temp=temp->link;
 }
 n=count;
 a=start1;
 b=start1->link;
 for(i=0;i<n-1;i++)
 {
     for(j=0;j<n-i-1;j++)
     {
         if(a->data>b->data)
         {
             t=a->data;
             a->data=b->data;
             b->data=t;
         }
         a=b;
         b=b->link;
     }
     a=start1;
     b=start1->link;
 }
 printf("\nSorted Linked List contains:\n");
 te=start1;
 while(te!=NULL)
 {
   printf("%d ",te->data);
   te=te->link;
  }
}

void reverse()
{
    node *t;
    node *a=start1;
    node *b=NULL;
    node *c=NULL;
    if(start1==NULL)
    {
        printf("\nLinked List is empty");
    }
    else
    {
    while(a!=NULL)
    {
        c=b;
        b=a;
        a=a->link;
        b->link=c;
    }
    }
    start1=b;
    printf("\nReversed Linked List contains:\n");
    t=start1;
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->link;
    }

}

void concatenate()
{
    node *start3,*temp,*t;
    if(start1==NULL)
    {
        start3=start2;
    }
    else
    if(start2==NULL)
    {
     start3=start1;
    }
    else
    {
        temp=start1;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=start2;
        start3=start1;
    }
    if(start3==NULL)
    {
        printf("\nConcatenated Linked List is empty");
    }
    else
    {
    printf("\nConcatenated Linked List contains:\n");
    t=start3;
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->link;
    }
    }

}
