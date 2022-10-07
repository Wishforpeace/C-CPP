#include<iostream>

using namespace std;

int main()
{
    string SStr = "abcde";
    string DStr = "fghi";
    int i;
    for(i=0;i<DStr.size();i++)
    {
        SStr += DStr[i];
    }
    cout<<SStr<<endl;
}