#include<stdio.h>
#include<string.h>

void forloop(char* a)
{
  char x,y,z;
  char b,c,d;
  int s;
  s=strlen(a);

  if(s==18)
  {
     c=*(a+10);
     if(c=='=')
      {
	b=*(a+4);
	x=*(a+6);
	y=*(a+11);
	z=*(a+12);
	printf("CODE IN PYTHON -\n");
	printf("\tfor %c in range(%c,%c%c):\n",b,x,y,z+1);
      }
      else
       {
	  b=*(a+4);
	  x=*(a+6);
	  d=*(a+7);
	  y=*(a+11);
	  z=*(a+12);
	  printf("CODE IN PYTHON -\n");
	  printf("\tfor %c in range(%c%c,%c%c):\n",b,x,d,y,z);
       }
  }

  else if(s==17)
  {
      c=*(a+10);
       if(c!='=')
      {
	 b=*(a+4);
	 x=*(a+6);
	 y=*(a+10);
	 z=*(a+11);
	 printf("CODE IN PYTHON -\n");
	 printf("\tfor %c in range(%c,%c%c):\n",b,x,y,z);
       }
      else
       {
	  b=*(a+4);
	  x=*(a+6);
	  y=*(a+11);

	  printf("CODE IN PYTHON -\n");
	  printf("\tfor %c in range(%c,%c):\n",b,x,y+1);

	}
  }
   else if(s==19)
	{
	   b=*(a+4);
	   c=*(a+7);
	   x=*(a+6);
	   y=*(a+12);
	   z=*(a+13);
	   printf("CODE IN PYTHON -\n");
	   printf("\tfor %c in range(%c%c,%c%c):\n",b,x,c,y,z+1);
	 }
    else if(s==16)
	 {
	   b=*(a+4);
	   x=*(a+6);
	   y=*(a+10);
	   printf("CODE IN PYTHON -\n");
	   printf("\tfor %c in range(%c,%c):\n",b,x,y);
	  }

    else
     {
	  printf("INVALID SYNTAX\n");
     }


}
 int main()
 {  char a[100];
 
     printf("ENTER CODE IN C -\n\t");
   scanf("%[^\n]",a);
   forloop(a);
   return 0;
}
