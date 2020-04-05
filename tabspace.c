void tab(char code2[200])
{

  int i=0,j=0,k=0,l=0;
  for(i;code2[i]!='\0';i++)
    { 
      if(code2[i-1]=='\n')
        {
          for(l=0;l<k;l++)
            {
              codefinal[j]='\t';
              j++;
            }
            
        }
      if(code2[i]=='{')
        {
          codefinal[j]='\t';
          k++;
          j++;
        }
      else if(code2[i]=='}')
        {
          k--;
        } 
      else
        {
          codefinal[j]=code2[i];
          j++;
        }  
    }
  codefinal[j]='\0';
}
