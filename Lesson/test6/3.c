#include<stdio.h>
void Chicken(){
    int num[3];
    int i,j,k ;
    for( i =0;i<=20;i++){
        for( j =0;j<=33;j++){
            for( k = 0;k <=300;k++){
                int cost = 5*i+3*j+k;
                if(cost==100&&i+j+3*k==100){
                   printf("可以买母鸡%d，公鸡%d，小鸡%d\n",i,j,3*k);
                }
              
            }
           
        }
       
    }
    
}
int main(){
    Chicken();
}