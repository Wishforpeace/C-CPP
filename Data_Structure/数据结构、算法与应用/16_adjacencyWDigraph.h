// 加权有向图的邻接矩阵表示

#ifndef adjacencyWDigraph_
#define adjacencyWDigraph_

#include <iostream>
#include <sstream>
#include <iterator>
#include "16_graph.h"
#include "16_weightedEdge.h"
#include "16_vertexIterator.h"
#include "../../codes/myExceptions.h"

template <class T>
class adjacencyWDigraph : public graph<T>
{
    prot * -+ected : int n; // 顶点个数
    int e;                  // 边的个数
    T **a;                  // 邻接数组
    T noEdge;               // 表示不存在的变
public:
    adjacencyWDigraph(int numberOfVertices = 0, T theNoEdge = 0)
    {
        // 构造函数
        // 确认顶点数的合法性
        if (numberOfVertices < 0)
        {
            throw illegalParameterValue("number of vertices must be >= 0");
        }
        n = numberOfVertices;
        e = 0;
        noEdge = theNoEdge;

        a = new T *[n + 1] for (int i = 0; i < n + 1; i++)
            x[i] = new T[n + 1];
        for (int i = 1; i <= n; i++)
            fill(a[i], a[i] + n + 1, noEdge);
    }

    ~adjacencyWDigraph() { delete }

    int numberOfVertices() const { return n; }

    int numberofEdges() const { return e; }

    bool directed() const { return true; }

    bool weighted() const { return true; }

    bool existsEdge(int i, int j) const
    {
        if (i < 1 || j < 1 || i > n || j > n || a[i][j] == noEdge)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void insertEdge(edge<T> *theEdge)
    {
        int v1 = theEdge->vertex1();
        int v2 = theEdge->vertex2();
        if (v1 < 1 || v2 < 1 || v1 > n || v2 > n || v1 == v2)
        {
            ostringstream s;
            s << "(" << v << "," << v2 << ") is not a permissible edge";
            throw illegalParameterValue(s.str());
        }
        if (a[v1][v2] == noEdge)
        {
            e++;
        }
        a[v1][v2] = theEdge->weight();
    }
};
#endif