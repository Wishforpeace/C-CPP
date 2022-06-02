#include<stdio.h>
#include<string.h>
int main()
{
    char a[100] ={"123"};
    char b[100] = {"1234"};
    int i=0;
    int j=0;
    while (a[i]!='\0')
    {
       i++;
    }
    while (b[j]!='\0')
    {
        j++;
    }
    int result;
    result = (i>j);
    printf("%d\n",result);
   
    printf("%d", strncmp(a,b,10));
}