#include<stdio.h>
void hanoi(int i ,char A,char B,char C);
void move(char x,char y);

int main()
{
    int n;
    
    printf("input the number of disks:");
    scanf("%d",&n);
    printf("the step to moving %d disks:\n",n);
    hanoi(n,'A','B','C');
    return 0;
}

void hanoi(int n,char A,char B,char C)
{
    if(n==1)// 递归结束条件
        move(A,C);
    else
    {
        hanoi(n-1,A,C,B);
        move(A,C);
        hanoi(n-1,B,A,C);
    }
}

void move(char x,char y)
{
    printf("%c----------->%c\n",x,y);
}