#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
    double x, y;

public:
    Point(double cin_x, double cin_y);
    void Distance(const Point &p)
    {
        x -= p.x;
        y -= p.y;
        double distance = sqrt(x * x + y * y);
        cout << "两点距离为:" << distance << endl;
    }
};

Point::Point(double cin_x, double cin_y)
{
    x = cin_x;
    y = cin_y;
}

int main()
{
    double x1, y1, x2, y2;
    cout << "请输入Point1的横纵坐标:";
    cin >> x1;
    cin >> y1;
    cout << "请输入point2的横纵坐标:";
    cin >> x2;
    cin >> y2;
    Point p1(x1, y1);
    Point p2(x2, y2);
    p1.Distance(p2);
}