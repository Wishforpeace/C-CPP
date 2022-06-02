#include<stdio.h>
int Fibonacci(int n)
{
    if(n<=0)
        return 0;
    else if(n==1)
        return 1;
    else
        return Fibonacci(n-1)+Fibonacci(n-2);
}

int main()
{
    int n;
    printf("请输入你需要的个数");
    scanf("%d",&n);
    int array[n];
    int i;
    for(i=0;i<n;i++)
    {
        array[i]=Fibonacci(i+1);
        if (i==0)
        {
            printf("{");
        }else if(i>0&&i<n-1)
        {
            printf("%d ",array[i]);
        }
        if(i==n-1)
        {
            printf("%d}",array[i]);
        }
    }

}