#include<stdio.h>
#include<conio.h>
#define size 3
void insert();
void delete();
void display();
int queue [size],front=-1,rear=-1;
void main()
{
int choice ;
while(1)
{
printf("1.insert 2.delete 3.display 4.exit\n");
printf("enter your choice\n");
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
default:printf("invalid choice\n");
}
}
getch();
}
void insert()
{
if((front==0&&rear==size-1)||(front==rear+1))
{
printf("queue is full\n");
}
else
{
int item;
if(front==-1 && rear==-1)
{
front=0;
rear=0;
}
else
{
rear=(rear+1)%size;
}
printf("enter the element\n");
scanf("%d",&item);
queue[rear]=item;
}
}
void delete()
{
int del;
if(front==-1&&rear==-1)
{
printf("queue is empty\n");
}
else
{
del=queue[front];
if(front==rear)
{
front=-1;
rear=-1;
}
else
{
front=(front+1)%size;
}
printf("deleted element=%d\n",del);
}
}
void display()
{
int i;
if(front==-1&&rear==-1)
{
printf("queue is empty\n");
}
else
{
printf("circular queue contents:\n");
if(front<=rear)
{
for(i=front;i<=rear;i++)
{
printf("%d\n",queue[i]);
}
}
else
{
for(i=front;i<=size-1;i++)
printf("%d\n",queue[i]);
for(i=0;i<=rear;i++)
printf("%d\n",queue[i]);
}
}
}



