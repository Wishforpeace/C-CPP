#include <iostream>
#include "11_binaryTreeNode.h"
#include "11_binaryTreeTraversals.h"
#include "11_infix.h"
#include "../../codes/myExceptions.h"
#include "../../codes/arrayQueue.h"

using namespace std;

template <class T>
void CreateTree(binaryTreeNode<T> *(*t))
{
    char val;
    cin >> val;
    if (val == '#')
    {
        *t = NULL;
    }
    else
    {
        // binaryTreeNode<char> *tmp;
        *t = new binaryTreeNode<char>(val);
        if (*t == NULL)
        {
            cout << "failed" << endl;
            exit(-1);
        }
        else
        {
            // cout << t->element;
            CreateTree(&((*t)->leftChild));
            CreateTree(&((*t)->rightChild));
        }
    }
}

// int main()
// {
//     binaryTreeNode<char> *root;
//     // root = new binaryTreeNode<char>('a');
//     // string Expression;
//     // cin >> Expression;
//     CreateTree(&root);
//     cout << "中序遍历:";
//     // cout << (*root).element << endl;
//     inOrder(root);
//     cout << endl;
//     cout << "后序遍历:";
//     postOrder(root);
//     cout << endl;
//     cout << "层次遍历:";
//     levelOrder(root);
// }