#include<stdio.h>
#include<string.h>
int main(){
    int a[2][3]={4,5,6};
    int i ;
    int j;
    int length= sizeof(a)/sizeof(a[0]);
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("%d\n",a[i][j]);
        }
        
    }
}