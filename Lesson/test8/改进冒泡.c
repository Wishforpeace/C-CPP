#include<stdio.h>
#include<sys/time.h>
int main(){
    int array[10]={1,4,2,3,6,5,0,7,8,9};
    int length = sizeof(array)/sizeof(array[0]);
    int i,j;
    int k =length-1;
    int pos = 0;
    for(i=0;i<length-1;i++){
        int flag =0;
        for(j=0;j<k-1;j++){
            int t;
            if(array[j]>array[j+1]){
                t = array[j];
                array[j]=array[j+1];
                array[j+1]=t;
                flag= 1;
                pos=j;
            } 
        }
        k = pos;
        if(flag==0){
            break;
        }
    }
    for(i =0;i<length;i++){
        printf("%d ",array[i]);
        if(i==length-1){
            printf("\n");
        }
    }
}