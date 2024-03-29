#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

#define MAXVEX 20
#define MAXEDGE 20
#define GRAPH_INFINITY 65535

typedef struct
{
    int vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

// 记录
typedef int Patharc[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

void CreateMGraph(MGraph *G)
{
    int i, j;

    /* printf("请输入边数和顶点数:"); */
    G->numEdges = 16;
    G->numVertexes = 9;

    for (i = 0; i < G->numVertexes; i++) /* 初始化图 */
    {
        G->vexs[i] = i;
    }

    for (i = 0; i < G->numVertexes; i++) /* 初始化图 */
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            if (i == j)
                G->arc[i][j] = 0;
            else
                G->arc[i][j] = G->arc[j][i] = GRAPH_INFINITY;
        }
    }

    G->arc[0][1] = 1;
    G->arc[0][2] = 5;
    G->arc[1][2] = 3;
    G->arc[1][3] = 7;
    G->arc[1][4] = 5;

    G->arc[2][4] = 1;
    G->arc[2][5] = 7;
    G->arc[3][4] = 2;
    G->arc[3][6] = 3;
    G->arc[4][5] = 3;

    G->arc[4][6] = 6;
    G->arc[4][7] = 9;
    G->arc[5][7] = 5;
    G->arc[6][7] = 2;
    G->arc[6][8] = 7;

    G->arc[7][8] = 4;

    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = i; j < G->numVertexes; j++)
        {
            G->arc[j][i] = G->arc[i][j];
        }
    }
}

void ShortestPath_Floyd(MGraph G, Patharc *P, ShortPathTable *D)
{
    int v, w, k;
    for (v = 0; v < G.numVertexes; v++)
    {
        for (w = 0; w < G.numVertexes; w++)
        {
            (*D)[v][w] = G.arc[v][w]; // D初始值即位对应点之间的权值
            (*P)[v][w] = w;           // P初始化为各个顶点本身
        }
    }
    for (k = 0; k < G.numVertexes; k++) // 遍历中间点
    {
        // 遍历图
        for (v = 0; v < G.numVertexes; v++)
        {
            for (w = 0; w < G.numVertexes; w++)
            {
                // 经过中间点k，路径小于直接连接两点
                if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w])
                {
                    (*D)[v][w] = (*D)[v][k] + (*D)[k][w];
                    (*P)[v][w] = (*P)[v][k]; // 路径设置为经过下标为k的顶点
                }
            }
        }
    }
}

int main(void)
{
    int v, w, k;
    MGraph G;

    Patharc P;
    ShortPathTable D; // 某点到其余点到最短路径

    CreateMGraph(&G);

    ShortestPath_Floyd(G, &P, &D);

    printf("各顶点间最短路径如下:\n");
    for (v = 0; v < G.numVertexes; v++)
    {
        for (w = v + 1; w < G.numVertexes; w++)
        {
            printf("v%d-v%d weight:%d", v, w, D[v][w]);
            k = P[v][w]; // 获取第一个路径顶点的下标
            printf(" path: %d", v);
            while (k != w)
            {
                printf(" -> %d", k);
                k = P[k][w];
            }

            printf(" -> %d\n", w);
        }
        printf("\n");
    }

    printf("最短路径D\n");

    for (v = 0; v < G.numVertexes; v++)
    {
        for (w = 0; w < G.numVertexes; w++)
        {
            printf("%d\t", D[v][w]);
        }
        printf("\n");
    }

    printf("最短路径P\n");
    for (v = 0; v < G.numVertexes; v++)
    {
        for (w = 0; w < G.numVertexes; w++)
        {
            printf("%d ", P[v][w]);
        }
        printf("\n");
    }
    return 0;
}