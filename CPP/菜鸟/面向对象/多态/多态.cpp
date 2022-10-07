#include <iostream>

using namespace std;
// 多态按字面的意思就是多种形态。当类之间存在层次结构，并且类之间是通过继承关联时，就会用到多态。
// C++ 多态意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数。
class Shape
{
protected:
    int width, height;

public:
    Shape(int a = 0, int b = 0)
    {
        width = a;
        height = b;
    }
    // int area()
    /*调用函数area()被编译器设置为基类中的版本，属于静态多类，函数调用在执行前
    就已经准备好，被称为早绑定
    加入virtual关键字
    编译器查看指针内容而非类型，调用各自的函数
    */

   //  定义虚函数，动态链接或后期绑定
    virtual int area()
    {
        cout << "Parent class area :" << endl;
        return 0;
    }
};

class Rectangle : public Shape
{
public:
    Rectangle(int a = 0, int b = 0) : Shape(a, b) {}
    int area()
    {
        cout << "Rectangle class area :" << endl;
        return (width * height);
    }
};

class Triangle : public Shape
{
public:
    Triangle(int a = 0, int b = 0) : Shape(a, b) {}
    int area()
    {
        cout << "Triangle class area :" << endl;
        return (width * height / 2);
    }
};

// 程序的主函数
int main()
{
    Shape *shape;
    Rectangle rec(10, 7);
    Triangle tri(10, 5);

    int a;

    // 存储矩形的地址
    shape = &rec;
    // 调用矩形的求面积函数 area
    a = shape->area();
    cout << a << endl;

    // 存储三角形的地址
    shape = &tri;
    // 调用三角形的求面积函数 area
    a = shape->area();
    cout << a << endl;

    return 0;
}