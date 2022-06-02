#include<stdio.h>
#include<math.h>

double NewTon(double X0,double X1){
    double s;
    X1=3;
   do
    {
       X0 = X1;
       X1= X0-(cos(X0)-X0)/(-sin(X0)-1);
        printf("X:%f\n",X1);
       s=fabs(X0-X1);
       printf("%f\n",s);

    }while (s>0.001);
    
    return X1;
}

double NewTonw(double X0,double X1){
    if (fabs(X0-X1)<0.001){
        return X1;
    }
    X0 = X1;
    X1= X0-(cos(X0)-X0)/(-sin(X0)-1);
    return X1;
}

int main(){
    double NewTon(double X0,double X1);
    double a,b,c;
    c=NewTon(a,b);
    printf("%.5lf\n",c);
}