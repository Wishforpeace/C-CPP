#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef struct Node
{
    char data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;

void Init(LinkList *L)
{
    *L = (Node *)malloc(sizeof(Node));
    if ((*L) == NULL)
    {
        printf("Failed to init\n");
    }
    (*L)->next = NULL;
}

void Alphabet(LinkList *L)
{
    LinkList p, q;
    p = *L;
    int l = 26;
    int i;
    for (i = 0; i < 26; i++)
    {
        q = (Node *)malloc(sizeof(Node));
        q->data = 'a' + i;
        q->next = p->next;
        p->next = q;
        p = q;
        p->next = NULL;
    }
}

void Display(LinkList L)
{
    int i;
    LinkList p;
    p = L->next;
    while (p != NULL)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

void Insert(LinkList *L, char X, char Y)
{
    LinkList p, q, s;
    p = *L;
    p = p->next;
    q = p->next;
    while (q->data != Y && q != NULL)
    {
        p = p->next;
        q = p->next;
    }
    s = (LinkList)malloc(sizeof(Node));
    s->data = X;
    s->next = q;
    p->next = s;
}

void Delete(LinkList *L, char X)
{
    LinkList p, q;
    p = *L;
    q = p->next;
    while (q != NULL)
    {
        if (q->data == X)
        {
            p->next = q->next;
            free(q);
        }
        p = p->next;
        q = p->next;
    }
}
int main()
{
    LinkList L;
    Init(&L);
    Alphabet(&L);
    Display(L);
    Insert(&L, 'c', 'b');
    Insert(&L, 'a', 'z');
    Display(L);
    Delete(&L, 'a');
    Display(L);
}