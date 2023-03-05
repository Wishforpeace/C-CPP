#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    cout<<setprecision(4)
    <<setw(3)
    <<hex
    <<24
    <<",";
    cout<<dec<<24<<endl;
}