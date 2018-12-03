#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
};
int count=0;
typedef struct node *Node;
Node head=NULL;
//void display_del(Node);
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
  temp->link=NULL;
  return temp;

}
void insert_beg()
{
  Node temp=create();
  if(head==NULL)
    head=temp;
  else
  {
    temp->link=head;
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
  else if(head->link==NULL)
  {
    temp=head;
    free(temp);
    head=NULL;
  }
  else
  {
    temp=head;
    head=head->link;
    display_del(temp);
   // free(temp);
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
  else if(head->link==NULL)
  {
    temp=head;
    free(temp);
    head=NULL;
  }
  else
  {
    while(temp->link!=NULL)
    {
      cur=temp;
      temp=temp->link;
    }
    cur->link=NULL;
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
    while(temp->link!=NULL)
    {
      temp=temp->link;
    }
    temp->link=newnode;
  }
}
void display()
{
  Node temp;
  temp=head;
  printf("FRONT->>");
  while(temp!=NULL)
  {
    printf("%d->> ",temp->data);
    temp=temp->link;
  }
  printf("END\n");
  printf("The number of node are: %d",count);
  printf("\n");
}

void main()
{
  int choice,i,n;
  while(1)
  {
    printf("1.Insertion By Frent Insertion\n");
    printf("2.Display the status SLL and count\n");
    printf("3.Insertion in End of SLL\n");
    printf("4.Deletion In the End of SLL\n");
    printf("5.Insertion In The Front of SLL\n");
    printf("6.Deletion In the Front of SLL\n");
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
