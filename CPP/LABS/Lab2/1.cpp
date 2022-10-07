#include<iostream>
#include <cmath>
using namespace std;
class Ctriangle
{
private:
    double side_a,side_b,side_c;
public:
    Ctriangle(double a,double b,double c);
    ~Ctriangle();
    void CalculatePerimeter();
    void CalculateArea();
};

Ctriangle::Ctriangle(double a,double b,double c)
{   
    cout<<"三边分别为:"<<" "<<a<<" "<<b<<" "<<c<<endl;
    side_a = a;
    side_b = b;
    side_c = c;
}

Ctriangle::~Ctriangle()
{
    cout<<"计算完成"<<endl;
}

void Ctriangle::CalculatePerimeter()
{
    cout<<"三角形周长为: "<<side_a+side_b+side_c<<endl;
}

void Ctriangle::CalculateArea()
{
    //海伦公式
    double p = (side_a+side_b+side_c)/2;
    double S;
    S = sqrt(p*(p-side_a)*(p-side_b)*(p-side_c));
    cout<<"三角形面积为: "<<S<<endl;
}

int main()
{
    double a,b,c;
    cout<<"请输入三角形三边:";
    cin>>a;
    cin>>b;
    cin>>c;
    Ctriangle ctriangle(a,b,c);
    ctriangle.CalculatePerimeter();
    ctriangle.CalculateArea();
}