#include<stdio.h>
int main(){
    int n=0,m=1,x=2;
    if(!n)x-=1;
    if(m)x-=2;
    if(x)x-=3;
    printf("%d\n",x);
    return 0 ;
}