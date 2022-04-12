#include<stdio.h>
#include<math.h>



int main(){
   printf("请输入任意自然数");
    int num;
    scanf("%d",&num);
    int m;
    m= num;
    printf("将为你拆解为几个数%d",m);

    int cubic;
    cubic = (int)pow(num,3);
    printf("cubic:%d\n",cubic);
    int part[m];
    int length = sizeof(part)/sizeof(part[0]);
    printf("sizeof part:%d\n",length);
    int i,j;
    int judge = ((cubic/m)+2*(m/2));
    printf("Judege:%d",judge);
    for ( i =0;i<=cubic/2;i++)
    {
        int index= 2*i+1;
        printf("index:%d ",index);
        int sum = m*index+(m-1)*(2+2*(m-1))/2;
        printf("sum:%d\n",sum);
        if (sum==cubic)
        {
            printf("结果:%d\n",index);
           for(j=0;j<m;j++)
           {
               part[j]= index;
               index+=2;
               printf("part:%d\n",part[j]);
           }
            break;
        }
    }
    printf("%d^3=",num);
    for ( i = 0; i < m;i++)
    {
      if (i==0){
          printf("%d",part[i]);
      }else{
          printf("+%d",part[i]);
      }
    }
    
}