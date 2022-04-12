#include<stdio.h>
#include <stdlib.h>

int main()
{
	float m;
	float c=1,b=0;
	int n,j,t,a[7];
	int i=0;
	scanf("%f",&m);
	for(i=0;i<=6;i++)
	{
		n=(int)m;
		a[i]=n;
		m=(m-n)*10;
		
	}	
	for(i=0;i<=6;i++)
	{
		printf("%d",a[i]);
    }
    printf("\n");
	for(i=6;i>=0;i--)
	{
		for(j=0;j<=i;j++)
		{
			if(a[j+1]<a[j])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}	
	for(i=0;i<=6;i++)
	{
		printf("%d",a[i]);
    }
    printf("\n");
    for(i=0;i<=6;i++)
    {
    	b=b+a[i]*c;
    	c=c*0.1;
    }
    printf("%f",b);
	return 0;
}