#include<iostream>

using namespace std;


int main()
{
    string s = "";
    string result = "";
    cout<<"请输入一段字串"<<endl;
    cin>>s;
    cout<<"删除其中的c"<<endl;
    int i;
    for(i=0;i<s.size();i++)
    {
        if(s[i]!='c')
        {
            result=result+s[i];
        }
    }
    cout<<result;
}