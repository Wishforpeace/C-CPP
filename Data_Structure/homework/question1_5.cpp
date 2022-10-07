#include<iostream>
using namespace std;
void Accumulate(int a[],int n,int x)
{
    int i;
    int result=0;
    for(i=0;i<n;i++)
    {
        result+=a[i];
    }
    cout<<result<<endl;
}

int main()
{
    int a[100];
    int n,i;
    cout<<"请输入需要输入的个数:";
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int x ;
    cout<<"请输入x0:";
    cin>>x;
    Accumulate(a,n,x);
}