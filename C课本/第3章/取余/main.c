#include<stdio.h>
int main()
{
    int k = 7,x = 12;
    x %= (k %= 5);
    printf("%d",x);
}z