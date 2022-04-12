#include <stdio.h>
int calculus(int numb,int* a,int* b,int* c){
    *a = numb/100;
    *b = (numb-*a*100)/10;
    *c = numb%10;
    return 0 ;
}
int main(){
    int numb;
    printf("请输入一个数");
    scanf("%d",&numb);
    int a,b,c;
    calculus(numb,&a,&b,&c);
    printf("百位%d,十位%d,个位%d",a,b,c);
    return 0 ;
}

