#include<stdio.h>
char printf(char cin[100])
{
    char cout[100];
    //scanf("%[^\n]",cin);
    int j=0,k=0;
    for(int i=0;cin[i]!='\0';i++)
    {
        if(cin[i]=='p'&&cin[i+1]=='r'&&cin[i+2]=='i'&&cin[i+3]=='n'&&cin[i+4]=='t'&&cin[i+5]=='f')
            {
                cout[j]='p';
                cout[j+1]='r';
                cout[j+2]='i';
                cout[j+3]='n';
                cout[j+4]='t';
                j+=5;
                i+=5;
            }
        else if(cin[i]=='(')
        {
            cout[j]=cin[i];
            j++;
            for(int l=i+1;cin[l]!=')';l++)
                if(cin[l]==','&&cin[l-1]=='"')
                    k++;
        }
        else if(k==1)
        {
            for(i;cin[i]!=',';i++);
            k=0;
        }
        else if(k==0)
           {
                cout[j]=cin[i];
                j++;
           }
        else
           {
                cout[j]=cin[i];
                j++;
           }

    }
    cout[j]='\0';
    return cout;
}

