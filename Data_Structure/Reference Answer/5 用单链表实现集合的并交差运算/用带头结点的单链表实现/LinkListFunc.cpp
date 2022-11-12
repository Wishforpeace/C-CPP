 #include <stdio.h> 
 #include <stdlib.h> // exit()
 
 typedef int ElemType;
 typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE
 
 #define TRUE 1
 #define FALSE 0

 /**********************************************************/
 /*              ���Ա�ĵ�����洢�ṹ                    */
 /**********************************************************/
 typedef struct LNode
 {
	 ElemType data;
	 struct LNode *next;
 }LNode, *LinkList;        // �̲��ϵĶ���
 
 /*
 struct LNode
 {
	 ElemType data;
	 LNode *next;
 };
 typedef LNode *LinkList; // ��һ�ֶ���LinkList�ķ���
 */

 /**********************************************************/
 /*          ��ͷ���ĵ�����Ļ�������(12��)              */
 /**********************************************************/
 void InitList_L(LinkList &L)
 { // �������������һ���յ����Ա�L------------------------------------------------1
   //L = (LinkList)malloc(sizeof(LNode)); // ����ͷ���,��ʹLָ���ͷ���
	 L = new LNode;
	 if(!L) // �洢����ʧ��
		 exit(-1);
	 L->next = NULL; // ָ����Ϊ��
 }

 void DestroyList_L(LinkList &L)
 { // ��ʼ���������Ա�L�Ѵ��ڡ�����������������Ա�L���ͷŰ���ͷ������ڵ����н��Ĵ洢�ռ䣩------2
	 LinkList q;
	 while(L)
	 {
		 q = L->next;
		 free(L);
		 L = q;
	 }
 }

 void ClearList_L(LinkList L) 
 { // ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�------------------------------3
	 LinkList p,q;
	 p = L->next; // pָ���һ�����
	 while(p) // û����β
	 {
		 q = p->next;
		 free(p);
		 p = q;
	 }
	 L->next = NULL; // ͷ���ָ����Ϊ��
 }

 Boolean ListEmpty_L(LinkList L)
 { // ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE---------------4
	 if(L->next) // �ǿ�
		 return FALSE;
	 else
		 return TRUE;
 }

 int ListLength_L(LinkList L) // �㷨2.14
 { // ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ���--------------------------------5
	 LinkList p = L->next; // pָ���һ�����
	 int k = 0;
	 while(p) // û����β
	 {
		 k++;
		 p = p->next;
	 }
	 return k;
 }

 void GetElem_L(LinkList L,int i,ElemType &e) 
 { // LΪ��ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ,��ֵ����e-----------------------------6
	 int j; // jΪ������
	 LinkList p;
	 
	 if(i < 1)
	 {
		 printf("iС��1�����Ϸ���\n");
		 exit(-1);
	 }

	 p = L->next; // pָ���һ�����
	 j = 1;
	 while(p && j<i) // ˳ָ��������,ֱ��pָ���i��Ԫ�ػ�pΪ��
	 {
		 p = p->next;
		 j++;
	 }
	 if(!p) // ��i��Ԫ�ز�����
	 {
		 printf("��i��Ԫ�ز����ڣ�\n");
		 exit(-1);
	 }
	 e = p->data; // ȡ��i��Ԫ��
 }

 LNode* LocateElem_L(LinkList L,ElemType e)  // �㷨2.15
 {    // �� L ��ָ�������в��ҵ�һ��ֵ�� e ��ȵ�����Ԫ�أ������ڣ��򷵻�-----------------------7
      // ���������е�λ�ã���ָ�������Ԫ�����ڽ���ָ�룻���򷵻� NULL
      LinkList p = L->next;
      while ( p && p->data!=e )
		  p = p->next;
      return p;
 }

 void PriorElem_L(LinkList L,ElemType cur_e,ElemType &pre_e)
 { // ��ʼ����: ���Ա�L�Ѵ���--------------------------------------------------------------------8
   // �������: ��cur_e��L������Ԫ��,�Ҳ��ǵ�һ��,����pre_e��������ǰ��;�������ʧ��,pre_e�޶���
	 LinkList q, p = L->next; // pָ���һ�����
	 while(p && p->next) // p�ǿ�ָ��(��Ե�һ�����ǿյ�Ҫ��)��p��ָ����к��
	 {
		 q = p->next; // qΪp�ĺ��
		 if(q->data == cur_e)
		 {
			 pre_e = p->data;
			 exit(0);
		 }
		 p = q; // p�����
	 }
	 printf("����Ҫ���ҵ�ǰ��Ԫ�أ�\n");
 }

 void NextElem_L(LinkList L,ElemType cur_e,ElemType &next_e)
 { // ��ʼ���������Ա�L�Ѵ���------------------------------------------------------------------------------9
   // �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ��;�������ʧ�ܣ�next_e�޶���
	 LinkList p = L->next; // pָ���һ�����
	 while(p && p->next) // p�ǿ�ָ��(��Ե�һ�����ǿյ�Ҫ��)��p��ָ����к��
	 {
		 if(p->data == cur_e)
		 {
			 next_e = p->next->data;
			 exit(0);
		 }
		 p = p->next;
	 }
	 printf("����Ҫ���ҵĺ��Ԫ�أ�\n");
 }

 void ListInsert_L( LinkList L, LNode *p, LNode *s ) // �㷨2.16�޸ġ���������ô���룬ͷָ��L����ı䣬�ʲ���&����
 { // ָ�� p ָ�� L Ϊͷָ���������ĳ����㣬�� s �����뵽 p ���֮ǰ--------------------------------10-1
   // �̲��㷨2.16��ͷ��㣬��Ҫ���ǲ���λ���ڵ�һ�����֮ǰ�����
   // �����㷨��ͷ��㣬�����迼���������
	 LNode *q = L;

	 while (q->next != p )
		 q = q->next;   // ���� p ��ǰ����� q
	 q->next = s; 
	 s->next = p;           // �������� q ���֮����� s ���
 } // ListInsert_L

 void ListInsert_L_E(LinkList L,int i,ElemType e) // �㷨2.16����
 { // �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e��1<=i<=Listlength(L)+1----------------------------10-2
   // ���㷨�������Ϊ�㷨6 GetElem_L��һ���޸ģ������ҵĲ��ǵ�i�������ǵ�i-1�����
   // �Ҳ��ҵĶ������ͷ������ڣ�ͷ�������Ϊ0
	 LinkList p = L, q;       // pָ��Ҫ���ҵĵ�i������ǰ����㣬��ֵΪͷ���
	 int  j = 0;              // jΪ����������0��ʼ��p����������ͷ��㿪ʼ������

	 if(i < 1)
	 {
		 printf("iС��1������λ�ò��Ϸ���\n");
		 exit(-1);
	 }

	 while(p && j<i-1)       // ��ͷ��㿪ʼ������,ֱ��pָ���i-1��Ԫ�ػ�pΪ��
	 {
		 p = p->next;
		 j++;
	 }
	 if(!p) // p���ֻ�ܵ���������һ����㣬��ʱpΪ��β��Ŀ�ָ�룬j==Listlength(L)����i>Listlength(L)+1
	 {
		 printf("i>Listlength(L)+1������λ�ò��Ϸ���\n");
		 exit(-1);
	 }

	 q = new LNode; // �����½��
	 q->data = e; // ����L��
	 q->next = p->next;
	 p->next = q;
 }

 void ListDelete_L( LinkList L, LNode* p, ElemType &e ) // �㷨 2.17�޸�
 { // pָ��LΪͷָ���������ĳ����㣬��������ɾ���ý�㲢��e������Ԫ��---------------------------------11-1
   // �̲��㷨2.17��ͷ��㣬��Ҫ����ɾ��λ���ǵ�һ���������
   // �����㷨��ͷ��㣬�����迼���������
	 LNode *q = L;

	 while (q->next != p )
		 q = q->next;              // ���� p ��ǰ����� q
	 q->next = p->next;           // �޸� q ����ָ����
	 e = p->data;
	 delete p;                     // ���ر�ɾ��������Ԫ�أ����ͷŽ��ռ�
 }// ListDelete_L

 void ListDelete_L_E(LinkList L,int i,ElemType &e) // �㷨2.17����
 { // �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ��,����e������ֵ��1<=i<=Listlength(L)-----------------------11-2
   // ���㷨�������Ϊ�㷨6 GetElem_L��һ���޸ģ������ҵĲ��ǵ�i�������ǵ�i-1�����
   // �Ҳ��ҵĶ������ͷ������ڣ�ͷ�������Ϊ0
	 LinkList p = L, q;       // pָ��Ҫɾ���ĵ�i������ǰ����㣬��ֵΪͷ���
	 int  j = 0;              // jΪ����������0��ʼ��p����������ͷ��㿪ʼ������

	 if(i < 1)
	 {
		 printf("iС��1��ɾ��λ�ò��Ϸ���\n");
		 exit(-1);
	 }

	 while(p && j<i-1)       // ��ͷ��㿪ʼ������,ֱ��pָ���i-1��Ԫ�ػ�pΪ��
	 {
		 p = p->next;
		 j++;
	 }
	 if(!p->next || !p)      // p���ֻ�ܵ�����ĵ����ڶ�����㣬��ʱp�ѵ���β��Ϊ��β�Ŀ�ָ��
	 {
		 printf("i>Listlength(L)��ɾ��λ�ò��Ϸ���\n");
		 exit(-1);
	 }

	 q = p->next; // ɾ�����ͷŽ��
	 p->next = q->next;
	 e = q->data;
	 free(q);
 }

 void ListTraverse_L(LinkList L)
 { // ��ʼ���������Ա�L�Ѵ���---------------------------------------12
   // �������:�������L�е�ÿ������
	 LinkList p = L->next;
	 while(p)
	 {
		 printf("%d ",(p->data));
		 p = p->next;
	 }
 }
