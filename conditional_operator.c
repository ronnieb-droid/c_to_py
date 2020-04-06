void condoper(char code[100])
{
    int j=0;
    for(int i=0;code[i]!='\0';i++)
    {
        if(code[i]=='&'&&code[i+1]=='&')
        {
            code2[j]=' ';
            code2[j+1]='a';
            code2[j+2]='n';
            code2[j+3]='d';
            code2[j+4]=' ';
            j+=5;
            i++;
        }
        else if(code[i]=='|'&&code[i+1]=='|')
        {
            code2[j]=' ';
            code2[j+1]='o';
            code2[j+2]='r';
            code2[j+3]=' ';
            j+=4;
            i++;
        }
        else
        {
            code2[j]=code[i];
            j++;
        }
    }
    code2[j]='\0';
}
