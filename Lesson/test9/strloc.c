#include<stdio.h>
#include<string.h>
int strloc(char S[],char T[]){
    int i;
    int j;
    int place;
    int length1;
    length1 = strlen(S);
    printf("lenght1:%d\n",length1);
    int length2;
    length2 = strlen(T);
    printf("length2:%d\n",length2);
    for(i=0;i<length1-length2;i++){
        int j =0;
       
        while (S[j+i]==T[j])
        {    
            printf("%c %c\n",S[j+i],T[j]);
            j ++;
            printf("j:%d\n",j);
        }
        printf("j:%d\n",j);
        if (j != length2){
            continue;
        }else if (j==length2)
        {
            place=j;
            printf("place:%d\n",place);
            break;
        }
        
        
    }
    return place;
}
int main()
{
    char str[]={"ababcaababbabccbab"};
    char T[] ={"ababbabc"};
    int underline;
    underline= strloc(str,T);
    printf("%d",underline);
}