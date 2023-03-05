#include <iostream>
#include <string>
using namespace std;

class Sample
{
public:
    int *p;
};

int main()
{
    Sample s;
    int m = 5;
    s.p = &m;
    *s.p = 6;
    cout << *s.p << endl;
    string S = "12345";
    cout << S.length() <<","<<S.size()<< endl;
}