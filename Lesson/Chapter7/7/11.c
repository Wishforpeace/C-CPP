#include<stdio.h>
#define MAX 15
int main()
{
    int m,mm,i,j,k,ni,nj;
    int magic[MAX][MAX] ={0};
    printf("Enter the number you wanted:");
    scanf("%d",&m);
    if((m <= 0)||(m%2 == 0))
    {
        printf("Error in put data.\n");
        return -1;
    } 
    mm = m*m;
    i = 0 ;
    j = m/2;
    for(k =1;k<=mm;k++){
        magic[i][j]=k;
        if(i==0)
        {
            ni = m-1;

        }else{
            
        }
    }

}