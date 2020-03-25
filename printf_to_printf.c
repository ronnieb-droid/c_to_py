#include<stdio.h>
#include<string.h>
void convert(char code[],char code2[],char check[]);
char printc[20]="printf",elifc[10]="else if",ifc[4]="if";
int main(){
       char code[90],code2[90],extr[100];
       printf("Enter your line of code: ");
       scanf("%[^\n]",code);
       //char *p=print;
       //printf("%p",p);
    convert(code,code2,printc);
       }

void convert(char code[],char code2[],char check[]){
    int i=0;// r=0,s=0,n=0;
    for(i; code[i]!='\0'; i++){
            if(code[i]==check[i]){
                    code2[i]=check[i];
            }
            if(i>=strlen(check)){
                    code2[i]=code[i];
            }
             int j = 0;
             for(j; code2[j]!='\0'; j++);
             if(j==strlen(check)){//but why 6
                     code2[i]='\0';
                     //printf("%s\n",code2);
                     i=i+1;
                     //printf("%d\n",i);
                     }
    }
    int k=0;
    for(k; code[k]!='('; k++);
    for(k;code[k]!='\0';k++){
        code2[k-1]=code[k];
    }
    code2[k-1]='\0';
    printf("%s\n%d\n",code2,k);//strlen(code2)=22
}

