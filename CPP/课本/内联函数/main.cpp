#include<iostream>
using namespace std;

inline double CirArea(double radius)
{
    return 3.14 * radius * radius;
}

int main()
{
    double r1(1.0),r2(2);
    cout<<CirArea(r1)<<endl;
    cout<<CirArea(r1+r2+4)<<endl;
    return 0;
}