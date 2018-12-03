#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int prec(char);
//void push1(char);
//int pop1();
//int eval(char[]);
char postfix[100];
char stack[100];
int top=-1;
void push(char a)
{
  stack[++top]=a;
}
char pop()
{
  char c;
  c=stack[top--];
  return c;
}
void convert(char suffix[100])
{ 
push('#');
  int j=0,pr,res;
  int i=0;
  char ch;
  while((ch=suffix[i])!='\0')
  {
    i++;
	printf("%c",ch);
    if(isalnum(ch))
    postfix[j++]=ch;
    else if(ch=='(')
      push(ch);
    else if(ch==')')
    {
      while(stack[top]!='(')
      {
        postfix[j++]=pop();
      }pop();
    }
    else
    {
      if(ch=='^')
      {
        pr=prec(ch);
        pr++;
      }
      else
      {
        pr= prec(ch);
      }
      if(prec(stack[top])>=pr)
      {
        postfix[j++]=pop();
      }
      push(ch);
    }
    }
    while(stack[top]!='#')
    {
      postfix[j++]=pop();
    }
    postfix[j++]='\0';
	printf("%s",postfix);
	//res=eval(postfix);
	//printf("%d",res);
}
int prec(char ch)
{
  switch(ch)
  {
    case '#':return 0;
    case '(':return 1;
    case '*':return 3;
    case '+':return 2;
    case '-':return 2;
    case '%':return 3;
    case '/':return 3;
    default: exit(0);
   }
}













void main()
{
char suff[100];
printf("enter the suffix expression\t");
scanf("%s",suff);
convert(suff);
}
