#include <iostream>
using namespace std;

// 全局重载
class Complex
{
private:
    double m_real, m_imag;

public:
    Complex();
    Complex(double real, double imag);
    void Display() const;
    friend Complex operator+(const Complex &A, const Complex &B);
};

Complex ::Complex(double real, double imag)
{
    m_real = real;
    m_imag = imag;
}

Complex ::Complex()
{
}
Complex operator+(const Complex &A, const Complex &B)
{
    return Complex(A.m_real + B.m_real, A.m_imag + B.m_imag);
}

void Complex::Display() const
{
    cout << m_real << " " << m_imag << endl;
}
int main()
{
    Complex A(10, 12);
    Complex B(5, 6);
    Complex C;
    C = A + B;
    C.Display();
}