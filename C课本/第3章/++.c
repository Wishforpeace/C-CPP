#include<stdio.h>
int main()
{
    float a=1,b;
    b = ++a * ++a;
    printf("%f\n",b);
    return 0;
}