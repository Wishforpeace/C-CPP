//���ô�ͷ���ĵ�����ʵ�������������ϵĲ�������������㡣��
#include "LinkListFunc.cpp" // �������Ա����ʽ�洢�ṹ

void InputElement(LinkList &L)   //���뼯��Ԫ�ص����Ա�L��
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

//�󲢼�
void Union(LinkList La, LinkList Lb, LinkList &Lc)
{
	// �㷨2.1���޸ģ������Ա�La��Lb�ϲ����µ����Ա�Lc���㷨ִ�н��������Ա�La��Lb����
	int i, j = 0;
	ElemType e;

	for (i = 1; i <= ListLength_L(La); i++)
	{
		GetElem_L(La, i, e);  //ȡ����A�е�Ԫ��
		j++;
		ListInsert_L_E(Lc, j, e); //���뵽����C��
	}
	for (i = 1; i <= ListLength_L(Lb); i++)
	{
		GetElem_L(Lb, i, e);  //ȡ����B�е�Ԫ��
		if (LocateElem_L(Lc, e))  //�ڼ���C�д��ڸ�Ԫ��
			continue;
		j++;
		ListInsert_L_E(Lc, j, e); //���뵽����C��
	}
} 

//�󽻼�
void Inter(LinkList La, LinkList Lb, LinkList &Lc)
{
	int i, j = 0;
	ElemType e;

	for (i = 1; i <= ListLength_L(La); i++)
	{
		GetElem_L(La, i, e);  //ȡ����A�е�Ԫ��
		if (LocateElem_L(Lb, e))  //�ڼ���B�д��ڸ�Ԫ��
		{
			j++;
			ListInsert_L_E(Lc, j, e); //���뵽����C��
		}
	}
}

//��
void Sub(LinkList La, LinkList Lb, LinkList &Lc)
{
	int i, j = 0;
	ElemType e;

	for (i = 1; i <= ListLength_L(La); i++)
	{
		GetElem_L(La, i, e);  //ȡ����A�е�Ԫ��
		if (!LocateElem_L(Lb, e))  //�ڼ���B�в����ڸ�Ԫ��
		{
			j++;
			ListInsert_L_E(Lc, j, e); //���뵽����C��
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

	InitList_L(Lc); // ����C��A��B��
	Union(La,Lb,Lc);

	InitList_L(Ld); // ����D��A��B��
	Inter(La,Lb,Ld);

	InitList_L(Le); // ����E��A-B��
	Sub(La,Lb,Le);

	InitList_L(Lf); // ����F��B-A��
	Sub(Lb,La,Lf);
	
	printf("\n************* Result ****************\n");

	printf("A = {"); // �������A
	ListTraverse_L(La);
	printf("}\n"); 

	printf("B = {"); // �������B
	ListTraverse_L(Lb);
	printf("}\n"); 

	printf("A U B = {"); // �������C��A��B��
	ListTraverse_L(Lc);
	printf("}\n"); 
	
	printf("A * B = {"); // �������D��A��B��
	ListTraverse_L(Ld);
	printf("}\n"); 
	
	printf("A - B = {"); // �������E��A-B��
	ListTraverse_L(Le);
	printf("}\n"); 

	printf("B - A = {"); // �������F��B-A��
	ListTraverse_L(Lf);
	printf("}\n"); 

	printf("*************************************\n");

	/*
	printf("\n****** ��֤ListDelete_L_E���� *******\n");

	int i, j = ListLength_L(Lc);
	ElemType e;
	for(i=j; i>=1; i--)
	{
		 ListDelete_L_E(Lc, i, e); 
		 printf("ɾ��Ԫ�� %d \n", e);
	}

	printf("Lc = {"); // �������LC
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



