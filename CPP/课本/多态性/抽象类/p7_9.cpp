#include <iostream>

using namespace std;
class Shape
{
public:
    //纯虚函数
    virtual double area() const = 0;
    virtual void show() = 0;
};

class Point : public Shape
{
protected:
    int X, Y;

public:
    Point(int X = 0; int Y = 0)
    {
        this->X = X;
        this->Y = Y;
    }
    void show()
    {
        cout << "(" << X << "," << Y << ")" << endl;
    }
} int main()
{
}