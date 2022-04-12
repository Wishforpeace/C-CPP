#include <stdio.h>
int main(){
    double a;
    scanf("%lf",&a);
    int b = a*1000000;
    int numb[7];
    int i =0;
    while (b>=0)
    {
        numb[i]= b%10;
        b= b/10;
        ++i;
    }
    int j =0;
    double new=0;
    while (j<=5)
    {
       new=numb[j]*10+numb[j+1];
       ++j; 
    }
    double out = (new/1000000);
    printf("%lf",out);
    

    
}