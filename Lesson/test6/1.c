#include<stdio.h>
void Bit(){
    int n;
    printf("请输入任意正整数");
    scanf("%d",&n);
    int i = 0;
    int j = 0;
    for (int index= n;index>0;index/=10)
    {
        i ++;
    }
    printf("有%d十进制位",i);
    for(int index =n;index>0;index/=2 )
    {
        j++;
    }
    int a = n;
    int k =0;
    while (a!=0)
    {
       a = a>>1;
       k++;
    }
    
    printf("有%d个二进制位",j);
    printf("有%d个二进制位",k);
}
int main(){
    Bit();
}