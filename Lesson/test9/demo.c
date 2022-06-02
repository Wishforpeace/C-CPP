#include<stdio.h>
#include<string.h>

int main()
{
    char a[]={"hello"};
    char b[100];
    strcpy(b,a);
    printf("%s",b);
 }