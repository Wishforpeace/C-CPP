#include<stdio.h>
int main()
{
    float n = 4.5267;
    int m;
    n = (n*100+0.5)/100.0;
    printf("n:%f\n",n);
    m = n*100+0.5,n=m/100.0;
    printf("n:%f\n",n);
    n=n*100+0.5/100.0;
    printf("n:%f\n",n);
    n = (n/100+0.5)*100.0;
    printf("n:%f\n",n);

}
