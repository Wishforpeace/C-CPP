#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 9
#define MAXEDGE 15
#define MAXVEX 9

typedef int Status;
typedef int Boolean;

typedef char VertexType;
typedef int EdgeType;

// 邻接矩阵
typedef struct
{
    VertexType vexs[MAXSIZE];
    EdgeType arc[MAXSIZE][MAXSIZE];
    int numVertexes, numEdges;
} MGraph;

// ****************邻接表******************
typedef struct EdgeNode
{
    int adjvex; // 邻接点域，存储该顶点对应的下标
    int weight; // 用于存储权值
    struct EdgeNode *next;
} EdgeNode;

// 顶点表结点
typedef struct VertexNode
{
    int in;              // 顶点入度
    char data;           // 顶点域，存储顶点信息
    EdgeNode *firstedge; // 边表头指针
} VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVertexs, numEdges;
} graphAdjList, *GraphAdjList;

// 循环队列
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
    if (QueueEmpty(*Q))
    {
        return ERROR;
    }

    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;

    return OK;
}

void CreateMGraph(MGraph *G)
{
    int i, j;

    G->numEdges = 15;
    G->numVertexes = 9;

    /* 读入顶点信息,建立顶点表 */
    G->vexs[0] = 'A';
    G->vexs[1] = 'B';
    G->vexs[2] = 'C';
    G->vexs[3] = 'D';
    G->vexs[4] = 'E';
    G->vexs[5] = 'F';
    G->vexs[6] = 'G';
    G->vexs[7] = 'H';
    G->vexs[8] = 'I';

    for (i = 0; i < G->numVertexes; i++) /* 初始化图 */
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

    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = i; j < G->numVertexes; j++)
        {
            G->arc[j][i] = G->arc[i][j];
        }
    }
}

void CreateALGraph(MGraph G, GraphAdjList *GL)
{
    int i, j;
    EdgeNode *e;

    *GL = (GraphAdjList)malloc(sizeof(graphAdjList));

    (*GL)->numVertexs = G.numVertexes;
    (*GL)->numEdges = G.numEdges;
    for (i = 0; i < G.numVertexes; i++)
    {
        (*GL)->adjList[i].in = 0;
        (*GL)->adjList[i].data = G.vexs[i];
        (*GL)->adjList[i].firstedge = NULL;
    }

    for (i = 0; i < G.numVertexes; i++)
    {
        for (j = G.numVertexes - 1; j >= 0; j--)
        {
            if (G.arc[i][j] == 1)
            {
                e = (EdgeNode *)malloc(sizeof(EdgeNode));

                if (i == 1 && j == 8)
                {
                    e->adjvex = 6;
                }
                else if (i == 1 && j == 6)
                {
                    e->adjvex = 8;
                }
                else
                {
                    e->adjvex = j;
                }
                e->next = (*GL)->adjList[i].firstedge;
                (*GL)->adjList[i].firstedge = e;
                (*GL)->adjList[j].in++;
            }
        }
    }
}

Boolean visited[MAXSIZE];

void DFS(GraphAdjList GL, int i)
{
    EdgeNode *p;
    visited[i] = TRUE;
    printf("%c ", GL->adjList[i].data);
    p = GL->adjList[i].firstedge;
    while (p)
    {
        if (!visited[p->adjvex])
        {
            DFS(GL, p->adjvex);
        }
        p = p->next;
    }
}

void BFSTraverse(GraphAdjList GL)
{
    int i;
    EdgeNode *p;
    Queue Q;
    for (i = 0; i < GL->numVertexs; i++)
    {
        visited[i] = FALSE;
    }
    InitQueue(&Q);
    for (i = 0; i < GL->numVertexs; i++)
    {
        if (!visited[i])
        {
            visited[i] = TRUE;
            printf("%c ", GL->adjList[i].data);
            EnQueue(&Q, i);
            while (!QueueEmpty(Q))
            {
                DeQueue(&Q, &i);
                p = GL->adjList[i].firstedge;
                while (p)
                {
                    if (!visited[p->adjvex])
                    {
                        visited[p->adjvex] = TRUE;
                        printf("%c ", GL->adjList[p->adjvex].data);
                        EnQueue(&Q, p->adjvex);
                    }
                    p = p->next;
                }
            }
        }
    }
}

void DFSTraverse(GraphAdjList GL)
{
    int i;
    for (i = 0; i < GL->numVertexs; i++)
    {
        visited[i] = FALSE;
    }
    for (i = 0; i < GL->numVertexs; i++)
    {
        if (!visited[i])
        {
            DFS(GL, i);
        }
    }
}

int main(void)
{
    MGraph G;
    GraphAdjList GL;
    CreateMGraph(&G);
    CreateALGraph(G, &GL);

    printf("DFS:\n");
    DFSTraverse(GL);
    printf("\nBFS:\n");
    BFSTraverse(GL);
    return 0;
}