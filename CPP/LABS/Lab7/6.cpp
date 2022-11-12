#include <iostream>

using namespace std;
class Shape
{
public:
    Shape(){};
    ~Shape(){};
    virtual double Area() = 0;
};

class Rectangle : public Shape
{
private:
    int width, length;

public:
    Rectangle(int w, int len);
    ~Rectangle(){};
    double Area();
};

Rectangle::Rectangle(int w, int len)
{
    this->width = w;
    this->length = len;
}

double Rectangle::Area()
{
    return this->width * this->length;
}

class Circle : public Shape
{
private:
    double radius;
    double pi;

public:
    Circle(double r);
    ~Circle(){};
    double Area();
};
Circle::Circle(double r)
{
    this->radius = r;
    this->pi = 3.14;
}

double Circle::Area()
{
    return pi * radius * radius;
}

int main()
{
    Shape *s;
    s = new Rectangle(5, 10);
    cout << "Rectangle Area:" << s->Area() << endl;
    s = new Circle(6.0);
    cout << "Circle Area:" << s->Area() << endl;
}