#include <iostream>
#include "substring.c"
using namespace std;

int main()
{
    char str1[100], str2[100], *sub;
    printf("请输入字符串1：");
    gets(str1);
    printf("请输入字符串2：");
    gets(str2);

    sub = maxsamesubstring(str1, str2);
    printf("\n最长公共子串长度=%lu \n", strlen(sub));
    puts(sub);
}
