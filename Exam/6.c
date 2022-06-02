#include<stdio.h>
int main(){
    char c='A';
    int i=1;
    int j;
    j=!c&&i++;
    printf("%d  %d",i,j);
    printf("%d",i);
}