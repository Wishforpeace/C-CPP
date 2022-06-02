#include<stdio.h>
#include<string.h>
int Strlen(char *a){
    int length = 0;
    while (a[length]!='\0')
    {
        length ++;
    }
    return length;
}

int main()
{
    char array[]={"山本，我日你仙人,gggg"};
    int length;
    length = Strlen(array);
    printf("lenght=%d\n",length);

    printf("%lu\n",strlen(array));
    printf("%lu",sizeof(array)/sizeof(array[0])-1);
   
}