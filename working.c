#include<stdio.h>
#include<string.h>
//Functions
void datatype(char *a);
void tab(char code2[]);
void forloop(char* a);
void print(char code[]);
void confirm(char code[],char check[]);
void convert(char code[],char code2[],char check[]);
void declaration(char code[],char code2[],char check[]);

//Global Variables
char printc[20]="printf",elifc[10]="else if",ifc[4]="if",scanc[6]="scanf";
char printp[20]="print",elifp[10]="elif",ifp[4]="if",inputp[6]="input";
char intc[4]="int",doublec[6]="double",charc[4]="char";
char code[100],code2[900],codefinal[900];
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
            datatype(code);
        }
        else if((code[0]=='f')&&(code[1]=='l')){
            //run datatype code
            datatype(code);
        }
        else if((code[0]=='f')&&(code[1]=='o')){
            //run for loop code
            forloop(code);
        }
        else if(code[0]=='c'){
            //run datatype code
            datatype(code);
        }
        else if(code[0]=='d'){
            //run datatype code
            datatype(code);
        }
        else if((code[0]=='e')&&(code[1]=='l')&&(code[2]=='s')&&(code[3]=='e')&&(code[5]=='i')&&(code[6]=='f')){
            confirm(code,elifc);
            
        }
        else if(code[0]=='w'){
            //run while loop code
        }
        else if(code[0]=='p'){
            print(code);
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
        if((code[0]=='i')&&(code[1]=='f')){
            code2[strlen(code2)-1]=':';
            code2[strlen(code2)]='\n';
        }
        else if((code[0]=='e')&&(code[1]=='l')&&(code[2]=='s')&&(code[3]=='e')){
            code2[strlen(code2)-1]=':';
            code2[strlen(code2)]='\n';
        }
    }
   
    //printf("%s\n",code2);
    tab(code2);
    printf("\nYour Python equivalent code is:\n\n");
    printf("%s\n",codefinal);
}









//code to check scanf,printf,elif

void confirm(char code[],char check[]){
        //checks if a particular keyword is used or not
        int i =0;
        keycheck=0;
        char code3[20];
        int m;
        for(m=0;code[m]!=check[0];m++);//to use keyword in any part of the line
        for(i; code[m]!='\0'; i++){
                 if(code[m]==check[i]){
                         code3[i]=check[i];
                }
                m++;
        }
        //printf("%d\n%s\n",strlen(code3),code3);
        
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
        int checky=strlen(code2);
        for(i; code[m]!='\0'; i++){
            if(code[m]==check[i]){
                    code2[checky]=elifp[i];
                    checky++;
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
        //printf("This is a legal info that this is a print statement\n");
        //printf("%s\n",code2);//strlen(code2)=22
    }
    else{
        //printf("%s\n",code2);
        int k=0,countcode2=0;
        char test[30];
        int c1=0;
        for(k=0;code[k]!='(';k++){
            if(code[k]==check[c1]){
                test[c1]=check[c1];
                c1++;
            }
            if(strlen(test)==strlen(check))
                break;
        }
        /*int f=strlen(elifc)-strlen(elifp);
        k=strlen(code2)+f;*/
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



//code for data type--rounak strg

void datatype(char *a)
{
    char inti[4] = "int";
    char charc[5] = "char";
    char doubled[7] = "double";
    char floatf[6] = "float";
    //char strg[25];
    int i = 0,k = 0;
    int ro = 0;
    int len=strlen(a);
    if(a[i]=='i'){
        while(a[++i]==inti[++ro]);
        if(ro==3){
            k=strlen(code2);
            ro++;
            while(a[ro++]!='\0'){
                if(a[ro-1]==';'){
                    if(a[ro-2]=='0' || a[ro-2]=='1' || a[ro-2]=='2' || a[ro-2]=='3' || a[ro-2]=='4' || a[ro-2]=='5' ||
                       a[ro-2]=='6' || a[ro-2]=='7' || a[ro-2]=='8' || a[ro-2]=='9'){
                        //printf("%d", ro);
                        break;
                    }
                    else{
                        code2[k]='=';
                        k++;
                        code2[k]='0';
                        k++;
                    }
                }
                else if(a[ro-1]!=';'){
                    code2[k]=a[ro-1];
                    k++;
                }
             }
            code2[k]=';';
            code2[k+1]='\n';
        }
    }
    if(a[i]=='c'){
        while(a[++i]==charc[++ro]);
        if(ro==4){
            k=strlen(code2);
            ro++;
            while(a[ro++]!='\0'){
                if(a[ro-1]==';'){
                    if(a[ro-2]=='\''){
                        //printf("%d", ro);
                        break;
                    }
                    else{
                        code2[k++]='=';
                        code2[k++]='\'';
                        code2[k++]='a';
                        code2[k++]='\'';
                    }
                }
                else if(a[ro-1]!=';'){
                    code2[k]=a[ro-1];
                    k++;
                }
            }
            code2[k]=';';
            code2[k+1]='\n';
        }
    }
    if(a[i]=='d'){
        while(a[++i]==doubled[++ro]);
        if(ro==6){
            k=strlen(code2);
            ro++;
             while(a[ro++]!='\0'){
                if(a[ro-1]==';'){
                    if(a[ro-2]=='0' || a[ro-2]=='1' || a[ro-2]=='2' || a[ro-2]=='3' || a[ro-2]=='4' || a[ro-2]=='5' ||
                       a[ro-2]=='6' || a[ro-2]=='7' || a[ro-2]=='8' || a[ro-2]=='9'){
                        //printf("%d", ro);
                        break;
                    }
                    else{
                        code2[k++]='=';
                        code2[k++]='0';
                        code2[k++]='.';
                        code2[k++]='0';
                    }
                }
                else if(a[ro-1]!=';'){
                    code2[k]=a[ro-1];
                    k++;
                }
            }
            code2[k]=';';
            code2[k+1]='\n';
        }
    }
    if(a[i]=='f'){
        while(a[++i]==floatf[++ro]);
        if(ro==5){
            k=strlen(code2);
            ro++;
            while(a[ro++]!='\0'){
                if(a[ro-1]==';'){
                    if(a[ro-2]=='0' || a[ro-2]=='1' || a[ro-2]=='2' || a[ro-2]=='3' || a[ro-2]=='4' || a[ro-2]=='5' ||
                       a[ro-2]=='6' || a[ro-2]=='7' || a[ro-2]=='8' || a[ro-2]=='9'){
                        //printf("%d", ro);
                        break;
                    }
                    else{
                        code2[k++]='=';
                        code2[k++]='0';
                        code2[k++]='.';
                        code2[k++]='0';
                    }
                }
                else if(a[ro-1]!=';'){
                    code2[k]=a[ro-1];
                    k++;
                }
            }
            code2[k]=';';
            code2[k+1]='\n';
        }
    }
    //printf("%s",code2);
}



//code for for-loop vaibhav
void forloop(char* a)
{
  char x,y,z;
  char b,c,d;
  int s;
  s=strlen(a);

  if(s==18)
  {
     c=*(a+10);
     if(c=='=')
      {
	b=*(a+4);
	x=*(a+6);
	y=*(a+11);
	z=*(a+12);
	//printf("CODE IN PYTHON -\n");
	//printf("\tfor %c in range(%c,%c%c):\n",b,x,y,z+1);
        char test[45]="for b in range(x,yz):\n";
        int countcode2=strlen(code2);
        for(int i=0;test[i]!='\0';i++){
                if(test[i]=='b'){
                        code2[countcode2]=b;
                }
                else if(test[i]=='x'){
                        code2[countcode2]=x;
                }
                else if(test[i]=='y'){
                        code2[countcode2]=y;
                }
                else if(test[i]=='z'){
                        code2[countcode2]=z+1;
                }
                else{
                        code2[countcode2]=test[i];
                }
                countcode2++;
        }

      }
      else
       {
	  b=*(a+4);
	  x=*(a+6);
	  d=*(a+7);
	  y=*(a+11);
	  z=*(a+12);
	  //printf("CODE IN PYTHON -\n");
	  //printf("\tfor %c in range(%c%c,%c%c):\n",b,x,d,y,z);
          char test[45]="for b in range(xd,yz):\n";
        int countcode2=strlen(code2);
        for(int i=0;test[i]!='\0';i++){
                if(test[i]=='b'){
                        code2[countcode2]=b;
                }
                else if(test[i]=='x'){
                        code2[countcode2]=x;
                }
                else if(test[i]=='d'){
                        code2[countcode2]=d;
                }
                else if(test[i]=='y'){
                        code2[countcode2]=y;
                }
                else if(test[i]=='z'){
                        code2[countcode2]=z;
                }
                else{
                        code2[countcode2]=test[i];
                }
                countcode2++;
        }

       }
  }

  else if(s==17)
  {
      c=*(a+10);
       if(c!='=')
      {
	 b=*(a+4);
	 x=*(a+6);
	 y=*(a+10);
	 z=*(a+11);
	// printf("CODE IN PYTHON -\n");
	// printf("\tfor %c in range(%c,%c%c):\n",b,x,y,z);
        char test[45]="for b in range(x,yz):\n";
        int countcode2=strlen(code2);
        for(int i=0;test[i]!='\0';i++){
                if(test[i]=='b'){
                        code2[countcode2]=b;
                }
                else if(test[i]=='x'){
                        code2[countcode2]=x;
                }
                else if(test[i]=='y'){
                        code2[countcode2]=y;
                }
                else if(test[i]=='z'){
                        code2[countcode2]=z;
                }
                else{
                        code2[countcode2]=test[i];
                }
                countcode2++;
        }

       }
      else
       {
	  b=*(a+4);
	  x=*(a+6);
	  y=*(a+11);

	 // printf("CODE IN PYTHON -\n");
	//  printf("\tfor %c in range(%c,%c):\n",b,x,y+1);
        char test[45]="for b in range(x,y):\n";
        int countcode2=strlen(code2);
        for(int i=0;test[i]!='\0';i++){
                if(test[i]=='b'){
                        code2[countcode2]=b;
                }
                else if(test[i]=='x'){
                        code2[countcode2]=x;
                }
                else if(test[i]=='y'){
                        code2[countcode2]=y+1;
                }
                else{
                        code2[countcode2]=test[i];
                }
                countcode2++;
        }


	}
  }
   else if(s==19)
	{
	   b=*(a+4);
	   c=*(a+7);
	   x=*(a+6);
	   y=*(a+12);
	   z=*(a+13);
	 //  printf("CODE IN PYTHON -\n");
	 //  printf("\tfor %c in range(%c%c,%c%c):\n",b,x,c,y,z+1);
        char test[45]="for b in range(xc,yz):\n";
        int countcode2=strlen(code2);
        for(int i=0;test[i]!='\0';i++){
                if(test[i]=='b'){
                        code2[countcode2]=b;
                }
                else if(test[i]=='x'){
                        code2[countcode2]=x;
                }
                else if(test[i]=='c'){
                        code2[countcode2]=c;
                }
                else if(test[i]=='y'){
                        code2[countcode2]=y;
                }
                else if(test[i]=='z'){
                        code2[countcode2]=z+1;
                }
                else{
                        code2[countcode2]=test[i];
                }
                countcode2++;
        }

	 }
    else if(s==16)
	 {
	   b=*(a+4);
	   x=*(a+6);
	   y=*(a+10);
	  // printf("CODE IN PYTHON -\n");
	// printf("\tfor %c in range(%c,%c):\n",b,x,y);
        char test[45]="for b in range(x,y):\n";
        int countcode2=strlen(code2);
        for(int i=0;test[i]!='\0';i++){
                if(test[i]=='b'){
                        code2[countcode2]=b;
                }
                else if(test[i]=='x'){
                        code2[countcode2]=x;
                }
                else if(test[i]=='y'){
                        code2[countcode2]=y;
                }
                else{
                        code2[countcode2]=test[i];
                }
                countcode2++;
        }

	  }



}



//code for tabspace--sudhanva

void tab(char code2[])
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
        }
      else
        {
          codefinal[j]=code2[i];
          j++;
        }
    }
  codefinal[j]='\0';
}


//for print part -- Sudhanva

void print(char code[])
{
    int j=strlen(code2);
    int k=0;
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
    code2[j]=';';
    code2[strlen(code2)-1]='\n';

}
