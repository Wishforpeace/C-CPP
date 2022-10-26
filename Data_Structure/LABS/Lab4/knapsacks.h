#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef int ElemType;
typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef struct
{
    ElemType data[MAXSIZE];
    int top;
} SqStack;

//初始化栈
Status InitStack(SqStack *S)
{
    S->top = -1;
    return OK;
}
//检验栈是否为空
Status StackEmpty(SqStack S)
{
    if (S.top == -1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
// 压栈
Status Push(SqStack *S, ElemType e)
{
    if (S->top == MAXSIZE - 1)
    {
        return ERROR;
    }
    S->top++;
    S->data[S->top] = e;
    return OK;
}

// 出栈
Status Pop(SqStack *S, ElemType *e)
{
    if (S->top == -1)
    {
        return ERROR;
    }
    *e = S->data[S->top];
    S->top--;
    return OK;
}

//遍历输出
Status StackTraverse(SqStack S)
{
    int i;
    i = 0;
    while (i <= S.top)
    {
        printf("%d ", S.data[i++] + 1);
    }
    printf("\n");
    return OK;
}

void PrintStatus(Status status, char *string)
{
    if (status)
    {
        printf("%s successeded\n", string);
    }
    else
    {
        printf("%s failed\n", string);
    }
}

// w为物件体积  T为总体积 n为物品个数
void knapsack(int *w, int T, int n)
{
    Status status;
    SqStack S;
    int k = 0;
    status = InitStack(&S);
    PrintStatus(status, "Init Stack");
    do
    {
        //当背包没有装满，并且物品也没有遍历结束
        while (T > 0 && k < n)
        {
            //如果能够放下该物品
            if (T - w[0] >= 0)
            {
                Push(&S, k);
                T -= w[k];
            }
            k++;
        }
        if (T == 0)
        {
            printf("找到一组解(物品的序号)");
            StackTraverse(S);
        }
        Pop(&S, &k);
        T += w[k];
        k++;

    } while (!StackEmpty(S) || (k < n));
}
