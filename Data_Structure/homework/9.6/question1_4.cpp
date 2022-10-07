#include<iostream>
using namespace std;
void combi(int n)
{
    int i,j,k;
    int count = 0;
    for (i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            for(k=j+1;k<=n;k++)
            {
                cout<<i<<j<<k<<endl;
                count++;
            }
        }
    }
    cout<<count<<endl;
}

int main()
{
    combi(9);
}   