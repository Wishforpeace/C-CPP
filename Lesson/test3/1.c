#include<stdio.h>
double Average(double a,double b,double c){
    double average = (a+b+c)/3;
    return average;
}


int main(){
    double  a,b,c;
    printf("请输入三个数");
    scanf("%lf %lf %lf",&a,&b,&c);
    double average =Average(a,b,c);
    printf("%.2lf",average);
    return 0;
}