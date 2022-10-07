#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char s1[]="abcd1234\0gja8193691";
    char s2[50];
    cout<<s1<<endl;
    int len = strlen(s1);
    int j;
    for(j=0;j<len;j++)
    {
        s2[j] = s1[j];
    }
    s2[j] = '\0';
    s2[j+1]='123';
    cout<<s2<<endl;
}