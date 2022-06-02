#include<stdio.h>
int main()
{
    int bag[5][2]={{2,6},{2,3},{6,5},{5,4},{4,6}};
    int i ;
    int j;
    int k;
    int w;
    int t;
    int v;
    int weight;
    int value;
    int position[1000][2];
    printf("请输入背包大小W");
    scanf("%d",w);
    for(i=0;i<5;i++)
    {   
        weight = 0 ;
        value = 0;
        value += bag[i][1];
        weight += bag[i][0];
        t = weight;
        v = value;
        if(weight<w){
            for(j=i+1;j<5;j++){
                weight = t;
                value = v;
                weight +=bag[j][0];
                value += bag[j][0];
                t = weight;
                v = value;
                if(weight<w){
                    for(k=j+k;k<5;k++){
                        weight = t;
                        value = v;
                        weight +=bag[j][0];
                        value += bag[j][0];
                        t = weight;
                        v = value;
                        if(weight<w){
                                
                        }
                    }
                }
            }
        }
    }
}