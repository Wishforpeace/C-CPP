#include<stdio.h>
int main()
{
    char a[]= {"hello"};
    char b[]={"world"};
    char c[1000];
    int i =0;
    while (a[i] !='\0')
    {
        c[i] = a[i];
        i++;
    }
    int j = 0 ;
    while(b[j]!= '\0')
    {
        c[i] = b[j];
        i++;
        j++;
    }
    printf("%s",c);
}