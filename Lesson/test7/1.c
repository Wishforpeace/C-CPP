#include<stdio.h>
#include<memory.h>
#include<string.h>
int main(){
    int a[5]={1,2,3,4,5};
    int b[5];
    memcpy(b,a,5*sizeof(int));
    int i ;
    for ( i = 0; i < 5; i++)
    {
        printf("%d\n",b[i]);
    }
    
    int c =sizeof(str);
    printf("sizeof(float):%d",c);
}