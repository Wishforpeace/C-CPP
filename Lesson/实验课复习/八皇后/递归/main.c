#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define NUM 8
// 使用一维数组来存储每个棋子的位置
int chess[NUM] = {0};
// 采用递归方法，进行每一次尝试
void try(int i);
// 检查每一次拜访是否合理
int placeable(int i, int j);
// 打印出每种可能结果
void PrintResult();

// 主要的递归函数
// 第i行的判断
void try(int i)
{
    int j;
    // 因为八皇后不可能列相同，所以列位置j应该不重复
    for (j = 0; j < NUM; j++)
    {
        // 判断该位置，是否满足
        if (placeable(i, j) == 1)
        { // 满足规则
            chess[i] = j;
            if (i == NUM - 1)
            {
                // 计算出第一种可能的结果
                PrintResult();
            }
            else
            {
                try(i + 1);
            }
        }
    }
}

int placeable(int i, int j)
{
    int k;
    // 检查第i行之前的行是否满足条件
    for(k=0;k<i;k++)
    {
        if(chess[k]==j||abs(k-i)==abs(chess[k]-j))
        {
            return 0;
        }
    }
    return 1;
}

void PrintResult(){
    // 统计结果
    static int sum =1;
    printf("********第%d种结果是********",sum++);
    int i;
    for(i=0;i<NUM;i++)
    {
        printf("第%d行的皇后放在第%d列\n",i+1,chess[i]+1);
    }
    printf("\n");
}
int main()  
{
    try(0);
    return 0;
}
