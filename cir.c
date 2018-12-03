#include<stdio.h>
#include<string.h>
#define size 5
char que[size],item;
int front=-1,rear=-1,i;
int elem;
void add()
{
  if(front==(rear+1)%size)
  {
    printf("queue is full\n");

  }
  else
  {
  printf("enter the number you want to enter in the array\n");
  scanf("%d",&elem );
  if(front==-1)
  front++;
  rear=(rear+1)%size;
  que[rear]=elem;
}
}
void delete1()
{
  int r;
  if(front==-1 &&rear==-1)
  {
    printf("array is empty\n");

  }
  else if(front==rear)
  {
    r=que[front];
    front=rear=-1;
    printf("the elment delted\t%d\n",r);
  }
  else
  {
    r=que[front];
    printf("the elment deleted\t %d\n",r);
    front=(front+1)%size;
  }
}
void display()
{

  int i;
  for(i=front;i!=rear;i=(i+1)%size)
  {
    printf("%d\t",que[i]);
  }
  printf("%d",que[rear]);
}
void main(){
  int choice,n;
  while(1)
  {
    printf("1.add\n 2. delete\n 3.display\n4.addsingle\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:printf("enter the number of elments you want to add\n");
        scanf("%d",&n );
        for(i=0;i<n;++i)
          add();
      break;
      case 2:delete1();
      break;
      case 3 :display();
      break;
      case 4:add();
    }
  }
}
