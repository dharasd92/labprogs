#include<stdio.h>
void tower(int n,char beg,char aux,char end)
{
  if(n==1)
  {
  printf("Disc 1 moves from %c to %c\n",beg,end);
  return;
  }
  else
  {
    tower(n-1,beg,end,aux);
    printf(" Disc %d moves from%c to %c\n",n,beg,end);
    tower(n-1,aux,beg,end);
  }

}
void main()
{
  int n;
  printf("Enter the number of sic you want to\n");
  scanf("%d",&n);
  tower(n,'a','b','c');
}
