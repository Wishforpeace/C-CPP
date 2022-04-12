#include <stdio.h>
int swap(int*a,int*b){
   int temp = *a;
   *a = *b;
   *b = temp;
   return 0;
}
int main(){
    int a,b;
    printf("方法一:\n请输入两个数\n");
    scanf("%d %d",&a,&b);
    swap(&a,&b);
    printf("方法一:\n原来a = %d,b = %d\n现在a = %d,b = %d\n",b,a,a,b);
    printf("方法二:\n请输入两个数\n");
    scanf("%d %d",&a,&b);
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("方法二:\n原来a = %d,b = %d\n现在a = %d,b = %d\n",b,a,a,b);
}

