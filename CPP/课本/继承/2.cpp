#include <iostream>

using namespace std;
class MyClass
{
public:
    MyClass() { cout << "A"; }
    MyClass(char c)
    {
        cout << c;
    }
    ~MyClass() { cout << "B"; }
};
int main()
{
    MyClass p1, *p2;
    p2 = new MyClass('X');
    delete p2;
    return 0;
}