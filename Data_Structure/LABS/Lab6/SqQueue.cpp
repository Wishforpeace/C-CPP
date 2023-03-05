#include<iostream>
using namespace std;
const int QUEUEINCREMENT = 10;

typedef char TElemType;

typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef BiTree QElemType;

typedef struct{
	QElemType *elem;
	int front;
	int rear;
	int queuesize;
	int incrementsize;
}SqQueue;

void InitQueue(SqQueue &Q, int size){
	Q.elem = new QElemType[size];
	Q.queuesize = size;
	Q.incrementsize = QUEUEINCREMENT;
	Q.front = Q.rear = 0;
}

bool DeQueue(SqQueue &Q, QElemType &e){
	if(Q.front == Q.rear)
		return false;
	e = Q.elem[Q.front];
	Q.front = (Q.front + 1) % Q.queuesize;
	return true;
}

void incrementsQueuesize(SqQueue &Q){
	QElemType* a;
	a = new QElemType[Q.queuesize + Q.incrementsize];
	for(int k = 0; k < Q.queuesize - 1; k++)
		a[k] = Q.elem[(Q.front + k) % Q.queuesize];
	delete [] Q.elem;
	Q.elem = a;
	Q.front = 0;
	Q.rear = Q.queuesize - 1;
	Q.queuesize += Q.incrementsize;
}

void EnQueue(SqQueue &Q, QElemType e){
	if((Q.rear + 1) % Q.queuesize == Q.front)
		incrementsQueuesize(Q);
	Q.elem[Q.rear] = e;
	Q.rear = (Q.rear + 1) % Q.queuesize;
}

void GetHead(SqQueue Q, QElemType &e){
	if(Q.front == Q.rear)
		exit(-1);
	e = Q.elem[Q.front];
}

bool QueueEmpty(SqQueue Q){
	if(Q.front == Q.rear)
		return true;
	else
		return false;
}
