#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;
#define OK 1
#define FALSE 0
#define ERROR 0
#define TRUE 1

#define MAXSIZE 20
#define Infinity 65535
typedef int Status;
typedef char VertexType;
typedef int EdgeType;

typedef struct
{
    int numVertexes, numEdges;
    VertexType Vertexes[MAXSIZE];
    EdgeType Edges[MAXSIZE][MAXSIZE];
} MGraph;

// 队列操作

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

Status EnQueue(Queue *Q, int e)
{
    // 队列已满
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
    if (Q->rear == Q->front)
    {
        return ERROR;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1 + MAXSIZE) % MAXSIZE;
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

// 标志访问数组
int visited[MAXSIZE];
void CreateMGraph(MGraph *G)
{
    int i, j;
    G->numEdges = 15;
    G->numVertexes = 9;

    // 读入顶点信息
    G->Vertexes[0] = 'A';
    G->Vertexes[1] = 'B';
    G->Vertexes[2] = 'C';
    G->Vertexes[3] = 'D';
    G->Vertexes[4] = 'E';
    G->Vertexes[5] = 'F';
    G->Vertexes[6] = 'G';
    G->Vertexes[7] = 'H';
    G->Vertexes[8] = 'I';

    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            G->Edges[i][j] = -1;
        }
    }

    G->Edges[0][1] = 1;
    G->Edges[0][5] = 1;

    G->Edges[1][2] = 1;
    G->Edges[1][8] = 1;
    G->Edges[1][6] = 1;

    G->Edges[2][3] = 1;
    G->Edges[2][8] = 1;

    G->Edges[3][4] = 1;
    G->Edges[3][7] = 1;
    G->Edges[3][6] = 1;
    G->Edges[3][8] = 1;

    G->Edges[4][5] = 1;
    G->Edges[4][7] = 1;

    G->Edges[5][6] = 1;

    G->Edges[6][7] = 1;

    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = i; j < G->numVertexes; j++)
        {
            G->Edges[j][i] = G->Edges[i][j];
        }
    }
}

// 深度优先
void DFS(MGraph G, int i)
{
    int j;
    visited[i] = TRUE;
    cout << G.Vertexes[i] << " ";
    for (j = 0; j < G.numVertexes; j++)
    {
        if (G.Edges[i][j] == 1 && (!visited[j]))
        {
            DFS(G, j);
        }
    }
}

void DFSTraverse(MGraph G)
{
    int i;
    for (i = 0; i < G.numVertexes; i++)
    {
        visited[i] = FALSE;
    }
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
    int i;
    for (i = 0; i < G.numVertexes; i++)
    {
        visited[i] = FALSE;
    }
    Queue Q;
    InitQueue(&Q);
    int j;
    for (i = 0; i < G.numVertexes; i++)
    {
        if (!visited[i])
        {
            visited[i] = TRUE;
            cout << G.Vertexes[i] << " ";
            EnQueue(&Q, i);
            while (!IsEmpty(Q))
            {
                DeQueue(&Q, &i);
                for (j = 0; j < G.numVertexes; j++)
                {
                    if (G.Edges[i][j] == 1 && !visited[j])
                    {
                        visited[j] = TRUE;
                        cout << G.Vertexes[j] << " ";
                        EnQueue(&Q, j);
                    }
                }
            }
        }
    }
}
int main()
{
    MGraph G;
    CreateMGraph(&G);
    int i, j;
    // for (i = 0; i < G.numVertexes; i++)
    // {
    //     for (j = 0; j < G.numVertexes; j++)
    //     {
    //         cout << G.Edges[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    DFSTraverse(G);
    cout << endl;
    BFSTraverse(G);
}