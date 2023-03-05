#include <stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef struct
{
    int front, rear;
    int data[MAXSIZE];
} Queue;

Status InitQueue(Queue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

Status IsEmpty(Queue Q)
{
    if (Q.front == Q.rear)
    {
        return TRUE;
    }
    return FALSE;
}
Status EnQueue(Queue *Q, int e)
{
    // 先判断满没满
    if ((Q->rear + 1) % MAXSIZE == Q->front)
    {
        return ERROR;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return OK;
}

Status DeQueue(Queue *Q, int *e)
{
    if (IsEmpty(*Q))
    {
        return FALSE;
    }
    *e = Q->front;
    Q->front = (Q->front + 1) % MAXSIZE;
    return OK;
}
