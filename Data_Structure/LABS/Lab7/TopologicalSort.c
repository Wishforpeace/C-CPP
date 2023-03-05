#include "stdio.h"
#include "stdlib.h"
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXEDGE 20
#define MAXVEX 14
#define MAXSIZE 20
typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */

// 邻接矩阵
typedef struct
{
    int vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

// 邻接表

// 边表结点
typedef struct EdgeNode
{
    int adjvex;            // 对应邻接点域，及点的下标
    int weight;            // 边的权重
    struct EdgeNode *next; // 下一个结点
} EdgeNode;

typedef struct VertexNode
{
    int in;                    // 顶点的入度
    int data;                  // 点的下标
    EdgeNode *firstedge;       // 边表的头结点
} VertexNode, AdjList[MAXVEX]; // 定义顶点表数组

typedef struct AdjGraph // 定义邻接表
{
    AdjList adjlist;           // 顶点表
    int numVertexes, numEdges; // 邻接表的顶点个数及边的个数
} graphAdjList, *GraphAdjList;

// 初始化邻接矩阵，构建图
void CreateMGraph(MGraph *G)
{
    int i, j;

    /* printf("请输入边数和顶点数:"); */
    G->numEdges = MAXEDGE;
    G->numVertexes = MAXVEX;

    for (i = 0; i < G->numVertexes; i++) /* 初始化图 */
    {
        G->vexs[i] = i;
    }

    for (i = 0; i < G->numVertexes; i++) /* 初始化图 */
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            G->arc[i][j] = 0;
        }
    }

    G->arc[0][4] = 1;
    G->arc[0][5] = 1;
    G->arc[0][11] = 1;
    G->arc[1][2] = 1;
    G->arc[1][4] = 1;
    G->arc[1][8] = 1;
    G->arc[2][5] = 1;
    G->arc[2][6] = 1;
    G->arc[2][9] = 1;
    G->arc[3][2] = 1;
    G->arc[3][13] = 1;
    G->arc[4][7] = 1;
    G->arc[5][8] = 1;
    G->arc[5][12] = 1;
    G->arc[6][5] = 1;
    G->arc[8][7] = 1;
    G->arc[9][10] = 1;
    G->arc[9][11] = 1;
    G->arc[10][13] = 1;
    G->arc[12][9] = 1;
}

// 创建邻接表
void CreateAdjGraph(MGraph G, GraphAdjList *GL)
{
    int i, j;
    EdgeNode *e;

    *GL = (GraphAdjList)malloc(sizeof(graphAdjList));

    (*GL)->numVertexes = G.numVertexes;
    (*GL)->numEdges = G.numEdges;
    for (i = 0; i < G.numVertexes; i++)
    {
        (*GL)->adjlist[i].data = G.vexs[i]; // 初始化顶点表
        (*GL)->adjlist[i].in = 0;
        (*GL)->adjlist[i].firstedge = NULL; // 空表
    }

    // 赋值，建立边表
    for (i = 0; i < G.numVertexes; i++)
    {
        for (j = 0; j < G.numVertexes; j++)
        {
            if (G.arc[i][j] == 1) // 如果两个顶点之间互通
            {
                e = (EdgeNode *)malloc(sizeof(EdgeNode));
                e->adjvex = j;
                // 类似于链表操作，插入到顶点表与firstnode之间
                e->next = (*GL)->adjlist[i].firstedge;
                (*GL)->adjlist[i].firstedge = e;
                (*GL)->adjlist[j].in++;
            }
        }
    }
}

// 栈操作
typedef struct
{
    int data[MAXSIZE];
    int top; // 栈顶指针
} SqStack;

// 初始化栈
Status InitStack(SqStack *S)
{
    S->top = -1;
    return OK;
}

// 是否为空
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

// 入栈
Status Push(SqStack *S, int e)
{
    if (S->top < MAXSIZE - 1)
    {
        S->top++;
        S->data[S->top] = e;
        return OK;
    }
    else
    {
        return ERROR;
    }
}

// 出栈
Status Pop(SqStack *S, int *e)
{
    if (S->top == -1)
    {
        return ERROR;
    }
    *e = S->data[S->top--];
    return OK;
}

// 获取栈顶元素
Status GetPop(SqStack S, int *e)
{
    if (S.top == -1)
    {
        return ERROR;
    }
    *e = S.data[S.top];
    return OK;
}
//  拓扑排序
Status TopologicalSort(GraphAdjList GL)
{
    EdgeNode *e;
    int i, k, gettop;
    int top = 0;
    int count = 0;
    SqStack *stack;
    stack = (SqStack *)malloc(sizeof(SqStack));
    InitStack(stack);
    for (i = 0; i < GL->numVertexes; i++)
    {
        if (GL->adjlist[i].in == 0) // 入度为0，入栈
        {
            Push(stack, i);
        }
    }

    // 栈不为空
    while (!StackEmpty(*stack))
    {
        Pop(stack, &gettop);
        printf("%d -> ", GL->adjlist[gettop].data); // 打印出栈结点对应的点下标
        count++;                                    // 输出i号顶点，计数
        // 将与i相连的结点的入度减1
        for (e = GL->adjlist[gettop].firstedge; e; e = e->next)
        {
            //  遍历边表结点
            k = e->adjvex;
            GL->adjlist[k].in--;        // 边表结点对应的顶点表减1
            if (GL->adjlist[k].in == 0) // 入度为0，进栈
            {
                Push(stack, k);
            }
        }
    }
    printf("\n");
    // 无法全部遍历，图是非连通图
    if (count < GL->numVertexes)
    {
        return ERROR;
    }
    else
    {
        return OK;
    }
}

int main(void)
{
    MGraph G;
    GraphAdjList GL;
    int result;
    CreateMGraph(&G);
    CreateAdjGraph(G, &GL);
    result = TopologicalSort(GL);
    printf("result:%d", result);
    return 0;
}