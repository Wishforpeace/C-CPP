#include<stdio.h>
int main(){
    int k=0;
    char c='A';
    do
    {
        switch (c++)
        {
        case 'A':
            k++;
            break;
        case'B':
            k--;
        case'C':
            k+=2;
            break;
        case'D':
            k%2;
            continue;
        case'E':
             k=k*2;
            break;

        default:
        k=(c?1:0);
            
        }
        k++;
        printf("%ck=%d\n",c-1,k);
    } while (c<'F');
    return 0;
}