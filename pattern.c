#include<stdio.h>
#include<string.h>
int i,j,k,m,n;
void main()
{
  char string[100],pat[100],rep[100],newstring[100];
  printf("Enter the string:\t");
  scanf("%s",string);//use gets function to include space
  printf("Enter the Pattern String:\t" );
  scanf("%s",pat );//use gets function to include space
  printf("Enter The Replacement String:\t" );
  scanf("%s",rep);//use gets function to include space
  while(string[i]!='\0')
  {
    if(string[j]==pat[k])
    {
      j++;
      k++;
      if(pat[k]=='\0')
      {
        for(n=0;rep[n]!='\0';++n)
        {
          newstring[m++]=rep[n];
        }
        i=j;
        k=0;
      }
    }
    else
    {
      newstring[m]=string[i];
      i++;
      m++;
      j=i;
      k=0;

    }
  }
  printf("%s",newstring);
}
