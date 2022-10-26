#include <stdio.h>
#include <stdlib.h>
#include "knapsacks.h"
int main()
{
    int num;
    printf("请输入物品个数n=");
    scanf("%d", &num);
    printf("请输入每个物品的体积:\n");
    int *w;
    w = (int *)malloc(sizeof(int) * num);
    int i;
    for (i = 0; i < num; i++)
    {
        printf("第%d个物品的体积:", i + 1);
        scanf("%d", &w[i]);
    }

    int T;
    printf("\n");
    printf("请输入背包体积T=");
    scanf("%d", &T);

    knapsack(w, T, num);
    return 0;
}