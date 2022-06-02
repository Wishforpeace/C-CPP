#include<stdio.h>
#include<string.h>
#define NUM 5
#define MAXWEIGHT 10
void BagPack()
{
    int value[NUM]  ={6,3,5,4,6};
    int weight[NUM] = {2,2,6,5,4};
    int subset[NUM] = {0};
    int maxset[NUM];
    int i ,j ,k;
    int s;
    int sumvalue,sumweight;
    int maxvalue;
    int upper = (1<<NUM)-1;// upper = 1<<5 -1    100000 ------- 11111
    for(i =1;i<upper;i++)// i<31
    {
        s=i; //s = 00001
        sumweight = sumvalue = 0; 
        memset(subset,0,NUM*sizeof(int)); //将subset前五个都设置为0
        for(j=0;s!=0;j++)   
        {
            subset[j] = s&1;    // 
            s = (unsigned int)s>>1;
        }
        for(k =0;k<NUM;k++){
            sumweight += weight[k]*subset[k];
            if(sumweight <= MAXWEIGHT)
            {
                sumvalue += value[k]*subset[k];
            }else
            {
                break;
            }
            
        }
        if(maxvalue<sumvalue)// 如果该子集合法，且价值超过 maxvalue
        {  
            maxvalue = sumvalue;
            memcpy(maxset,subset,NUM*sizeof(int));
        }
    }
    printf("item: ");
    for(k=0;k<NUM;k++){
        printf(maxset[k]?"%d ":" ",k+1);
    }
    printf(" are selected with max value: %d\n",maxvalue);
}

int main()
{
    BagPack();
}