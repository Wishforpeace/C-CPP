#include<iostream>

using namespace std;

class Box
{
public:
   double getVolume(void)
   {
        return length * height * breadth;
   }
   void setLength(double len)
   {
        length  = len
   }
   void setBreadth(double bre)
   {
        breadth = bre;
   }
   void setHeight(double hei)
   {
        height = hei;
   }
    // 重载运算符，将两个Box相加
    Box operator+(const Box&b)
    {
        Box box;
        box.length = this->length + b.length;
        box.height = this->height + b.height;
        box.breadth = this->breadth + b.breadth;
        return box;
    }
protected:
    double length;
    double height;
    double breadth;
};

int main(void)
{
    Box box1;
    Box box2;
    Box box3;

    double volume = 0.0;

    // box1
    box1.setLength(6.0);
    box1.setHeight(7.0);
    box1.setBreadth(8.0);

    // box2
    box2.setLength(6.0);
    box2.setHeight(7.0);
    box2.setBreadth(8.0);

    // box1的volume
    volume = box1.getVolume();
    cout<<"box1 的 volume:"<<volume<<endl;

    // box2的colume
    volume = box2.getVolume();
    cout<<"box2 的 volume:"<<volume<<endl;

    // box3 = box1+box2
    box3 = box1 + box2;

    volume = box3.getVolume();
    cout<<"box3 的 volume:"

}