#include<stdio.h>
#include<string.h>
//Functions
void confirm(char code[],char check[]);
void convert(char code[],char code2[],char check[]);
void declaration(char code[],char code2[],char check[]);

//Global Variables
char printc[20]="printf",elifc[10]="else if",ifc[4]="if";
char printp[20]="print",elifp[10]="elif",ifp[4]="if";
char intc[4]="int",doublec[6]="double",charc[4]="char";
char code3[90];
int keycheck=0;//default for else if is 0 


int main(){
       char code[90],code2[90],extr[100];
       printf("Enter your line of code: ");
       scanf("%[^\n]",code);
       //char *p=print;
       //printf("%p",p);
        confirm(code,printc);//calling the first function to check 
       }

void confirm(char code[],char check[]){
        //checks if a particular keyword is used or not
        int i =0;
        char code2[20];
        int m;
        for(m=0;code[m]!=check[0];m++);//to use printf in any part of the line
        //printf("%d\n",m);
        for(i; code[m]!='\0'; i++){
                 if(code[m]==check[i]){
                         code2[i]=check[i];
                }
                m++;
        }
        /*printf("%s\n",code2);
        printf("%d  %d\n",strlen(code2),strlen(check));*/
        if((strlen(code2)==8)){
                //8 because for both it is only giving value as 8
                if(check[0]=='p'){
                        keycheck=1;
                }
                convert(code,code3,check);
        }
}

void convert(char code[],char code2[],char check[]){
        //will be used to change the c code/keyword into python
    int i=0;// r=0,s=0,n=0;
    int m;
    for(m=0;code[m]!=check[0];m++);//to use printf in any part of the line
    //printf("%d\n",m);
    if(keycheck==1){
        for(i; code[m]!='\0'; i++){
            if(code[m]==check[i]){
                    code2[i]=printp[i];
            }
            m++;
           /* if(i>=strlen(checkp)){
                    code2[i]=code[i];
            }*/
             /*int j = 0;
             for(j; code2[j]!='\0'; j++);
             if(check[0]=='p'){
                        if(j==6){//but why 6
                        code2[i]='\0';
                        //printf("%s\n",code2);
                        i=i+1;
                        //printf("%d\n",i);
                        }
             }
             if(check[0]=='e'){
                     printf("What's up Doc?");
                     if(j==strlen(check)){
                             printf("Hell");
                     }
             }*/
        }
    }
    else{
        for(i; code[m]!='\0'; i++){
            if(code[m]==check[i]){
                    code2[i]=elifp[i];
            }
            m++;
        }
    }

    int k=0,countcode2=0;
    for(k; code[k]!=check[strlen(check)-1]; k++);
    ++k;
    //printf("%d %s %d %d\n",k,code,strlen(code2),strlen(elifp));
    if(keycheck==1){
        countcode2=strlen(printp);
    }
    else{
        countcode2=strlen(elifp);

    }
     for(k;code[k]!='\0';k++){
        code2[countcode2]=code[k];
        countcode2++;
     }
    code2[k-1]='\0';
    printf("%s\n%d\n",code2,k);//strlen(code2)=22

}


/*void declaration(char code[],char code2[],char check[]){
        //used to replace int and all the integer type by null character
        int i=0;// r=0,s=0,n=0;
    for(i; code[i]!='\0'; i++){
            if(code[i]==check[i]){
                    code2[i]='\0';
            }
    }
}*/
