#ifndef weightedEdge_
#define weightedEdge_
#include "16_edge.h"
using namespace std;

template <class T>
class weightedEdge : public
{
public:
    weightedEdge(){};
    weightedEdge(int theV1, int theV2, T theW)
    {
        v1 = theV1;
        v2 = theV2;
        w = theW;
    }
    ~weightedEdge(){};
    int vertex1() const { return v1; }
    int vertex2() const { return v2; }
    T weight() const { return w; }
    operator T()const{return w;}
    void output(ostream& out)const
    {
        out<<"("<<v1<<","<<v2<<","<<w<<")";
    }

private:
    int v1, v2;
    T W;
};

#endif
