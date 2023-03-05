#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAX 100
#define GRAPH_INFINITY 65535

typedef int Status;
typedef char VertexType;
typedef int EdgeType;
typedef struct 
{
    VertexType vexs[MAX];
    EdgeType arc[MAX][MAX];
    int numNodes,numEdges;
}MGraph;

// 建立无向图的邻接矩阵表示
void CreateMGraph(MGraph *G)
{
    int i,j,k,w;
    printf("输入顶点数和边数：\n");
    scanf("%d %d",&G->numNodes,&G->numEdges);
    for(i=0;i<&G->numNodes;i++)
    {
        scanf(&G->vexs[i]);
    }

}
