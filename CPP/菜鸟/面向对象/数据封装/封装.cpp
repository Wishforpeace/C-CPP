#include<iostream>
using namespace std;

class Box
{
private:
    double length,breadth,height;
public:
    double getVolume(void)
    {
        return length*breadth*height;
    }
};
// 此处length breadth height都为私有的，只能被Box类的其他成员访问而不能被程序中其他部分访问

// 实例
class Adder{
    public:
        // 构造函数
        Adder(int i=0)
        {   
            total = i;
        }
        // 对外接口
        void addNum(int number)
        {
            total += number;
        }
        //  对外接口
        int getTotal(void)
        {
            return total;
        }
    private:
        int total;
};


int main()
{
    Adder a;
    a.addNum(10);
    a.addNum(20);
    a.addNum(30);

    cout<<"Total:"<<a.getTotal()<<endl;
}