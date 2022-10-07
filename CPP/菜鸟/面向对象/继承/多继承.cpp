#include<iostream>
using namespace std;

// 基类
class Shape
{
public:
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }
protected:
    int width;
    int height;

};

// 基类PaintCost
class PainCost 
{
    public:
    int getCost(int area)
    {
        return area *70;
    }
};
// 派生类
class Rectangle : public Shape,public PainCost
{
    public:
        int getArea()
        {
            return (width * height);
        }
};

int main(void)
{
    Rectangle Rect;
    int area;

    Rect.setWidth(5);
    Rect.setHeight(7);

    area = Rect.getArea();

    // 输出对象面积
    cout<<"Total area:"<<area<<endl;
    
    // 输出总花费
    cout<<"Total cost:"<<Rect.getCost(area)<<endl;

    return 0;
}
