#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define NUM 8
int chess[NUM]={0};
void try(int i);
int placebale(int i,int j);
void PrintfResult();

int placeable(int i,int j)
{
    int k;
    for(k=0;k<i;k++)
    {   // 列冲突
        if(chess[k]==j||abs(k-i)==abs(chess[k]-j))
            return 0;
    }
    return 1;
}

void PrintfResult()
{
    static int snum=1;
    int i;
    printf("====第%d个方案====",snum++);
    for(i=0;i<NUM;i++)
        printf("第%d行的皇后放在%d列\n",i+1,chess[i]+1);
    printf("\n");
}
void try(int i)
{
    int j;
    for(j=0;j<NUM;j++)
    {
        if (placeable(i,j)==1)
        {
            chess[i]=j;
            if(i==NUM-1)
            {
                PrintfResult();
            }else{
                try(i+1);
            }
        }
    }
}

int main()
{
    try(0);
    return 0;
}