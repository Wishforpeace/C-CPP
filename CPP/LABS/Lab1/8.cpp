#include<iostream>
using namespace std;


int main()
{
    string s="";
    cin>>s;
    int i;
    int flag = 1;
    int len = s.size();
    for(i=0;i<len/2;i++)
    {
        if(s[i]!=s[len-1-i])
        {
            flag = 0;
        }
    }
    if(flag){
        cout<<s<<" 是回文数"<<endl;
    }else{
        cout<<s<<" 不是回文数"<<endl;
    }
}