#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int elem;
	struct Node *next;
} Node;

typedef struct Node *LinkList;

void Create(LinkList *L, int n)
{

	LinkList s, q;
	q = (*L);
	int e;
	printf("����Ԫ��Ϊ:");
	while (n--)
	{
		s = (LinkList)malloc(sizeof(Node));
		scanf("%d", &e);
		//		printf("%d",e);
		s->elem = e;
		s->next = q->next;
		q->next = s;
		q = q->next;
	}
	//	LinkList p;
	//	p = (*L)->next;
	//	while(p!=NULL)
	//	{
	//		printf("%d ",p->elem);
	//		p = p->next;
	//	}
}
void Traverse(LinkList L)
{
	LinkList p;
	p = L->next;
	int i;
	i = 9;
	while (p != NULL)
	{
		printf("%d ", p->elem);
		p = p->next;
	}
	printf("\n");
}

void Invert(LinkList *L, int m, int n)
{

	LinkList p;
	p = (*L)->next;
	int pos;
	for (pos = 1; pos < m - 1; pos++)
	{
		p = p->next;
	}
	//	printf("%d",p->elem);
	LinkList q, t, s;
	t = p->next;
	//	(p->next)->next = NULL;
	t = t->next;
	s = t->next;
	//	printf("s %d\n",s->elem);
	//	printf("t %d\n",t->elem);
	while (t != NULL)
	{
		q = p->next;
		p->next = t;
		t->next = q;
		//		printf("t %d\n",t->elem);
		t = s;
		if (t != NULL)
		{
			s = s->next;
		}
	}
	int i;
	p = (*L);
	for (i = 0; i < n; i++)
	{
		p = p->next;
		//		printf("%d ",p->elem);
	}
	p->next = NULL;
}
int main()
{
	LinkList head;
	head = (LinkList)malloc(sizeof(Node));
	head->next = NULL;
	int n;
	printf("n = ");
	scanf("%d", &n);
	Create(&head, n);
	Traverse(head);
	int m;
	printf("m = ");
	scanf("%d", &m);
	Invert(&head, m, n);
	Traverse(head);
}
