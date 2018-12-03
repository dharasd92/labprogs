#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *llink;
  struct node *rlink;
};
int count=0;
typedef struct node *Node;
Node head=NULL;
void display_del(Node temp)
{
  printf("The Data To Be Deleted:\t");
  printf("%d \n",temp->data);
  count--;
}
Node getnode()
{
  Node temp;
  temp=(Node)malloc(sizeof(struct node));
  return temp;
}
Node create()
{
  Node temp;
  count++;
  temp=getnode();
  printf("Enter the data\n" );
  scanf("%d",&temp->data);
  temp->llink=NULL;
  temp->rlink=NULL;
  return temp;
}
void insert_beg()
{
  Node temp=create();
  if(head==NULL)
    head=temp;
  else
  {
    temp->rlink=head;
    head->llink=temp;
    head=temp;
  }
}
void del_beg()
{
  Node temp;
  if(head==NULL)
  {
    printf("The list is empty");

  }
  else if(head->rlink==NULL)
  {
    temp=head;
    free(temp);
    head=NULL;
  }
  else
  {
    temp=head;
    head=head->rlink;
    head->llink=NULL;
    display_del(temp);
    free(temp);
  }
}
void del_end()
{
  Node temp,cur;
  temp=head;
  if(head==NULL)
  {
    printf("The list is empty");

  }
  else if(head->rlink==NULL)
  {
    temp=head;
    free(temp);
    head=NULL;
  }
  else
  {
    while(temp->rlink!=NULL)
    {
      cur=temp;
      temp=temp->rlink;
    }
    cur->rlink=NULL;
    display_del(temp);
    //free(temp);
  }
}
void add_end()
{
  Node temp,newnode;
  newnode=create();
  temp=head;
  if(head==NULL)
    head=newnode;
  else
  {
    while(temp->rlink!=NULL)
    {
      temp=temp->rlink;
    }
    temp->rlink=newnode;
    newnode->llink=temp;
  }
}
void display()
{
  Node temp;
  temp=head;
  printf("FRONT->>");
  while(temp->rlink!=NULL)
  {
    printf("%d->> ",temp->data);
    temp=temp->rlink;

  }printf("%d->> ",temp->data);
  printf("END\n");
  printf("The number of node are: %d",count);
  printf("\n");
  printf("END");
  printf("<<--%d",temp->data);
  temp=temp->llink;
  while(temp!=NULL)
  {
    printf("<<--%d ",temp->data);
    temp=temp->llink;
  }  printf("<<--FRONT\n");
}
void main()
{
  int choice,i,n;
  while(1)
  {
    printf("1.Insertion By Frent Insertion\n");
    printf("2.Display the status DLL and count\n");
    printf("3.Insertion in End of DLL\n");
    printf("4.Deletion In the End of DLL\n");
    printf("5.Insertion In The Front of DLL\n");
    printf("6.Deletion In the Front of DLL\n");
    printf("7.Exit\n");
    printf("Enter the choice\n" );
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        printf("Enter the number of Entries\n");
        scanf("%d",&n);
        for(i=0;i<n;++i)
        {
          insert_beg();
        }
      break;
      case 2:display();
      break;
      case 3:add_end();
      break;
      case 4:del_end();
      break;
      case 5:insert_beg();
      break;
      case 6:del_beg();
      break;
      case 7:exit(0);break;

    }
  }
}
