#include<stdio.h>
#define size 3
void insert();
void delete();
void display();
int queue[size];
int rear=-1;
int front=-1;
void main()
{
 int choice;
 while(1)
 {
 printf("1:insert 2:delete 3:display 4:exit\n");
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
 default:printf("wrong choice\n");
 }
 }
 }
 void insert()
 {
 int item;
 if(rear==size-1)
 printf("Queue overflow\n");
 else
 {
 if(front==-1)
 front=0;
 printf("enter the element\n");
 scanf("%d",&item);
 rear=rear+1;
 queue[rear]=item;
 }
 }
 void delete()
 {
 if(front==-1||front>rear)
 {
 printf("queue underflow\n");
 return;
 }
 else
 {
     int item=queue[front];
     if(front==rear)
     {

         front=-1;
         rear=-1;
     }
     else
     {
         front=front+1;
     }
     printf("deleted element=%d\n",item);
 }
 }
 void display()
 {
 int i;
 if(front==-1)
 printf("queue is empty\n");
 else
 {
 printf("queue contents:\n");
 for(i=front;i<=rear;i++)
 printf("%d\n",queue[i]);
 }
 }
