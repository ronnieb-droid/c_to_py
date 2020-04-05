#include<stdio.h>
#include<string.h>
//Functions
void confirm(char code[],char check[]);
void convert(char code[],char code2[],char check[]);
void declaration(char code[],char code2[],char check[]);

//Global Variables
char printc[20]="printf",elifc[10]="else if",ifc[4]="if",scanc[6]="scanf";
char printp[20]="print",elifp[10]="elif",ifp[4]="if",inputp[6]="input";
char intc[4]="int",doublec[6]="double",charc[4]="char";
char code[100],code2[900];
int keycheck=0;//default for else if is 0 


int main(){
      int n;
    printf("Enter Number of lines of code: ");
    scanf("%d",&n);
    code[0]=getchar();
    for(int i=0;i<n;i++){
        for(int k=0;code[k]!='\n';k++){
            code[k+1]=getchar();
        }
        scanf("%[^\n]",code);//from for(int k ...) to this scanf used for input very necessary otherwise not working and i dont know why
        
        if((code[0]=='i')&&(code[1]=='n')){
            //Datatype change code
        }
        else if((code[0]=='f')&&(code[1]=='l')){
            //run datatype code
        }
        else if((code[0]=='f')&&(code[1]=='o')){
            //run for loop code
        }
        else if(code[0]=='c'){
            //run datatype code
        }
        else if(code[0]=='d'){
            //run datatype code
        }
        else if((code[0]=='e')&&(code[1]=='l')&&(code[2]=='s')&&(code[3]=='e')&&(code[5]=='i')&&(code[6]=='f')){
            confirm(code,elifc);
        }
        else if(code[0]=='w'){
            //run while loop code
        }
        else if(code[0]=='p'){
            confirm(code,printc);
        }
        else if(code[0]=='s'){
            confirm(code,scanc);
        }
        else{
            int lencode2=strlen(code2);
            for(int k=0;k<strlen(code);k++){
                code2[lencode2]=code[k];
                lencode2++;
            }
            code2[lencode2]='\n';
            lencode2++;
        }
    }
    printf("%s",code2);
}









//code to check scanf,printf,elif

void confirm(char code[],char check[]){
        //checks if a particular keyword is used or not
        int i =0;
        char code3[20];
        int m;
        for(m=0;code[m]!=check[0];m++);//to use keyword in any part of the line
        for(i; code[m]!='\0'; i++){
                 if(code[m]==check[i]){
                         code3[i]=check[i];
                }
                m++;
        }
        if((strlen(code3)==8)){
                //8 because for both it is only giving value as 8
                if(check[0]=='p'){
                        keycheck=1;
                }
                else if(check[0]=='s'){
                        keycheck=2;
                }
                convert(code,code2,check);
        }
}

void convert(char code[],char code2[],char check[]){
        //will be used to change the c code/keyword into python
    int i=0;// r=0,s=0,n=0;
    int m;
    int count=0,cont=0;//cont---->continue
    for(m=0;code[m]!=check[0];m++);//to use printf in any part of the line
    if(m!=0){
        int m1=0;
        cont=m;
        char test[30];
        for(cont;code[cont]!='\0';cont++){
                if(code[cont]==check[m1]){
                    test[m1]=check[m1];
                    m1++;
                }
        }
        if(strlen(test)==strlen(check)){
                for(count;count<m;count++){
                        code2[count]=code[count];
                }
        }
    }

    if(keycheck==1){
        int checky=strlen(code2);
        for(i; code[m]!='\0'; i++){
            if(code[m]==check[i]){
                    code2[checky]=printp[i];
                    checky++;
            }
            m++;
        }
    }
    else if(keycheck==0){
        for(i; code[m]!='\0'; i++){
            if(code[m]==check[i]){
                    code2[count]=elifp[i];
                    count++;
            }
            m++;
        }
    }
    if(keycheck==2){//for 1 input only
                char inputd[20]="= int(input());";
                char inputld[20]="= long(input());";
                char inputf[20]="= float(input());";
                char inputlf[20]="= double(input());";
                char inputc[20]="= char(input());";
                char a[10];
                char type[10];
                int count=0;
                int code2count=strlen(code2);
                for(int k=5;code[k]!=')';k++){
                        if(code[k]=='%'){
                                if(code[k+1]=='d'){//for int
                                        for(int i1=k;code[i1]!='\0';i1++){
                                                
                                                if(code[i1]=='&'){
                                                        count++;
                                                        code[i1]='~';
                                                        //printf("%s\n",code);
                                                }
                /*this works----->*/            else if((count%2!=0) && (code[i1]!=',')&&(code[i1]!=')')){//to check the commas
                                                        code2[code2count]=code[i1];
                                                        code2count++;
                                                }
                                                else if((count>0)&&((code[i1]==',')||(code[i1]==')'))){
                                                        count++;
                                                        if(count%2==0){
                                                                for(int k1=0;inputd[k1]!='\0';k1++)
                                                                {
                                                                        code2[code2count]=inputd[k1];
                                                                        code2count++;
                                                                }
                                                                code2[code2count]='\n';
                                                                code2count++;
                                                                break;
                                                        }
                                                }
                                        }
                                }
                                else if((code[k+1]=='l')&&(code[k+2]=='d')){//for long int
                                        for(int i1=k;code[i1]!='\0';i1++){
                                                if(code[i1]=='&'){
                                                        count++;
                                                        code[i1]='~';
                                                }
                                                else if((count%2!=0) && (code[i1]!=',')&&(code[i1]!=')')){//to check the commas
                                                        code2[code2count]=code[i1];
                                                        code2count++;
                                                }
                                                else if((count>0)&&((code[i1]==',')||(code[i1]==')'))){
                                                        count++;
                                                        if(count%2==0){
                                                                for(int k1=0;inputd[k1]!='\0';k1++){
                                                                        code2[code2count]=inputld[k1];
                                                                        code2count++;
                                                                }
                                                                code2[code2count]=';';
                                                                code2count++;
                                                                code2[code2count]='\n';
                                                                code2count++;
                                                                break;
                                                        }
                                                }
                                        }

                                }
                                else if(code[k+1]=='f'){//for float
                                        for(int i1=k;code[i1]!='\0';i1++){
                                                if(code[i1]=='&'){
                                                        count++;
                                                        code[i1]='~';
                                                }
                                                else if((count%2!=0) && (code[i1]!=',')&&(code[i1]!=')')){//to check the commas
                                                        code2[code2count]=code[i1];
                                                        code2count++;
                                                }
                                                else if((count>0)&&((code[i1]==',')||(code[i1]==')'))){
                                                        count++;
                                                        if(count%2==0){
                                                                for(int k1=0;inputd[k1]!='\0';k1++){
                                                                        code2[code2count]=inputf[k1];
                                                                        code2count++;
                                                                }
                                                                code2[code2count]=')';
                                                                code2count++;
                                                                code2[code2count]=';';
                                                                code2count++;
                                                                code2[code2count]='\n';
                                                                code2count++;
                                                                break;
                                                        }
                                                }
                                        }

                                }
                                else if((code[k+1]=='l')&&(code[k+2]=='f')){//for double
                                        for(int i1=k;code[i1]!='\0';i1++){
                                                if(code[i1]=='&'){
                                                        count++;
                                                        code[i1]='~';
                                                }
                                                else if((count%2!=0) && (code[i1]!=',')&&(code[i1]!=')')){//to check the commas
                                                        code2[code2count]=code[i1];
                                                        code2count++;
                                                }
                                                else if((count>0)&&((code[i1]==',')||(code[i1]==')'))){
                                                        count++;
                                                        if(count%2==0){
                                                                for(int k1=0;inputd[k1]!='\0';k1++){
                                                                        code2[code2count]=inputlf[k1];
                                                                        code2count++;
                                                                }
                                                                code2[code2count]=')';
                                                                code2count++;
                                                                code2[code2count]=')';
                                                                code2count++;
                                                                code2[code2count]=';';
                                                                code2count++;
                                                                code2[code2count]='\n';
                                                                code2count++;
                                                                break;
                                                        }
                                                }
                                        }

                                }
                                else if(code[k+1]=='c'){//for char
                                        for(int i1=k;code[i1]!='\0';i1++){
                                                if(code[i1]=='&'){
                                                        count++;
                                                        code[i1]='~';
                                                }
                                                else if((count%2!=0) && (code[i1]!=',')&&(code[i1]!=')')){//to check the commas
                                                        code2[code2count]=code[i1];
                                                        code2count++;
                                                }
                                                else if((count>0)&&((code[i1]==',')||(code[i1]==')'))){
                                                        count++;
                                                        if(count%2==0){
                                                                for(int k1=0;inputd[k1]!='\0';k1++){
                                                                        code2[code2count]=inputc[k1];
                                                                        code2count++;
                                                                }
                                                                code2[code2count]=';';
                                                                code2count++;
                                                                code2[code2count]='\n';
                                                                code2count++;
                                                                break;
                                                        }
                                                }
                                        }

                                }
                        }
                }     
                //printf("%s",code2); 
    }
    else if(keycheck==1){
        //printf("%s\n",code2);
        int k,countcode2=0;
        //int f=strlen(elifc)-strlen(elifp);
        //k=strlen(code2)+f;
        for(k=0;code[k]!='(';k++);
        //printf("%d %c\n",k,check[strlen(check)-2]);
        countcode2=strlen(code2);
        //printf("%c\n",code2[0]);
        //printf("%d\n",strlen(code2));
        for(k;code[k]!='\0';k++){
                code2[countcode2]=code[k];
                countcode2++;
        }
        code2[countcode2]='\n';
        //printf("%d\n",strlen(code2));
        //printf("%c\n",code2[0]);
        //printf("%s\n",code2);//strlen(code2)=22
    }
    else{

        //printf("%s\n",code2);
        int k=0,countcode2=0;
        int f=strlen(elifc)-strlen(elifp);
        k=strlen(code2)+f;
        //printf("%d %c\n",k,check[strlen(check)-2]);
        countcode2=strlen(code2);
        for(k;code[k]!='\0';k++){
                code2[countcode2]=code[k];
                countcode2++;
        }
        //code2[k-1]='\0';
        code2[countcode2]='\n';
        //printf("%s\n",code2);
    }
}
