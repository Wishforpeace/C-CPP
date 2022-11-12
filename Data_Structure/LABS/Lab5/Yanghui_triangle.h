#include <stdio.h>
#include "Queue.h"

void Yanghui(int n)
{
    Elemtype e;
    SqQueue Q;
    int i, k;
    for (i = 0; i < n; i++)
    {
        printf(" ");
    }
    printf("1\n"); //打出第一个1
    InitQueue(&Q, n + 2);
    EnQueue(&Q, 0);
    EnQueue(&Q, 1);
    EnQueue(&Q, 1);
    int s;
    k = 1;
    while (k < n)
    {
        for (i = 1; i <= n - k; i++)
        {
            printf(" ");
        }
        EnQueue(&Q, 0);
        do
        {
            DeQueue(&Q, &s);
            GetHead(Q, &e);
            if (e)
            {
                printf("%d ", e);
            }
            else
            {
                printf("\n");
            }
            EnQueue(&Q, s + e);
        } while (e != 0);
        k++;
    }
    DeQueue(&Q, &e);
    while (!QueueEmpty(Q))
    {
        DeQueue(&Q, &e);
        printf("%d ", e);
    }
}
