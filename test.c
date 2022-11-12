#include <stdio.h>
void test(int *a)
{
    a[1] = 0;
}
int main()
{
    int a[] = {0, 2, 3, 4, 5};
    test(a);
    int i;
    int len = sizeof(a) / sizeof(a[0]);
    for (i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
}