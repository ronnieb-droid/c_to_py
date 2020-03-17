#include <stdio.h>

char tab(char cin[100])
{

  char cout[120];
  int i=0,j=0,k=0,l=0;
  for(i;cin[i]!='\0';i++)
    { 
      if(cin[i-1]=='\n')
        {
          for(l=0;l<k;l++)
            {
              cout[j]='\t';
              j++;
            }
            
        }
      if(cin[i]=='{')
        {
          cout[j]='\t';
          k++;
          j++;
        }
      else if(cin[i]=='}')
        {
          k--;
        } 
      else
        {
          cout[j]=cin[i];
          j++;
        }  
    }
  return cout;
} 
