#include<stdio.h>
#include<stdlib.h>
struct node
{
  int coeff;
  int expx;
  int expy;
  int expz;
  struct node *link;
};
typedef struct node *Node;
//Node root=Null;

Node headnode()
{
  Node temp;
  temp=(Node)malloc(sizeof(struct node));
  temp->coeff=-1;
  temp->expx=-1;
  temp->expy=-1;
  temp->expz=-1;
  temp->link=temp;
}
Node createnode()
{
  Node temp;
  temp=(Node)malloc(sizeof(struct node));
  printf("enter the cofficent\n");
  scanf("%d",&temp->coeff);
  printf("enter the X exp:");
  scanf("%d",&temp->expx);
  printf("\nenter the y exp:");
  scanf("%d",&temp->expy);
  printf("\nenter the Z exp:");
  scanf("%d",&temp->expz);
  temp->link=NULL;
  return temp;
}
Node createnode1(int coef,int expX,int expY,int expZ)
{
  Node temp;
  temp=(Node)malloc(sizeof(struct node));
  temp->coeff=coef;
  temp->expx=expX;
  temp->expy=expY;
  temp->expz=expZ;
  temp->link=NULL;
  return temp;
}
void insertrear(Node node1,Node newnode)
{
  Node node=node1;
  if(node1->link==node1)
{
    node1->link=newnode;
newnode->link=node1;
}
  else
  {
      while (node->link!=node1)
      {
        node=node->link;
      }
      node->link=newnode;
      newnode->link=node1;
    }
}


void add2()
{
	printf("hello");
}

Node add1(Node tem,Node temp)
{
  Node startA,startB,startC;
  startA=tem->link;
  startB=temp->link;
  startC=headnode();
  while(startA!=tem && startB!=temp)
  {
    if(startA->expx==startB->expx&&startA->expz==startB->expz&&startA->expy==startB->expy)
    {
      insertrear(startC,createnode1(startA->coeff+startB->coeff,startA->expx,startB->expy,startA->expz));
    }
    else if (startA->expx>startB->expx/* condition */) {
      insertrear(startC,createnode1(startA->coeff,startA->expx,startB->expy,startA->expz));
    }
    else if(startA->expx==startB->expx&&startA->expy>startB->expy)
      insertrear(startC,createnode1(startA->coeff,startA->expx,startA->expy,startA->expz));
    else if(startA->expx==startB->expx&&startA->expy==startB->expy&&startA->expz>startB->expz)
      insertrear(startC,createnode1(startA->coeff,startA->expx,startA->expy,startA->expz));
    else
      insertrear(startC,createnode1(startB->coeff,startB->expx,startB->expy,startB->expz));
  }
  return startC;
}
void display(Node temp)
{

  Node cur;
  cur=temp->link;
  while(cur!=temp)
  {
    if(cur->coeff<0)
    {
      printf("-%dX^%dY^%dZ^%d ",cur->coeff,cur->expx,cur->expy,cur->expz);
    }
    else
    printf("+%dX^%dY^%dZ^%d ",cur->coeff,cur->expx,cur->expy,cur->expz);
    cur=cur->link;
  }
}
void main()
{
  int n,i,m;
Node temp,temp2,temp3;
temp=headnode();
temp2=headnode();


printf("enter the number of node");
scanf("%d",&n );
for(i=0;i<n;++i)
{
  insertrear(temp,createnode());
}
display(temp);
printf("\nenter the second number of node");
scanf("%d",&m);
for(i=0;i<m;++i)
{
  insertrear(temp2,createnode());
}
display(temp2);
//display(temp);
//display(temp2);
printf("hello");

temp3=add1(temp,temp2);
//display(temp3);
}
