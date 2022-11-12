#include <stdio.h>
#define true 1
#define false 0
#define maxsize 100

typedef int status;

status match(char exp[], int n)
{   //判别表达式中开闭括号是否配对出现，假设表达式已
    //存储在数组exp[]中，并且表达式中的圆、方、花括号可以任意次序嵌套，n为数组长度

    if (n < 0)
    {
        printf("匹配失败！");
        return false;
    }

    char stack[maxsize];
    int top = -1;
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            stack[++top] = exp[i];
        else if (exp[i] == ')')
        {
            if (stack[top] == '(')
                top--;
            else
            {
                printf("匹配失败！");
                return false;
            }
        }
        else if (exp[i] == '}')
        {
            if (stack[top] == '{')
                top--;
            else
            {
                printf("匹配失败！");
                return false;
            }
        }
        else if (exp[i] == ']')
        {
            if (stack[top] == '[')
                top--;
            else
            {
                printf("匹配失败！");
                return false;
            }
        }
    }
    if (top == -1)
    {
        printf("匹配成功！");
        return true;
    }

    else
    {
        printf("匹配失败！");
        return false;
    }
}

void main()
{
    char exp[maxsize];
    int n, i, x;
    printf("请输入表达式的长度n：\n");
    scanf("%d", &n);
    getchar(); //用于接收回车键
    if (n > 0)
    {
        printf("请逐个输入表达式中的字符：\n");
        for (i = 0; i < n; i++)
        {
            x = getchar(); //不敲回车键直接输入完毕
            exp[i] = x;
            printf("exp[%d]=%c\n", i, exp[i]);
        }
    }

    match(exp, n);
}
