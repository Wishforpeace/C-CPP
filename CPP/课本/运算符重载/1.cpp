#include <iostream>
using namespace std;

class Complex
{
public:
    double real, imag;
    Complex(double a, double b);
    Complex operator+(const Complex &A) const;
    Complex operator++(int);
    Complex operator-(const Complex &A) const;
    Complex operator--(int);
    void Display();
};

Complex::Complex(double a, double b)
{
    this->real = a;

    this->imag = b;
}

Complex Complex::operator+(const Complex &A) const
{
    return Complex(real + A.real, imag + A.imag);
}

Complex Complex::operator++(int)
{
    return Complex(real + 1, imag);
}

Complex Complex::operator-(const Complex &A) const
{
    return Complex(real - A.real, imag - A.imag);
}

Complex Complex::operator--(int)
{
    return Complex(real - 1, imag);
}

void Complex::Display()
{
    if (imag >= 0)
    {
        cout << real << "+" << imag << "i" << endl;
    }
    else
    {
        cout << real << imag << "i" << endl;
    }
}

int main()
{
    Complex A(1, -5);
    Complex B(2, 3);
    A.Display();
    A++;
    A.Display();
    A--;
    A.Display();
    (A + B).Display();
}