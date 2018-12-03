#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int stack1[101];
int top1=-1;


void push1(int ch)
{
  
  stack1[++top1]=ch;
  //printf("#%d# ",stack1[top1]);
}
int pop1()
{
  int c;
  c=stack1[top1--];
 //printf(" *%d* ",c);
  return c;
}
int eval(char a[100])
{ int j,i=0,k,op2,op1;
  int result;
  char ch;
  while((ch=a[i])!='\0')
  {
	i++;
	//printf("%c",ch);
   if(isalpha(ch))
    {
      printf("INVALID EXPRESSION\n");

    }
    else
    {
      if(isdigit(ch))
      {
        k=ch-48;
        push1(k);
      }
      else
      {
        op2=pop1();
        op1=pop1();
        switch(ch)
        {
          case '+': push1(op2+op1);break;
          case '-': push1(op2-op1);break;
          case '*': push1(op2*op1);break;
          case '/': push1(op2/op1);break;
          case '%': push1(op2%op1);break;
          default:printf("INVALID OPERATOR\n");
        }
      }
    }
  }
  j=pop1();
  if(top1!=-1)
  {
    printf("INVALID EXPRESSION 1 \n");
  }
  //printf("The Final Answer :\t %d ",result);
return j;
}
void main()
{int i;
char prefix[100];
printf("Enter a prefix expression");
scanf("%s",prefix);
i=eval(prefix);
printf("The final answer %d",i);
}
