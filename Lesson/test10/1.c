#include<stdio.h>
#include<string.h>
#define NUM 80
void MaxAffixLen(char T[],int next[]){
    int length = strlen(T);
    int i;
    int count=0;
    for(i=0;i<length;i++)
    {
        char index[i+1];
        memcpy(index,T,(i+1)*sizeof(char));
        printf("%s\n",index);
        int j;
        for(j=i+1;j>0;j--){
            /* 此处j+1,将index的字母取出判断
            如果 index :ababa
            此时temp
            a
            ab 
            aba
            */
            char temp[j];
            int flag=0;
            memcpy(temp,index,(j)*sizeof(char));
            int k;
            for(k=i+1-j;k<i+1;k++)
            {
                
                if(temp[k+1-j] !=temp[k])
                {
                    flag=1;
                }
                
            }
            if(flag==0){
                next[count]=j;
                count++;
            }
        }
    }
}
// void MaxAffixLenTaught(char T[],int next[]){
//     int i,j,k,len;
//     memset(next,0,sizeof(int)*NUM);
//     for(i=1;T[i]!='\0';i++)//列举所有的前缀子串
//     {
//         for(len=i;len>=i;len--)// 列举所有的真前后缀
//         {
//             for(j=0;j<len;j++)//判断长度为len的前后缀是否相等
//             {
//                 if(T[0+j]!=T[i-len+1+j])
//                     break;
//             }
//             if(j==len)
//             {
//                 next[i]=len;
//                 break;
//             }
//         }
//     }
//     for(i=0;i<strlen(T);i++){
//         printf("%d",next[i]);
//     }
//     printf("\n");
// }


// void KMP(char S[],char T[]){
//     int i=0,j=0;
//     int next[NUM];
//     MaxAffixLenTaught(T,next);
//     while(S[i]!='0'&&T[j]!='\0')
//     {
//         if(S[i]==T[j])
//         {
//             i++;
//             j++;
//         }else
//         {
//             if(j==0)
//                 i++;
//             else
//                 j=next[j=1];
//         }
//     }
//     if(T[j]=='0')
//         return i-strlen(T)+1;
//     else 
//     {
//        return 0 ;
//     }
    
// }
int main(){
    char T[]={"ababaaababaa"};
    int next[100];
    MaxAffixLen(T,next);
    int i=0;
    for(i=0;i<100;i++)
    {
        printf("%d\n",next[i]);
    }
    return 0;
}