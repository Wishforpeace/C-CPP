 #include <stdio.h> 
 #include <stdlib.h> // exit()
 
 typedef int ElemType;
 typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE
 
 #define TRUE 1
 #define FALSE 0

 /**********************************************************/
 /*              线性表的单链表存储结构                    */
 /**********************************************************/
 typedef struct LNode
 {
	 ElemType data;
	 struct LNode *next;
 }LNode, *LinkList;        // 教材上的定义
 
 /*
 struct LNode
 {
	 ElemType data;
	 LNode *next;
 };
 typedef LNode *LinkList; // 另一种定义LinkList的方法
 */

 /**********************************************************/
 /*          不带头结点的单链表的基本操作(12个)              */
 /**********************************************************/
 void InitList_L(LinkList &L)   // 头指针L会被修改，故应加上&符号，下同
 { // 操作结果：构造一个空的线性表L------------------------------------------------1
   	 L = NULL; // 指针为空
 }

 void DestroyList_L(LinkList &L)
 { // 初始条件：线性表L已存在。操作结果：销毁线性表L（释放所有结点的存储空间）------2
	 LinkList q;
	 while(L)     // 循环结束后，L为NULL
	 {
		 q = L->next;
		 free(L);
		 L = q;
	 }
 }

 void ClearList_L(LinkList &L) 
 { // 初始条件：线性表L已存在。操作结果：将L重置为空表------------------------------3
	 LinkList q;
	 while(L)     // 循环结束后，L为NULL
	 {
		 q = L->next;
		 free(L);
		 L = q;
	 }
 }

 Boolean ListEmpty_L(LinkList L)
 { // 初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE---------------4
	 if(L) // 非空
		 return FALSE;
	 else
		 return TRUE;
 }

 int ListLength_L(LinkList L) // 算法2.14
 { // 初始条件：线性表L已存在。操作结果：返回L中数据元素个数--------------------------------5
	 LinkList p = L; // p指向第一个结点
	 int k = 0;
	 while(p) // 没到表尾
	 {
		 k++;
		 p = p->next;
	 }
	 return k;
 }

 void GetElem_L(LinkList L,int i,ElemType &e) 
 { // L为单链表的指针。当第i个元素存在时,其值赋给e-----------------------------6
	 int j; // j为计数器
	 LinkList p;
	 
	 if( i<1 || i>ListLength_L(L) )
	 {
		 printf("i值不合法，即第i个元素不存在！\n");
		 exit(-1);
	 }

	 p = L; // p指向第一个结点
	 j = 1;
	 while( j<i ) // 顺着指针向后查找,直到p指向第i个元素
	 {
		 p = p->next;
		 j++;
	 }
	 e = p->data; // 取第i个元素
 }

 LNode* LocateElem_L(LinkList L,ElemType e)  // 算法2.15
 {    // 在 L 所指的链表中查找第一个值和 e 相等的数据元素，若存在，则返回-----------------------7
      // 它在链表中的位置，即指向该数据元素所在结点的指针；否则返回 NULL
      LinkList p = L;
      while ( p && p->data!=e )
		  p = p->next;
      return p;
 }

 void PriorElem_L(LinkList L,ElemType cur_e,ElemType &pre_e)
 { // 初始条件: 线性表L已存在--------------------------------------------------------------------8
   // 操作结果: 若cur_e是L的数据元素,且不是第一个,则用pre_e返回它的前驱;否则操作失败,pre_e无定义
	 LinkList q, p = L; // p指向第一个结点
	 while(p && p->next) // p非空指针(针对第一个结点非空的要求)且p所指结点有后继
	 {
		 q = p->next; // q为p的后继
		 if(q->data == cur_e)
		 {
			 pre_e = p->data;
			 exit(0);
		 }
		 p = q; // p向后移
	 }
	 printf("无所要查找的前驱元素！\n");
 }

 void NextElem_L(LinkList L,ElemType cur_e,ElemType &next_e)
 { // 初始条件：线性表L已存在------------------------------------------------------------------------------9
   // 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继;否则操作失败，next_e无定义
	 LNode *p = L; // p指向第一个结点
	 while(p && p->next) // p非空指针(针对第一个结点非空的要求)且p所指结点有后继
	 {
		 if(p->data == cur_e)
		 {
			 next_e = p->next->data;
			 exit(0);
		 }
		 p = p->next;
	 }
	 printf("无所要查找的后继元素！\n");
 }

 void ListInsert_L( LinkList &L, LNode *p, LNode *s ) // 算法2.16
 { // 指针 p 指向链表 L 中某个结点，将 s 结点插入到 p 结点之前--------------------------------10-1
     LNode *q;

	 if(p == L)   // 插入位置在第一个结点之前的情况
	 {
		 s->next = L;
		 L = s;
	 }
	 else{
		 q = L;
		 while (q->next != p )
			 q = q->next;   // 查找 p 的前驱结点 q
		 q->next = s; 
		 s->next = p;           // 在链表中 q 结点之后插入 s 结点
	 }
 }

 void ListInsert_L_E(LinkList &L,int i,ElemType e) // 算法2.16扩充，调用了ListLength_L(L)函数
 { // 在不带头结点的单链表L中第i个位置之前插入元素e，1<=i<=Listlength(L)+1----------------------------10-2
   // 本算法可以理解为算法6 GetElem_L的一种修改，即查找的不是第i个结点而是第i-1个结点
	 LNode *p, *q;       
	 int j;            

	 if(i<1 || i>ListLength_L(L)+1)
	 {
		 printf("i值不合法，即插入位置不合法！\n");
		 exit(-1);
	 }
	 
	 if(i == 1)// 插入到第一个结点之前
	 {
		 q = new LNode; // 生成新结点
		 q->data = e;
		 q->next = L;   // 插入L中
		 L = q;
	 }
	 else{
		 p = L;              // p指向要查找的第i个结点的前驱结点即第i-1个结点，初值为L
		 j = 1;              // j为计数器，从1开始对p计数
		 while(j<i-1)       // 从第一个结点开始向后查找,直到p指向第i-1个元素
		 {
			 p = p->next;
			 j++;
		 }
		 q = new LNode; // 生成新结点
		 q->data = e; // 插入L中
		 q->next = p->next;
		 p->next = q;
	 }
 }

 void ListDelete_L( LinkList &L, LNode* p, ElemType &e ) // 算法 2.17
 { // p指向L链表中某个结点，从链表中删除该结点并由e返回其元素---------------------------------11-1
	 LNode *q;

	 if(p == L) // 删除链表的第一个结点，修改表头指针
		 L = p->next; 
	 else{
		 q = L;
		 while (q->next != p )
			 q = q->next;              // 查找 p 的前驱结点 q
		 q->next = p->next;           // 修改 q 结点的指针域
	 }
	 e = p->data;
	 delete p;                     // 返回被删结点的数据元素，并释放结点空间
 }

 void ListDelete_L_E(LinkList &L,int i,ElemType &e) // 算法2.17扩充，调用了ListLength_L(L)函数
 { // 在不带头结点的单链线性表L中，删除第i个元素,并由e返回其值，1<=i<=Listlength(L)-----------------------11-2
   // 本算法可以理解为算法6 GetElem_L的一种修改，即查找的不是第i个结点而是第i-1个结点
	 LinkList p, q;       // q指向被删除的第i个结点
	 int j;              

	 if(i<1 || i>ListLength_L(L))
	 {
		 printf("i值不合法，即删除位置不合法！\n");
		 exit(-1);
	 }

	 if(i == 1)// 删除的是第一个结点
	 {
		 q = L;
		 L = q->next;
	 }
	 else{
		 p = L;              // p指向要查找的第i个结点的前驱结点，初值为L
		 j = 1;              // j为计数器，从1开始对p计数
		 while(j<i-1)       // 从第一个结点开始向后查找,直到p指向第i-1个结点
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
 { // 初始条件：线性表L已存在---------------------------------------12
   // 操作结果:依次输出L中的每个数据
	 LinkList p = L;
	 while(p)
	 {
		 printf("%d ",(p->data));
		 p = p->next;
	 }
 }
