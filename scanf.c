void scan(char code2[])
{
    int i=0,j=0,k=0,l=0,count=0,x=0;
    char temp[10],data[20];
    for(i=0;code2[i]!='\0';i++)
    {
        if(code2[i]=='s'&&code2[i+1]=='c'&&code2[i+2]=='a'&&code2[i+3]=='n'&&code2[i+4]=='f')
            {
                x=0;
                i+=7;
                for(i;code2[i]!='"';i++)
                {
                    if(code2[i]=='%')
                    {
                        count++;
                        if(code2[i+1]=='l')
                        {
                            if(code2[i+2]=='f')
                                data[x]='q';
                            else if(code2[i+2]=='d')
                                data[x]='w';
                        }
                        else
                        {
                            data[x]=code2[i+1];
                        }
                        x++;
                    }
                }
                i+=2;
                x=0;
                while(count>0)
                {
                  l=0;
                  for(i;code2[i]!=','&&code2[i]!=')';i++)
                  {
                      if(code2[i]!='&')
                      {
                       temp[l]=code2[i];
                       l++;
                      }
                  }
                  i++;
                  for(k=0;k<l;k++)
                  {
                      cout[j]=temp[k];
                      j++;
                  }
                  cout[j++]='=';
                  if(data[x]=='d')
                  {
                      cout[j++]='i';
                      cout[j++]='n';
                      cout[j++]='t';
                      cout[j++]='(';
                      cout[j++]='i';
                      cout[j++]='n';
                      cout[j++]='p';
                      cout[j++]='u';
                      cout[j++]='t';
                      cout[j++]='(';
                      cout[j++]=')';
                      cout[j++]=')';
                      cout[j++]=';';
                      cout[j++]='\n';
                  }
                  else if(data[x]=='c'||data[x]=='s')
                  {
                      cout[j++]='i';
                      cout[j++]='n';
                      cout[j++]='p';
                      cout[j++]='u';
                      cout[j++]='t';
                      cout[j++]='(';
                      cout[j++]=')';
                      cout[j++]=';';
                      cout[j++]='\n';
                  }
                  else if(data[x]=='f')
                  {
                      cout[j++]='f';
                      cout[j++]='l';
                      cout[j++]='o';
                      cout[j++]='a';
                      cout[j++]='t';
                      cout[j++]='(';
                      cout[j++]='i';
                      cout[j++]='n';
                      cout[j++]='p';
                      cout[j++]='u';
                      cout[j++]='t';
                      cout[j++]='(';
                      cout[j++]=')';
                      cout[j++]=')';
                      cout[j++]=';';
                      cout[j++]='\n';
                  }
                  else if(data[x]=='q')
                  {
                      cout[j++]='d';
                      cout[j++]='o';
                      cout[j++]='u';
                      cout[j++]='b';
                      cout[j++]='l';
                      cout[j++]='e';
                      cout[j++]='(';
                      cout[j++]='i';
                      cout[j++]='n';
                      cout[j++]='p';
                      cout[j++]='u';
                      cout[j++]='t';
                      cout[j++]='(';
                      cout[j++]=')';
                      cout[j++]=')';
                      cout[j++]=';';
                      cout[j++]='\n';
                  }
                  else if(data[x]=='w')
                  {
                      cout[j++]='l';
                      cout[j++]='o';
                      cout[j++]='n';
                      cout[j++]='g';
                      cout[j++]='(';
                      cout[j++]='i';
                      cout[j++]='n';
                      cout[j++]='p';
                      cout[j++]='u';
                      cout[j++]='t';
                      cout[j++]='(';
                      cout[j++]=')';
                      cout[j++]=')';
                      cout[j++]=';';
                      cout[j++]='\n';
                  }
                  count--;
                  x++;
                }
                i++;
            }
        else
        {
            cout[j]=code2[i];
            j++;
        }
    }
    cout[j]='\0';
}
