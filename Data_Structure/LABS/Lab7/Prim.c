#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

void CreateMGraph(MGraph *G)
{
    int i, j;

    G->numEdges = 15;
    G->numVertexes = 9;
    // 初始化图
    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            if (i == j)
            {
                G->arc[i][j] = 0;
            }
            else
            {
                G->arc[i][j] = GRAPH_INFINITY;
            }
        }
    }
    G->arc[0][1] = 10;
    G->arc[0][5] = 11;
    G->arc[1][2] = 18;
    G->arc[1][8] = 12;
    G->arc[1][6] = 16;
    G->arc[2][8] = 8;
    G->arc[2][3] = 22;
    G->arc[3][8] = 21;
    G->arc[3][6] = 24;
    G->arc[3][7] = 16;
    G->arc[3][4] = 20;
    G->arc[4][7] = 7;
    G->arc[4][5] = 26;
    G->arc[5][6] = 17;
    G->arc[6][7] = 19;

    // 无向图对称
    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = i; j < G->numVertexes; j++)
        {
            G->arc[j][i] = G->arc[i][j];
        }
    }
}

// Prim 生成最小生成树
void MiniSpanTree_Prim(MGraph G)
{
    int min, i, j, k;
    int adjvex[MAXVEX];  // 保存相关顶点的下标
    int lowcost[MAXVEX]; // 保存相关顶点间边的权值
    lowcost[0] = 0;      //  初始结点权值为0，v0加入书中
    adjvex[0] = 0;       // 初始化第一个顶点下标为0
    for (i = 1; i < G.numVertexes; i++)
    {
        lowcost[i] = G.arc[0][i]; // 将v0顶点与之有边权的都存入数组
        adjvex[i] = 0;            // 初始化都为v0的下标
    }

    for (i = 1; i < G.numVertexes; i++)
    {
        // 初始化最小权值为正无穷
        min = GRAPH_INFINITY;

        j = 1;
        k = 0;
        // 循环所有的结点
        while (j < G.numVertexes)
        {
            // 如果权值不为0且小于min
            if (lowcost[j] != 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        // 打印当前顶点边中权值最小的边
        printf("(%d,%d)\n", adjvex[k], k);
        lowcost[k] = 0; // 将当前顶点的权值设置为0，表示此顶点已经完成任务
        for (j = 1; j < G.numVertexes; j++)
        {
            // 如果下标为k，顶点各边权值小于此前这些顶点未被加入生成树权值
            if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
            {
                // 将较小的权值存入lowcost相应位置
                lowcost[j] = G.arc[k][j];
                // 将下标为k的顶点存入adjvex
                adjvex[j] = k;
            }
        }
    }
}

int main(void)
{
    MGraph G;
    CreateMGraph(&G);
    MiniSpanTree_Prim(G);
    return 0;
}