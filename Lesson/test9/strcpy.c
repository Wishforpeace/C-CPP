#include<stdio.h>
#include<string.h>
char* Strcpy(char a[],char b[100]) 
{  
   int i ;
   for(i=0;a[i]!='\0';i++)
   {
       b[i] = a[i];
   }
   return b;
}
   


int main(){
    char a[] = {"hhhh"};
    char b[100] ;
    b=Strcpy(a,b);
    printf("%s",b);
}