#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    string s = "";
    cin>>s;
    float len ;
    len = s.size();
    int i;
    char t;
    for(i=0;i<len/2;i++)
    {
      t = s[i]  ;
      s[i]=s[len-1-i] ;
      s[len-1-i] = t;
    }
    cout<<s<<endl;
}