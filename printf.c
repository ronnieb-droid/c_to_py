#include<stdio.h>
void print(char code[100])
{
    int j=0,k=0;
    for(int i=0;code[i]!='\0';i++)
    {
        if(code[i]=='p'&&code[i+1]=='r'&&code[i+2]=='i'&&code[i+3]=='n'&&code[i+4]=='t'&&code[i+5]=='f')
            {
                code2[j]='p';
                code2[j+1]='r';
                code2[j+2]='i';
                code2[j+3]='n';
                code2[j+4]='t';
                j+=5;
                i+=5;
            }
        else if(code[i]=='(')
        {
            code2[j]=code[i];
            j++;
            for(int l=i+1;code[l]!=')';l++)
                if(code[l]==','&&code[l-1]=='"')
                    k++;
        }
        else if(k==1)
        {
            for(i;code[i]!=',';i++);
            k=0;
        }
        else if(k==0)
           {
                code2[j]=code[i];
                j++;
           }
        else
           {
                code2[j]=code[i];
                j++;
           }

    }
    code2[j]='\0';

}

