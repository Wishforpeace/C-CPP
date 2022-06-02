#include<iostream>
#include<cmath>
using namespace std;
 
const int n = 8;

void Queen(int chess[],int k, int &sum)
{
	bool flag;   //用于标志当前布局是否可行
	if(k <= n)
	{
		for(int i = 1; i <= n; i++)
		{
			chess[k] = i; 
			flag = true;
			for(int j = 1; j < k; j++)
			{
				if(chess[k] == chess[j]  ||								//排除同列
				   abs(k-j) == abs(chess[k] - chess[j]))	            //排除在对角线上 
				{
					flag = false;
				}
			}
			
			if(flag)		 
			{
				if(k == n)
				{
					sum++;
					for(int j = 1; j <= n; j++)
					{
						cout<<"("<<j<<","<<chess[j]<<")\t";
					}
					cout<<endl;
				}
				else
				{
					Queen(chess, k+1, sum);
				}
			}
		}
	} 
} 
int main()
{
	int layout[n+1];
	int i,sum =0;
	for(int i = 0; i <= n; i++)
	{
		layout[i] = 0;
	}
	Queen(layout,1,sum);
	cout<<n<<"皇后解的数量有"<<sum<<"个"<<endl; 
}
