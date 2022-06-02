#include<stdio.h>
#include<stdlib.h>

void Merge(int sourceArr[],int temArr[],int startIndex,int midIndex,int endIndex)
{
    int i = startIndex,j= midIndex+1,k =startIndex;
    while (i!=midIndex+1&&j!=endIndex+1)
    {
        if(sourceArr[i]>sourceArr[j])
            temArr[k++] =sourceArr[j++];
        else
            temArr[k++] =sourceArr[i++];
    }
    while (i != midIndex+1)
    {
       temArr[k++] = sourceArr[i++];
    }
    while (j != endIndex+1)
    {
        temArr[k++] = sourceArr[j++];
    }
    for(i = startIndex;i<=endIndex;i++)
    {
        sourceArr[i] = temArr[i];
    }
    
}

void MergeSort(int sourceArr[],int tempArr[],int startIndex,int endIndex)
{
    int midIndex;
    if(startIndex<endIndex)
    {
        midIndex =(startIndex+endIndex)/2;
        MergeSort(sourceArr,tempArr,startIndex,midIndex);
        MergeSort(sourceArr,tempArr,midIndex+1,endIndex);
        Merge(sourceArr,tempArr,startIndex,midIndex,endIndex);
    }
}

int main()
{
    int a[10]= {2,5,4,9,6,7,1,10,3,8};
    int i,b[10];
    MergeSort(a,b,0,9);
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}