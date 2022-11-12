#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 //初始化长度

typedef int Status;
typedef int Elemtype;

typedef struct
{
    Elemtype data[MAXSIZE];
    int front;
    int rear;
    int size;
} SqQueue;

Status Visit(Elemtype c)
{
    printf("%d ", c);
    return OK;
}
Status InitQueue(SqQueue *Q, int n)
{
    Q->front = 0;
    Q->rear = 0;
    Q->size = n;
    return OK;
}

Status ClearQueue(SqQueue *Q)
{
    Q->front = Q->rear = 0;
    return OK;
}

Status QueueEmpty(SqQueue Q)
{
    if (Q.front == Q.rear)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int QueueLength(SqQueue Q)
{
    return (MAXSIZE + Q.rear - Q.front) % MAXSIZE;
}

//获取队首元素
Status GetHead(SqQueue Q, Elemtype *e)
{
    // 此时队列为空
    if (Q.front == Q.rear)
    {
        return ERROR;
    }
    *e = Q.data[Q.front];
    return OK;
}

//入队
Status EnQueue(SqQueue *Q, Elemtype e)
{
    //队列已满
    if ((Q->rear + 1) % MAXSIZE == Q->front)
    {
        return ERROR;
    }

    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE; // rear后移一位

    return OK;
}

//删除队首元素
Status DeQueue(SqQueue *Q, Elemtype *e)
{
    //队列为空
    if (Q->front == Q->rear)
    {
        return ERROR;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;

    return OK;
}

Status QueueTravserse(SqQueue Q)
{
    int i;
    i = Q.front;
    while ((i + Q.front) != Q.rear)
    {
        Visit(Q.data[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
    return OK;
}
