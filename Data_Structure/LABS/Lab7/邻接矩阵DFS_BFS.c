#include "stdio.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean; // Boolean是bool类型的

typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 9
#define MAXEDGE 15
#define MAXVEX 9

typedef struct
{
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

// 使用的队列及其函数
typedef struct
{
    int data[MAXSIZE];
    int front;
    int rear;
} Queue;

Status InitQueue(Queue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

Status QueueEmpty(Queue Q)
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

Status EnQueue(Queue *Q, int e)
{
    // 队列是否已满
    if ((Q->rear + 1) % MAXSIZE == Q->front)
    {
        return ERROR;
    }
    // 赋值给队尾
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return OK;
}

Status DeQueue(Queue *Q, int *e)
{
    if (QueueEmpty(*Q))
    {
        return ERROR;
    }

    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return OK;
}

// 创建图
void CreateMGraph(MGraph *G)
{
    int i, j;

    G->numEdges = 15;
    G->numVertexes = 9;

    for (i = 0; i < G->numVertexes; i++)
    {
        G->vexs[i] = 'A' + i;
    }

    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            G->arc[i][j] = 0;
        }
    }

    G->arc[0][1] = 1;
    G->arc[0][5] = 1;

    G->arc[1][2] = 1;
    G->arc[1][8] = 1;
    G->arc[1][6] = 1;

    G->arc[2][3] = 1;
    G->arc[2][8] = 1;

    G->arc[3][4] = 1;
    G->arc[3][7] = 1;
    G->arc[3][6] = 1;
    G->arc[3][8] = 1;

    G->arc[4][5] = 1;
    G->arc[4][7] = 1;

    G->arc[5][6] = 1;

    G->arc[6][7] = 1;
}

// 标记已经访问的数组
Boolean visited[MAXVEX];

void DFS(MGraph G, int i)
{
    int j;
    visited[i] = TRUE;
    printf("%c ", G.vexs[i]);

    for (j = 0; j < G.numVertexes; j++)
    {
        if (G.arc[i][j] == 1 && !visited[j])
        {
            DFS(G, j); // 递归思路
        }
    }
}

void DFSTraverse(MGraph G)
{
    int i;
    for (i = 0; i < G.numVertexes; i++)
    {
        visited[i] = FALSE; // 初始化标记数组
    }

    // 对未访问过的顶点调用DFS，若是连通图，只会执行一次
    for (i = 0; i < G.numVertexes; i++)
    {
        if (!visited[i])
        {
            DFS(G, i);
        }
    }
}

void BFSTraverse(MGraph G)
{
    int i, j;
    Queue Q;
    for (i = 0; i < G.numVertexes; i++)
    {
        visited[i] = FALSE;
    }
    InitQueue(&Q);
    for (i = 0; i < G.numVertexes; i++)
    {
        if (!visited[i])
        {
            visited[i] = TRUE;
            printf("%c ", G.vexs[i]);
            EnQueue(&Q, i);
            while (!QueueEmpty(Q))
            {
                DeQueue(&Q, &i);
                for (j = 0; j < G.numVertexes; j++)
                {
                    if (G.arc[i][j] == 1 && !visited[j])
                    {
                        visited[j] = TRUE;
                        printf("%c ", G.vexs[j]);
                        EnQueue(&Q, j);
                    }
                }
            }
        }
    }
}



int main(void)
{
    MGraph G;
    CreateMGraph(&G);
    printf("DFS:\n");
    DFSTraverse(G);
    printf("\nBFS:\n");
    BFSTraverse(G);
}