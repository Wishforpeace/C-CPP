#include <stdio.h>
#include <math.h>
int Judge(int a,int b,int c){
    if ((pow(b,2)-4*a*c)>=0){
        return 1;
    }else{
        return 0;
    }
}

int SolveEqutions(int a,int b,int c,float* x1,float* x2){
    int judge;
    judge=Judge(a,b,c);
    if (judge==1){
        *x1 = (-b+sqrt(pow(b,2)-4*a*c))/(2*a);
        *x2 = (-b-sqrt(pow(b,2)-4*a*c))/(2*a);
    };
    if (judge==0){
        printf("无解");
    };
    return 0;
}


int main(){
    int a,b,c;
    printf("请输入a\n");
    scanf("%d",&a);
    printf("请输入b\n");
    scanf("%d",&b);
    printf("请输入c\n");
    scanf("%d",&c);
    float x1,x2;
    SolveEqutions(a,b,c,&x1,&x2);
    printf("两个解为%f,%f",x1,x2);
    return 0;
}

