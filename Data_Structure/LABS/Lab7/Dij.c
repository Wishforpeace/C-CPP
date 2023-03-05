#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXEDGE 20
#define MAXVEX 20
#define GRAPH_INFINITY 65535

typedef int Status;

typedef struct
{
    int vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

typedef int Patharc[MAXVEX];        // 存储最短路径下标的数组
typedef int ShortPathTable[MAXVEX]; // 用于存储到各点最短路径的权值和

void CreateMGraph(MGraph *G)
{
    int i, j;
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

void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{
    int v, w, k, min;
    int final[MAXVEX]; // final[w] = 1表示最终v0到达vw的最短路径
    for (v = 0; v < G.numVertexes; v++)
    {
        final[v] = 0;           // 全部顶点初始化为位置最短路径状态
        (*D)[v] = G.arc[v0][v]; // 将与v0有连线的顶点加上权值
        (*P)[v] = -1;           // 初始化路径数组P为-1
    }

    (*D)[v0] = 0;
    final[v0] = 1;

    // 主循环，每次求的v0到某个v点点最短路径
    for (v = 1; v < G.numVertexes; v++)
    {
        min = GRAPH_INFINITY;
        // 找到距离v0最近的顶点
        for (w = 0; w < G.numVertexes; w++)
        {

            if (!final[w] && (*D)[w] < min)
            {
                k = w;
                min = (*D)[w]; // 此时w点距离v0更近
            }
        }
        // 将找到的最近的点置为1
        final[k] = 1;
        // 修正当前最短路径及其距离
        for (w = 0; w < G.numVertexes; w++)
        {
            // 如果经过v顶点的路径比现在这条路径更短的话
            if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
            {
                (*D)[w] = min + G.arc[k][w];
                (*P)[w] = k;
            }
        }
    }
}

int main(void)
{
    int i, j, v0;
    MGraph G;
    Patharc P;
    ShortPathTable D; /* 求某点到其余各点的最短路径 */
    v0 = 0;

    CreateMGraph(&G);

    ShortestPath_Dijkstra(G, v0, &P, &D);

    printf("最短路径倒序如下:\n");
    for (i = 1; i < G.numVertexes; ++i)
    {
        printf("v%d - v%d : ", v0, i);
        j = i;
        while (P[j] != -1)
        {
            printf("%d ", P[j]);
            j = P[j];
        }
        printf("\n");
    }
    printf("\n源点到各顶点的最短路径长度为:\n");
    for (i = 1; i < G.numVertexes; ++i)
        printf("v%d - v%d : %d \n", G.vexs[0], G.vexs[i], D[i]);
    return 0;
}