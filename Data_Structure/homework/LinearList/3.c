#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int main()
{
    int i;
    i = 0;
    Node *head, *p, *s;
    head = (Node *)malloc(sizeof(Node));
    if (head == NULL)
    {
        printf("Init Failed");
    }
    head->next = NULL;
    p = head;
    printf("请输入值,输入-1停止:\n");
    do
    {
        int n;
        scanf("%d", &n);
        if (n == -1)
        {
            break;
        }
        s = (Node *)malloc(sizeof(Node));
        s->data = n;
        s->next = p->next;
        p->next = s;
        p = p->next;
        p->next = NULL;
    } while (1);

    p = head->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
        i++;
    }
    printf("length:%d\n", i);
}