//顶点的抽象类
#ifndef vertexIterator_
#define vertexIterator_
using namespace std;
template <class T>
class vertexIterator
{
public:
    virtual ~vertexIterator() {}
    virtual int next() = 0;
    virtual int next(T &) = 0;
};
#endif