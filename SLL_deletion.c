#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct Node
{
int data;
struct Node *link;

};
typedef struct Node node;
node *start=NULL;
void create();
void delete_beg();
void delete_end();
void delete_pos();
void display();
int main()
{
int choice;
while(1)
{
printf("1.create 2.delete at first position 3.delete at end 4.delete at required position 5.display 6.exit\n");
printf("enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:create();
       break;
case 2:delete_beg();
       break;
case 3:delete_end();
       break;
case 4:delete_pos();
       break;
case 5:display();
       break;
case 6:exit(0);
       break;
default:printf("invalid choice\n");
}
}
return 0;
}
void create()
{
if(start==NULL)
{
 int ch;
node *new,*curr;
start=(node *)malloc(sizeof(node));
printf("enter element\n");
scanf("%d",&start->data);
curr=start;
while(1)
{
printf("do you want to add another element(1/0)\n");
scanf("%d",&ch);
if(ch==1)
{
new=(node *)malloc(sizeof(node));
printf("enter element\n");
scanf("%d",&new->data);
curr->link=new;
curr=new;
}
else
{
curr->link=NULL;
break;
}
}
}else
{
printf("linked list already exists\n");
}
}
void delete_beg()
{
 node *temp;
if(start==NULL)
{
printf("linked list is empty\n");
}
else
{
temp=start;
start=start->link;
free(temp);
}
}
void delete_end()
{
node *temp,*prev,*next;
if(start==NULL)
{
printf("linked list is empty\n");
}
else
{
if(start->link==NULL)
{
free(start);
start=NULL;
}
else
{
prev=start;
next=start->link;
while(next->link!=NULL)
{
prev=next;
next=next->link;
}
prev->link=NULL;
free(next);
}
}
}
void delete_pos()
{
if(start==NULL)
{
printf("linked list is empty\n");
}
else
{
int ele;
node *prev,*next;
printf("enter element to be deleted\n");
scanf("%d",&ele);
if(start->data==ele)
{
free(start);
start->link=NULL;
printf("element is deleted\n");
}
else
{
prev=start;
next=start->link;
while(next->data!=ele&&next!=NULL)
{
prev=next;
next=next->link;
}
if(next->data==ele)
{
prev->link=next->link;
free(next);
}
else
{
printf("element not found\n");
}
}
}
}
void display()
{
node *temp;
if(start==NULL)
{
printf("linked list is empty\n");
return;
}
temp=start;
printf("Contents of linked list:\n");
while(temp!=NULL)
{
printf("%d\n",temp->data);
temp=temp->link;
}
}
