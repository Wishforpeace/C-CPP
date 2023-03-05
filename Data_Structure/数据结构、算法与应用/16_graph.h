#ifndef graph_
#define graph_
using namespace std;
#include "edge.h"
#include "16_vertexIterator.h"
#include "../../codes/arrayQueue.h"
#include "../../codes/arrayStack.h"
#include "../../codes/myExceptions.h"
template <class T>
class graph
{
public:
    virtual ~graph() {}
    // const不可修改变量成员
    //=0表示成员函数为纯虚函数，可以理解为没有定义只有接口
    //由继承类来具体定义它的行为
    //如果一个类包含=0的函数，这个类为抽象类，不可以被实例化，只能由它派生子类

    // ADT
    //返回图的顶点数
    virtual int numberOfVertices() const = 0;
    //返回图的边树
    virtual int numberOfEdges() const = 0;
    //判断边(i,j)是否存在，存在返回true，不存在返回false
    virtual bool existEdge(int, int) const = 0;
    //插入边
    virtual void insertEdge(edge<T> *) = 0;
    //删除边
    virtual void eraseEdge(int, int) = 0;
    //返回顶点的度
    virtual int degree(int) const = 0;
    //返回顶点入度
    virtual int inDegree(int) const = 0;
    //返回顶点入度
    virtual int outDegree(int) const = 0;

    // Others
    virtual bool directed() const = 0; //判断是否为有向图
    virtual boll weight() const = 0;   //判断是否是加权图
    virtual vertexIterator<T> *itertor(int) = 0;
};
#endif