void tab(char code[200])
{

  int i=0,j=0,k=0,l=0;
  for(i;code[i]!='\0';i++)
    { 
      if(code[i-1]=='\n')
        {
          for(l=0;l<k;l++)
            {
              code2[j]='\t';
              j++;
            }
            
        }
      if(code[i]=='{')
        {
          code2[j]='\t';
          k++;
          j++;
        }
      else if(code[i]=='}')
        {
          k--;
        } 
      else
        {
          code2[j]=code[i];
          j++;
        }  
    }
  code2[j]='\0';
} 
