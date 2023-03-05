#include <iostream>
using namespace std;
class A
{
public:
    static int a;
    void init() { a = 1; }
    A(int a = 2)
    {
        init();
        a++;
    }
};
int A::a = 0;
A obj;
int main()
{
    cout << obj.a;
    return 0;
}