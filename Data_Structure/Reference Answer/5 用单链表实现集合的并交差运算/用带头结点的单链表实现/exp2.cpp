//利用带头结点的单链表实现两个整数集合的并、交、差的运算。。
#include "LinkListFunc.cpp" // 采用线性表的链式存储结构

void InputElement(LinkList &L)   //输入集合元素到线性表L中
{
	int i, num, e;
	
	printf("num  = ");
	scanf("%d", &num);
	printf("elem = ");
	for(i = 1; i <= num; i++)
	{
		scanf("%d", &e);
		ListInsert_L_E(L, i, e); 
	}
}

//求并集
void Union(LinkList La, LinkList Lb, LinkList &Lc)
{
	// 算法2.1的修改：将线性表La和Lb合并成新的线性表Lc，算法执行结束后，线性表La和Lb不变
	int i, j = 0;
	ElemType e;

	for (i = 1; i <= ListLength_L(La); i++)
	{
		GetElem_L(La, i, e);  //取集合A中的元素
		j++;
		ListInsert_L_E(Lc, j, e); //插入到集合C中
	}
	for (i = 1; i <= ListLength_L(Lb); i++)
	{
		GetElem_L(Lb, i, e);  //取集合B中的元素
		if (LocateElem_L(Lc, e))  //在集合C中存在该元素
			continue;
		j++;
		ListInsert_L_E(Lc, j, e); //插入到集合C中
	}
} 

//求交集
void Inter(LinkList La, LinkList Lb, LinkList &Lc)
{
	int i, j = 0;
	ElemType e;

	for (i = 1; i <= ListLength_L(La); i++)
	{
		GetElem_L(La, i, e);  //取集合A中的元素
		if (LocateElem_L(Lb, e))  //在集合B中存在该元素
		{
			j++;
			ListInsert_L_E(Lc, j, e); //插入到集合C中
		}
	}
}

//求差集
void Sub(LinkList La, LinkList Lb, LinkList &Lc)
{
	int i, j = 0;
	ElemType e;

	for (i = 1; i <= ListLength_L(La); i++)
	{
		GetElem_L(La, i, e);  //取集合A中的元素
		if (!LocateElem_L(Lb, e))  //在集合B中不存在该元素
		{
			j++;
			ListInsert_L_E(Lc, j, e); //插入到集合C中
		}
	}
}

void main()
{
	LinkList La, Lb, Lc, Ld, Le, Lf;

	printf("************* Input A ***************\n");
	InitList_L(La);
	InputElement(La);

	printf("************* Input B ***************\n");
	InitList_L(Lb);
	InputElement(Lb);

	InitList_L(Lc); // 集合C（A并B）
	Union(La,Lb,Lc);

	InitList_L(Ld); // 集合D（A交B）
	Inter(La,Lb,Ld);

	InitList_L(Le); // 集合E（A-B）
	Sub(La,Lb,Le);

	InitList_L(Lf); // 集合F（B-A）
	Sub(Lb,La,Lf);
	
	printf("\n************* Result ****************\n");

	printf("A = {"); // 输出集合A
	ListTraverse_L(La);
	printf("}\n"); 

	printf("B = {"); // 输出集合B
	ListTraverse_L(Lb);
	printf("}\n"); 

	printf("A U B = {"); // 输出集合C（A并B）
	ListTraverse_L(Lc);
	printf("}\n"); 
	
	printf("A * B = {"); // 输出集合D（A交B）
	ListTraverse_L(Ld);
	printf("}\n"); 
	
	printf("A - B = {"); // 输出集合E（A-B）
	ListTraverse_L(Le);
	printf("}\n"); 

	printf("B - A = {"); // 输出集合F（B-A）
	ListTraverse_L(Lf);
	printf("}\n"); 

	printf("*************************************\n");

	/*
	printf("\n****** 验证ListDelete_L_E函数 *******\n");

	int i, j = ListLength_L(Lc);
	ElemType e;
	for(i=j; i>=1; i--)
	{
		 ListDelete_L_E(Lc, i, e); 
		 printf("删除元素 %d \n", e);
	}

	printf("Lc = {"); // 输出集合LC
	ListTraverse_L(Lc);
	printf("}\n"); 

	printf("*************************************\n");
	*/

	DestroyList_L(La);
	DestroyList_L(Lb);
	DestroyList_L(Lc);
	DestroyList_L(Ld);
	DestroyList_L(Le);
	DestroyList_L(Lf);
}



