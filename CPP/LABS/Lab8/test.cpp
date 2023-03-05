#include <iostream>
#include <math.h>
using namespace std;

class Point
{
protected:
    float X, Y;

public:
    Point(float x, float y);
    float Distance(Point q);
};

Point::Point(float x, float y)
{
    X = x;
    Y = y;
}

float Point::Distance(Point q)
{

    return hypot(X - q.X, Y - q.Y);
}
int main()
{
    Point p(1, 1);
    Point q(2, 2);
    cout << p.Distance(q) << endl;
}