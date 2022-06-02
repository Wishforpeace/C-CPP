#include<stdio.h>
#include<math.h>
#include <stdlib.h>
void EightQueen(int chess[],int k,int *sum)
{
   int flag=0;
   int i,j;
   if(k<=8)
   {
       for(i=1;i<=8;i++)
       {
           //确定皇后在第k行摆放的列位置，且一行只能摆放一个
           chess[k]=i;
           flag=1;
           //   比较是否有重复
           for(j=1;j<k;j++)
           {    //前面为列重复
                if(j==k)
                {
                    continue;
                }
               if(chess[k]==chess[j]||abs(k-j)==abs(chess[k]-chess[j]))
               {
                   flag=0;
               }
           }
       
            if(flag)
            {
                if(k==8)
                {
                    *sum+=1;
                }else
                {
                    EightQueen(chess,k+1,sum);
                }
            }
       }   
   }
}
int main()
{
    int layout[9]={0};
    // 用于求和
    int sum=0;
    // 从第0个开始
    EightQueen(layout,1,&sum);
    printf("八皇后问题，共有%d种解",sum);
}