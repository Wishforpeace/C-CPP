#include <iostream>
using namespace std;
void func_inner()
{
    throw "Unknown Exception";
    cout << "[1]This segment will not be executed." << endl;
}
void func_outer()
{
    func_inner();
    cout << "[2]This segment will not be executed." << endl;
}
int main()
{
    try
    {
        func_outer();
        cout << "[3]This segment will not be excuted." << endl;
    }
    catch (const char *&e)
    {
        cout << e << endl;
    }
    return 0;
}