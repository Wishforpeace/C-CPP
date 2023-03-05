#include<iostream>
#include"SqQueue.cpp" 
using namespace std;



void CreateBiTree(BiTree &T){
	char ch;
	cin >> ch;
	if(ch == '#')
		T = NULL;
	else{
		T = new BiTNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

void visit(BiTree T){
	cout << T->data;
}

void Inorder(BiTree T, void (*visit)(BiTree)){
	if(T){
		Inorder(T->lchild, visit);
		visit(T);
		Inorder(T->rchild, visit);
	}
}

void Afterorder(BiTree T, void (*visit)(BiTree)){
	if(T){
		Afterorder(T->lchild, visit);
		Afterorder(T->rchild, visit);
		visit(T);
	}
}

void Layerorder(BiTree T, void (*visit)(BiTree)){
	SqQueue Q;
	BiTree p;
	InitQueue(Q, 100);
	EnQueue(Q, T);
	while(!QueueEmpty(Q)){
		DeQueue(Q, p);
		visit(p);
		if(p->lchild)
			EnQueue(Q, p->lchild);
		if(p->rchild)
			EnQueue(Q, p->rchild);
	}
}

int main(){
	BiTree T;
	CreateBiTree(T);
	cout << "中序遍历";
	Inorder(T, visit);
	cout << endl;
	cout << "后序遍历";
	Afterorder(T, visit);
	cout << endl;
	cout << "层次遍历";
	Layerorder(T, visit); 
	return 0;
}




