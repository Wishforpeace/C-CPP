#include<stdio.h>
void InsertSort(int numb[],int len){
    int i;
    int place;
    for(i=place;i<len;i++){
       if(numb[i]>numb[i+1]){
           place= i+1;
           break;
       }
    }
    int j,k;
    int key;
    for(j=place;j<len;j++){
        key=numb[j];
        k = j -1;
        while (k>=0&&numb[k]>key)
        {
          numb[k+1]=numb[k];
          k--;
        }
        numb[k+1]=key;
    }
    

}
int main(){
    int numb[10]={2,6,8,9,3,7,5,1,0,4};
   
    int i;
    int len = sizeof(numb)/sizeof(numb[0]);
     InsertSort(numb,len);
    for(i=0;i<len;i++){
        printf("%d ",numb[i]);
    }
}