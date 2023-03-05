#include <stdio.h>
#include "stdlib.h"

#include "math.h"
#include "time.h"
#define MAXSIZE 20
#define Infinity 65535
#define OK 1
#define FALSE 0
#define TRUE 1
#define ERROR 0
typedef char VertexType;
typedef int EdgeType;

typedef struct
{
    VertexType Vertexes[MAXSIZE];
    EdgeType Arcs[MAXSIZE][MAXSIZE];
    int numVertexes, numEdges;
} MGraph;

void CreateMGraph(MGraph *G)
{
    G->numVertexes = 9;
    G->numEdges = 15;

    int i, j;
    for (i = 0; i < G->numVertexes; i++)
    {
        G->Vertexes[i] = 'A' + i;
    }

    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            G->Arcs[i][j] = Infinity;
        }
    }
    G->Arcs[0][1] = 1;
    G->Arcs[0][5] = 1;

    G->Arcs[1][2] = 1;
    G->Arcs[1][8] = 1;
    G->Arcs[1][6] = 1;

    G->Arcs[2][3] = 1;
    G->Arcs[2][8] = 1;

    G->Arcs[3][4] = 1;
    G->Arcs[3][7] = 1;
    G->Arcs[3][6] = 1;
    G->Arcs[3][8] = 1;

    G->Arcs[4][5] = 1;
    G->Arcs[4][7] = 1;

    G->Arcs[5][6] = 1;

    G->Arcs[6][7] = 1;

    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = 0; j < G->numVertexes; j++)
        {

            G->Arcs[j][i] = G->Arcs[i][j];
        }
    }
}

void BFSTraverse(MGraph G)
{
    int i, j;
    int visit[G.numVertexes];
    for (i = 0; i < G.numVertexes; i++)
    {
        
    }
}
int main()
{
    MGraph G;
    CreateMGraph(&G);
    int i;

    // for (i = 0; i < G.numVertexes; i++)
    // {
    //     printf("%c", G.Vertexes[i]);
    // }
}