#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 30
#define MAXEDGE 30
#define GRAPH_INFINITY 65535

typedef int Status;

// 时间最早发生和最迟发生的数组
int *etv, *ltv;
int *stack1, *stack2;
int top1, top2;

/*-------邻接矩阵-----------*/
typedef struct
{
    int vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

/*--------邻接表-----------*/
// 边表节点
typedef struct EdgeNode
{
    int adjvex;            // 记录点下标
    int weight;            // 边的权重
    struct EdgeNode *next; // 下一个节点
} EdgeNode;

// 顶点表
typedef struct VertexNode
{
    int data;            // 存储下标值
    int in;              // 存储入度
    EdgeNode *firstnode; // 顶点表连接的第一个边表
} VertexNode, AdjList[MAXVEX];

// 邻接表
typedef struct
{
    AdjList adjlist; // 顶点表
    int numVertexes, numEdges;
} graphAdjList, *GraphAdjList;

void CreateMGraph(MGraph *G) /* 构件图 */
{
    int i, j;
    /* printf("请输入边数和顶点数:"); */
    G->numEdges = 13;
    G->numVertexes = 10;

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
                G->arc[i][j] = GRAPH_INFINITY;
        }
    }

    G->arc[0][1] = 3;
    G->arc[0][2] = 4;
    G->arc[1][3] = 5;
    G->arc[1][4] = 6;
    G->arc[2][3] = 8;
    G->arc[2][5] = 7;
    G->arc[3][4] = 3;
    G->arc[4][6] = 9;
    G->arc[4][7] = 4;
    G->arc[5][7] = 6;
    G->arc[6][9] = 2;
    G->arc[7][8] = 5;
    G->arc[8][9] = 3;
}

// 邻接表构建邻接矩阵
void CreateALGraph(MGraph G, GraphAdjList *GL)
{
    int i, j;
    EdgeNode *e;

    // 初始化邻接表
    (*GL) = (GraphAdjList)malloc(sizeof(graphAdjList));
    (*GL)->numEdges = G.numEdges;
    (*GL)->numVertexes = G.numVertexes;

    for (i = 0; i < G.numVertexes; i++)
    {
        (*GL)->adjlist[i].in = 0;
        (*GL)->adjlist[i].data = G.vexs[i];
        (*GL)->adjlist[i].firstnode = NULL;
    }

    for (i = 0; i < (*GL)->numVertexes; i++)
    {
        for (j = 0; j < (*GL)->numVertexes; j++)
        {
            if (G.arc[i][j] < GRAPH_INFINITY && G.arc[i][j] != 0)
            {
                e = (EdgeNode *)malloc(sizeof(EdgeNode));
                e->adjvex = j;
                e->weight = G.arc[i][j];
                e->next = (*GL)->adjlist[i].firstnode;
                (*GL)->adjlist[i].firstnode = e;
                (*GL)->adjlist[j].in++;
            }
        }
    }
}

/*--------------拓扑排序--------------*/
Status TopologicalSort(GraphAdjList GL)
{
    EdgeNode *e;
    int i, k, gettop;
    int count = 0; // 统计输出的顶点个数
    stack1 = (int *)malloc(sizeof(int) * (GL->numVertexes));
    top1 = 0;
    // 入度为零的入栈，作为起始点
    for (i = 0; i < GL->numVertexes; i++)
    {
        // printf("%d ", GL->adjlist[i].in);
        if (GL->adjlist[i].in == 0)
        {
            stack1[top1++] = GL->adjlist[i].data;
            // printf("%d\n", stack1[top1 - 1]);
        }
    }

    top2 = 0;
    // 时间最早发生的数组
    etv = (int *)malloc(GL->numVertexes * sizeof(int));
    for (i = 0; i < GL->numVertexes; i++)
    {
        etv[i] = 0;
    }

    stack2 = (int *)malloc(sizeof(int) * GL->numVertexes);

    printf("TopologicalSort:\n");
    while (top1 != 0)
    {
        gettop = stack1[top1--];
        printf("%d -> ", GL->adjlist[gettop].data);
        count++;

        stack2[++top2] = gettop; // 将弹出的顶点序号压入拓扑排序的栈
        for (e = GL->adjlist[gettop].firstnode; e; e = e->next)
        {
            k = e->adjvex;
            GL->adjlist[k].in--;
            // 入度为0，入栈
            if (GL->adjlist[k].in == 0)
            {
                stack1[++top1] = k;
            }
            // 求各顶点时间的最早发生时间etv值
            if ((etv[gettop] + e->weight) > etv[k])
            {
                etv[k] = etv[gettop] + e->weight;
            }
        }
    }
    printf("\n");
    if (count < GL->numVertexes)
    {
        return ERROR;
    }
    return OK;
}

/*---------------求关键路径-----------------*/
void CriticalPath(GraphAdjList GL)
{
    EdgeNode *e;
    int i, gettop, k, j;
    // 声明活动发生的最早时间和最迟发生时间
    int ete, lte;
    TopologicalSort(GL); //  求拓扑排序，计算出etv和stack2的值
    ltv = (int *)malloc(sizeof(int) * GL->numVertexes);
    for (i = 0; i < GL->numVertexes; i++)
    {
        ltv[i] = etv[GL->numVertexes - 1]; // 初始化
    }
    printf("etv:\t");
    for (i = 0; i < GL->numVertexes; i++)
    {
        printf("%d -> ", etv[i]);
    }
    printf("\n");

    while (top2 != 0)
    {
        gettop = stack2[top2--];
        // 求各顶点时间的最迟发生值
        for (e = GL->adjlist[gettop].firstnode; e; e = e->next)
        {
            k = e->adjvex;
            if (ltv[k] - e->weight < ltv[gettop])
            {
                ltv[gettop] = ltv[k] - e->weight;
            }
        }
    }
    printf("ltv:\t");
    for (i = 0; i < GL->numVertexes; i++)
    {
        printf("%d -> ", ltv[i]);
    }
    printf("\n");

    for (j = 0; j < GL->numVertexes; j++)
    {
        for (e = GL->adjlist[j].firstnode; e; e = e->next)
        {
            k = e->adjvex;
            ete = etv[j];             // 活动最早发生时间
            lte = ltv[k] - e->weight; // 活动最迟发生时间
            if (ete == lte)
            {
                printf("<v%d - v%d> length: %d\n", GL->adjlist[j].data, GL->adjlist[k].data, e->weight);
            }
        }
    }
}

int main()
{
    MGraph G;
    GraphAdjList GL;
    CreateMGraph(&G);
    CreateALGraph(G, &GL);
    CriticalPath(GL);
    return 0;
}