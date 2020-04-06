void tab(char code2[200])
{

  int i=0,j=0,k=0,l=0;
  for(i;code2[i]!='\0';i++)
    {
      if(code2[i-1]=='\n'&&code2[i-2]!='{')
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
          i++;
        }
      else if(code2[i]=='}')
        {
          k--;
          i++;
        }
      else
        {
          codefinal[j]=code2[i];
          j++;
        }
    }
  codefinal[j]='\0';
}
