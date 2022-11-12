#include <iostream>
using namespace std;
#define MaxSize 100
int tag; //以tag == 0和tag == 1来区别在队头指针(front)和队尾指针(rear)相等时，队列状态为"空"还是"满"
typedef struct
{
    int *base;
    int front;
    int rear;
} Seq;

int Init(Seq &L)
{ //初始化
    L.base = new int[MaxSize];
    L.front = L.rear = 0;
    tag = 0;
    return 1;
}

int Enter(Seq &L, int m)
{ //入队列
    if (L.rear % MaxSize == L.front && tag == 1)
    {
        cout << "队列已满！";
        return 0;
    }
    L.base[L.rear] = m;
    L.rear = (L.rear + 1) % MaxSize;
    if (L.rear == L.front)
        tag = 1;
    return 1;
}

int Out(Seq &L, int &m)
{ // 出队列
    if (L.rear == L.front && tag == 0)
    {
        cout << "队列空！";
        return 0;
    }
    m = L.base[L.front];
    L.front = (L.front + 1) % MaxSize;
    if (L.rear == L.front)
        tag = 0;
    return 1;
}

int JudgeEmpty(Seq L)
{
    if (L.rear == L.front && tag == 0)
    {
        cout << "队列空！";
        return 0;
    }
}

int JudgeFullness(Seq L)
{
    if (L.rear % MaxSize == L.front && tag == 1)
    {
        cout << "队列已满！";
        return 0;
    }
}

int main()
{
    Seq S;
    int m;
    Init(S);
    Enter(S, 4);
    Enter(S, 5);
    Enter(S, 7);
    Enter(S, 6);
    Enter(S, 8);

    for (int i = 0; i < 5; i++)
    {
        Out(S, m);
        cout << m << " ";
    }
    JudgeEmpty(S);
    return 0;
}
