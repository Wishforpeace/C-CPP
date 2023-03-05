#include <iostream>
using namespace std;
template <class T>
class TAdd
{
    T x, y;

public:
    TAdd(T a, T b) : x(a), y(b) {}
    int add() { return x + y; }
};

int main()
{
    TAdd<char> K('3', '4');
    cout << K.add();
}