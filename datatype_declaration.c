#include<stdio.h>
#include<string.h>

void datatype(char *a);
char a[69];

int main(){

    printf("Enter:\n");
    scanf("%[^\n]",a);
    datatype(a);
    return 0;
}
void datatype(char *a)
{
    char inti[4] = "int";
    char charc[5] = "char";
    char doubled[7] = "double";
    char floatf[6] = "float";
    char strg[25];
    int i = 0,k = 0;
    int ro = 0;
    int len=strlen(a);
    if(a[i]=='i'){
        while(a[++i]==inti[++ro]);
        if(ro==3){
            ro++;
            while(a[ro++]!='\0'){
                if(a[ro-1]==';'){
                    if(a[ro-2]=='0' || a[ro-2]=='1' || a[ro-2]=='2' || a[ro-2]=='3' || a[ro-2]=='4' || a[ro-2]=='5' ||
                       a[ro-2]=='6' || a[ro-2]=='7' || a[ro-2]=='8' || a[ro-2]=='9'){
                        //printf("%d", ro);
                        break;
                    }
                    else{
                        strg[k]='=';
                        k++;
                        strg[k]='0';
                        k++;
                    }
                }
                else if(a[ro-1]!=';'){
                    strg[k]=a[ro-1];
                    k++;
                }
             }
            //printf("%d",ro);
            strg[k]='\0';
        }
    }
    if(a[i]=='c'){
        while(a[++i]==charc[++ro]);
        if(ro==4){
            ro++;
            while(a[ro++]!='\0'){
                if(a[ro-1]==';'){
                    if(a[ro-2]=='\''){
                        //printf("%d", ro);
                        break;
                    }
                    else{
                        strg[k++]='=';
                        strg[k++]='\'';
                        strg[k++]='a';
                        strg[k++]='\'';
                    }
                }
                else if(a[ro-1]!=';'){
                    strg[k]=a[ro-1];
                    k++;
                }
             }
            strg[k]='\0';
        }
    }
    if(a[i]=='d'){
        while(a[++i]==doubled[++ro]);
        if(ro==6){
            ro++;
            while(a[ro++]!='\0'){
                if(a[ro-1]==';'){
                    if(a[ro-2]=='0' || a[ro-2]=='1' || a[ro-2]=='2' || a[ro-2]=='3' || a[ro-2]=='4' || a[ro-2]=='5' ||
                       a[ro-2]=='6' || a[ro-2]=='7' || a[ro-2]=='8' || a[ro-2]=='9'){
                        //printf("%d", ro);
                        break;
                    }
                    else{
                        strg[k++]='=';
                        strg[k++]='0';
                        strg[k++]='.';
                        strg[k++]='0';
                    }
                }
                else if(a[ro-1]!=';'){
                    strg[k]=a[ro-1];
                    k++;
                }
            }

            strg[k]='\0';
        }
    }
    if(a[i]=='f'){
        while(a[++i]==floatf[++ro]);
        if(ro==5){
            ro++;
            while(a[ro++]!='\0'){
                if(a[ro-1]==';'){
                    if(a[ro-2]=='0' || a[ro-2]=='1' || a[ro-2]=='2' || a[ro-2]=='3' || a[ro-2]=='4' || a[ro-2]=='5' ||
                       a[ro-2]=='6' || a[ro-2]=='7' || a[ro-2]=='8' || a[ro-2]=='9'){
                        //printf("%d", ro);
                        break;
                    }
                    else{
                        strg[k++]='=';
                        strg[k++]='0';
                        strg[k++]='.';
                        strg[k++]='0';
                    }
                }
                else if(a[ro-1]!=';'){
                    strg[k]=a[ro-1];
                    k++;
                }
            }

            strg[k]='\0';
        }
    }
    printf("%s",strg);
}
