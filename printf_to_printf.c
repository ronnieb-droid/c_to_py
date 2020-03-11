#include<stdio.h>
int main(){
       char code[90],code2[90],extr[100], print[20]="printf";
       printf("Enter your line of code: ");
       scanf("%[^\n]",code);
       //char *p=print;
       //printf("%p",p);
       int k = 0;
       int i=0, r=0,s=0,n=0;
       for(i; code[i]!='\0'; i++){
               if(code[i]==print[i]){
                       code2[i]=print[i];                          
               }
               if(i>=5){
                       code2[i]=code[i];
               }
                int j = 0;
                for(j; code2[j]!='\0'; j++);
                if(j==6){
                        code2[i]='(';
                        //printf("%s\n",code2);
                        i=i+1;
                        //printf("%d\n",i); 
                        }
       }
       printf("%s\n",code2);
       }
