#include <iostream>

#include "binaryTreeNode.h"

using namespace std;

template <class T>

void postfix(binaryTreeNode<T> *t)
{
    if (t != NULL)
    {
        postfix(t->leftChild);
        postfix(t->rightChild);
        cout << t->element;
    }
}

int main(void)
{
    binaryTreeNode<char> x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12;
    x1.element = '*';
    x2.element = '/';
    x3.element = '-';
    x1.leftChild = &x2;
    x1.rightChild = &x3;
    x4.element = '+';
    x5.element = '*';
    x2.leftChild = &x4;
    x2.rightChild = &x5;
    x6.element = 'f';
    x3.rightChild = &x6;
    x3.leftChild = 0;
    x7.element = 'a';
    x8.element = 'b';
    x4.leftChild = &x7;
    x4.rightChild = &x8;
    x9.element = '-';
    x10.element = 'e';
    x5.leftChild = &x9;
    x5.rightChild = &x10;
    x11.element = 'c';
    x12.element = 'd';
    x9.leftChild = &x11;
    x9.rightChild = &x12;
    x7.leftChild = x7.rightChild = x11.rightChild = x11.leftChild = x12.rightChild = x12.leftChild = x10.leftChild = x10.rightChild = x6.rightChild = x6.leftChild = 0;
    postfix(&x1);
    cout << endl;
}