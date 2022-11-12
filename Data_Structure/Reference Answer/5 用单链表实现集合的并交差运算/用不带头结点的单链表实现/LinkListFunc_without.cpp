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
 /*          ����ͷ���ĵ�����Ļ�������(12��)              */
 /**********************************************************/
 void InitList_L(LinkList &L)   // ͷָ��L�ᱻ�޸ģ���Ӧ����&���ţ���ͬ
 { // �������������һ���յ����Ա�L------------------------------------------------1
   	 L = NULL; // ָ��Ϊ��
 }

 void DestroyList_L(LinkList &L)
 { // ��ʼ���������Ա�L�Ѵ��ڡ�����������������Ա�L���ͷ����н��Ĵ洢�ռ䣩------2
	 LinkList q;
	 while(L)     // ѭ��������LΪNULL
	 {
		 q = L->next;
		 free(L);
		 L = q;
	 }
 }

 void ClearList_L(LinkList &L) 
 { // ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�------------------------------3
	 LinkList q;
	 while(L)     // ѭ��������LΪNULL
	 {
		 q = L->next;
		 free(L);
		 L = q;
	 }
 }

 Boolean ListEmpty_L(LinkList L)
 { // ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE---------------4
	 if(L) // �ǿ�
		 return FALSE;
	 else
		 return TRUE;
 }

 int ListLength_L(LinkList L) // �㷨2.14
 { // ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ���--------------------------------5
	 LinkList p = L; // pָ���һ�����
	 int k = 0;
	 while(p) // û����β
	 {
		 k++;
		 p = p->next;
	 }
	 return k;
 }

 void GetElem_L(LinkList L,int i,ElemType &e) 
 { // LΪ�������ָ�롣����i��Ԫ�ش���ʱ,��ֵ����e-----------------------------6
	 int j; // jΪ������
	 LinkList p;
	 
	 if( i<1 || i>ListLength_L(L) )
	 {
		 printf("iֵ���Ϸ�������i��Ԫ�ز����ڣ�\n");
		 exit(-1);
	 }

	 p = L; // pָ���һ�����
	 j = 1;
	 while( j<i ) // ˳��ָ��������,ֱ��pָ���i��Ԫ��
	 {
		 p = p->next;
		 j++;
	 }
	 e = p->data; // ȡ��i��Ԫ��
 }

 LNode* LocateElem_L(LinkList L,ElemType e)  // �㷨2.15
 {    // �� L ��ָ�������в��ҵ�һ��ֵ�� e ��ȵ�����Ԫ�أ������ڣ��򷵻�-----------------------7
      // ���������е�λ�ã���ָ�������Ԫ�����ڽ���ָ�룻���򷵻� NULL
      LinkList p = L;
      while ( p && p->data!=e )
		  p = p->next;
      return p;
 }

 void PriorElem_L(LinkList L,ElemType cur_e,ElemType &pre_e)
 { // ��ʼ����: ���Ա�L�Ѵ���--------------------------------------------------------------------8
   // �������: ��cur_e��L������Ԫ��,�Ҳ��ǵ�һ��,����pre_e��������ǰ��;�������ʧ��,pre_e�޶���
	 LinkList q, p = L; // pָ���һ�����
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
	 LNode *p = L; // pָ���һ�����
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

 void ListInsert_L( LinkList &L, LNode *p, LNode *s ) // �㷨2.16
 { // ָ�� p ָ������ L ��ĳ����㣬�� s �����뵽 p ���֮ǰ--------------------------------10-1
     LNode *q;

	 if(p == L)   // ����λ���ڵ�һ�����֮ǰ�����
	 {
		 s->next = L;
		 L = s;
	 }
	 else{
		 q = L;
		 while (q->next != p )
			 q = q->next;   // ���� p ��ǰ����� q
		 q->next = s; 
		 s->next = p;           // �������� q ���֮����� s ���
	 }
 }

 void ListInsert_L_E(LinkList &L,int i,ElemType e) // �㷨2.16���䣬������ListLength_L(L)����
 { // �ڲ���ͷ���ĵ�����L�е�i��λ��֮ǰ����Ԫ��e��1<=i<=Listlength(L)+1----------------------------10-2
   // ���㷨�������Ϊ�㷨6 GetElem_L��һ���޸ģ������ҵĲ��ǵ�i�������ǵ�i-1�����
	 LNode *p, *q;       
	 int j;            

	 if(i<1 || i>ListLength_L(L)+1)
	 {
		 printf("iֵ���Ϸ���������λ�ò��Ϸ���\n");
		 exit(-1);
	 }
	 
	 if(i == 1)// ���뵽��һ�����֮ǰ
	 {
		 q = new LNode; // �����½��
		 q->data = e;
		 q->next = L;   // ����L��
		 L = q;
	 }
	 else{
		 p = L;              // pָ��Ҫ���ҵĵ�i������ǰ����㼴��i-1����㣬��ֵΪL
		 j = 1;              // jΪ����������1��ʼ��p����
		 while(j<i-1)       // �ӵ�һ����㿪ʼ������,ֱ��pָ���i-1��Ԫ��
		 {
			 p = p->next;
			 j++;
		 }
		 q = new LNode; // �����½��
		 q->data = e; // ����L��
		 q->next = p->next;
		 p->next = q;
	 }
 }

 void ListDelete_L( LinkList &L, LNode* p, ElemType &e ) // �㷨 2.17
 { // pָ��L������ĳ����㣬��������ɾ���ý�㲢��e������Ԫ��---------------------------------11-1
	 LNode *q;

	 if(p == L) // ɾ������ĵ�һ����㣬�޸ı�ͷָ��
		 L = p->next; 
	 else{
		 q = L;
		 while (q->next != p )
			 q = q->next;              // ���� p ��ǰ����� q
		 q->next = p->next;           // �޸� q ����ָ����
	 }
	 e = p->data;
	 delete p;                     // ���ر�ɾ��������Ԫ�أ����ͷŽ��ռ�
 }

 void ListDelete_L_E(LinkList &L,int i,ElemType &e) // �㷨2.17���䣬������ListLength_L(L)����
 { // �ڲ���ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ��,����e������ֵ��1<=i<=Listlength(L)-----------------------11-2
   // ���㷨�������Ϊ�㷨6 GetElem_L��һ���޸ģ������ҵĲ��ǵ�i�������ǵ�i-1�����
	 LinkList p, q;       // qָ��ɾ���ĵ�i�����
	 int j;              

	 if(i<1 || i>ListLength_L(L))
	 {
		 printf("iֵ���Ϸ�����ɾ��λ�ò��Ϸ���\n");
		 exit(-1);
	 }

	 if(i == 1)// ɾ�����ǵ�һ�����
	 {
		 q = L;
		 L = q->next;
	 }
	 else{
		 p = L;              // pָ��Ҫ���ҵĵ�i������ǰ����㣬��ֵΪL
		 j = 1;              // jΪ����������1��ʼ��p����
		 while(j<i-1)       // �ӵ�һ����㿪ʼ������,ֱ��pָ���i-1�����
		 {
			 p = p->next;
			 j++;
		 }
		 q = p->next; 
		 p->next = q->next;
	 }
	 e = q->data;
	 free(q);
 }

 void ListTraverse_L(LinkList L)
 { // ��ʼ���������Ա�L�Ѵ���---------------------------------------12
   // �������:�������L�е�ÿ������
	 LinkList p = L;
	 while(p)
	 {
		 printf("%d ",(p->data));
		 p = p->next;
	 }
 }
