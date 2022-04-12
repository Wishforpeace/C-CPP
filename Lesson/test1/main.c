#include<stdio.h>

int Date(int X,int N,int* out){
    int index;
    index = (N+X)%7;
    if (index==0){
        *out = 7;
    }else{
        *out = index;
    }
   
    return 0;
}
int main(){
    int X,N,out;
    printf("请输入两个数，第一个位为星期几，第二个为延迟时间");
    scanf("%d %d",&X,&N);
    Date(X,N,&out);
    printf("延迟后是星期%d开学",out);
    return 0;
}