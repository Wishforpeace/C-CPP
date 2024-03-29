#ifndef unweightedEdge_
#define unweightedEdge_
using namespace std;
#include "16_edge.h"
#include "../../codes/myExceptions.h"

class unweightedEdge : public edge<bool>
{
public:
    unweightedEdge(int theV1, int theV2)
    {
        v1 = theV1;
        v2 = theV2;
    }
    ~unweightedEdge(){};
    int vertex1() const { return v1; }
    int vertex2() const { return v2; }
    bool weight() const { throw undefinedMethod("weight"); }

private:
    int v1, v2;
};

#endif