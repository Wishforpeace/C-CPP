#include <iostream>

using namespace std;
class Point
{
private:
    float x, y;

public:
    Point(float xx, float yy);
    ~Point();
};

Point::Point(float xx, float yy)
{
    this->x = xx;
    this->y = yy;
}

Point::~Point()
{
}

class Rectangle : public Point
{
private:
    float width, height;

public:
    Rectangle(float xx, float yy, float w, float h);
    float Area();
};

Rectangle ::Rectangle(float xx, float yy, float w, float h) : Point(xx, yy)
{
    this->width = w;
    this->height = h;
}

float Rectangle::Area()
{
    return width * height;
}

class Circle : public Point
{
private:
    float radius;

public:
    Circle(float xx, float yy, float r);
    float Area();
};

Circle ::Circle(float xx, float yy, float r) : Point(xx, yy)
{
    this->radius = r;
}
float Circle::Area()
{
    return 3.1415926 * radius * radius;
}
int main()
{
    Rectangle R(1, 2, 3, 4);
    cout << "R的面积为:" << R.Area() << endl;
    Circle C(3, 4, 5);
    cout << "C的面积为:" << C.Area() << endl;
}