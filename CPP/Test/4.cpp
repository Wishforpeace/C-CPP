#include <iostream>

using namespace std;

class ONE
{
public:
    virtual void f() { cout << "1"; }
};

class TWO : public ONE
{
public:
    TWO() { cout << "2"; }
};

class THREE : public TWO
{
public:
    virtual void f()
    {
        TWO::f();
        cout << "3";
    }
};

int main()
{
    ONE aa, *p;
    TWO bb;
    THREE cc;
    p = &cc;
    p->f();
    return 0;
}