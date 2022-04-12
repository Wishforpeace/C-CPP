#include<stdio.h>
int main(){
    int a[5]={1,3,5,7,9};
    int b[5]={2,4,6,8,10};
    int array[10];
    int index=0;
    int i ;
    int lena = sizeof(a)/sizeof(a[0]);
    int lenb = sizeof(b)/sizeof(b[0]);
    for (i=0;i<lena;i++){
        array[index]= a[i];
        index++;
    }
    for (i=0;i<lenb;i++){
        array[index]= b[i];
        index++;
    }
    for(i=0;i<10;i++){
        printf("array:%d\n",array[i]);
    }
    int j,k;
    int length= sizeof(array)/sizeof(array[0]);
    printf("length%d\n",length);
    for (j =0;j<length-1;j++){
        for(k=0;k<length-1-j;k++){
            if(array[k]>array[k+1]){
                int t;
                t=array[k];
                array[k]=array[k+1];
                array[k+1]=t;
            }
        }
    }
    for(i=0;i<length;i++){
        printf("%d ",array[i]);
    }
    return 0;
}