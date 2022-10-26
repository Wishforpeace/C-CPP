#include <iostream>

using namespace std;

class Complex
{
private:
    double real, image;

public:
    Complex(double real = 0.0, double image = 0.0)
    {
        this->real = real;
        this->image = image;
    }
    void Display()
    {
        cout << "(" << this->real << "," << image << ")" << endl;
    }
    friend Complex operator+(ComplexA, Complex B)
    {
        return Complex(A.real + B.real, A.image + B.image);
    }
    // 减
    friend Complex operator-(Complex A, Complex B);
    // 取负
    friend Complex operator-(Complex A);
    // 前置++
    friend Complex operator++(Complex &A);
    // 后置++
    friend Complex operator
} int main()
{
}