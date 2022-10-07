#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 // 存储空间初始化分配量
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE]; //数组，用于存储数据
    int length;             // 线性表长度
} SqlList;
//数组长度与线性表长度不等，线性表长度始终小于等于数组长度

// 自定义函数状态码
typedef int Status;

Status visit(ElemType c)
{
    cout << c << endl;
    return OK;
}

//初始化顺序线性表
Status InitList(SqlList *L)
{
    L->length = 0;
    return OK;
}

//线性表是否为空
Status ListEmpty(SqlList L)
{
    if (L.length == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

Status ClearList(SqlList *L)
{
    L->length = 0;
    return OK;
}

int ListLength(SqlList L)
{
    return L.length;
}

// 获取第i个元素
// 初始条件：L已存在，1≤i≤ListLength(L)
// 操作结果：用e返回第i个数据元素的值，i是位置，数组从0开始
Status GetElem(SqlList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length)
    {
        return ERROR;
    }
    *e = L.data[i - 1];

    return OK;
}

//插入元素
//初始条件：L已存在，1≤i≤ListLength(L)
//操作结果:第i个元素之后插入元素e,L的长度+1
Status ListInsert(SqlList *L, int i, ElemType e)
{

    int k;
    //线性表已满
    if (L->length == MAXSIZE)
    {
        return ERROR;
    }
    // i小于第一个位置或大于最后一个位置，则无法插入
    if (i < 1 || i > L->length + 1)
    {
        return ERROR;
    }
    //插入数据不在表尾
    if (i <= L->length)
    {
        //从第i个元素向后，都将其赋给后一个值，确保第i个值可被修改
        //[0,2,5,9,1,10,4]
        // 将3插入第2个的位置
        //[0,2,2,5,9,1,10,4]
        for (k = L->length - 1; k >= i - 1; k--)
        {
            L->data[k + 1] = L->data[k];
        }
    }
    // 第i个元素
    //[0,3,2,5,9,1,10,4]
    L->data[i - 1] = e;
    L->length += 1;
    // cout << L->data[i - 1] << endl;
    return OK;
}

//寻找某元素所在位置
int LocatElem(SqlList L, ElemType e)
{
    int i;
    if (L.length == 0)
    {
        return 0;
    }

    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            break;
    }
    if (i >= L.length)
    {
        return 0;
    }
    return i + 1;
}

//遍历输出线性表中的全部元素
Status ListTraverse(SqlList L)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        //输出对应元素的值
        visit(L.data[i]);
    }
    return OK;
}
//删除L中的第i个元素,用e返回其值
Status ListDelete(SqlList *L, int i, ElemType *e)
{
    int k;
    if (L->length == 0)
    {
        return ERROR;
    }
    // 如果删除位置小于1或大于长度
    if (i < 1 || i > L->length)
    {
        return ERROR;
    }
    *e = L->data[i - 1];
    // 如果删除的不是最后一个元素，则将后面元素前移，覆盖此元素
    if (i < L->length)
    {
        for (k = i; k < L->length; k++)
        {
            L->data[k-1]=L->data[k];
        }
    }
    L->length--;
    return OK;
}

//将Lb于La元素合并
void unionL(SqlList *La,SqlList Lb)
{
    int La_len,Lb_len,i;
    ElemType e;
    La_len = ListLength(*La);
    Lb_len = ListLength(Lb);
    //遍历Lb中的全部元素
    for(i=1;i<=Lb_len;i++)
    {
        GetElem(Lb,i,&e);
        // 如果La中没有该元素，则将其补到La之后
        if(!LocatElem(*La,e))
        {
            ListInsert(La,++La_len,e);
        }
    }
}
int main()
{
    SqlList L;
    SqlList Lb;

    ElemType e;
    Status i;

    int j, k;
    // 初始化线性表
    i = InitList(&L);
    cout << i << endl;
    if (i)
    {
        cout << "初始化之后的L.length:" << L.length << endl;
    }
    for (j = 1; j <= 5; j++)
    {
        i = ListInsert(&L, 1, j);
        if (!i)
        {
            break;
        }
    }
    //赋值化后全部输出
    cout << "赋值后的线性表" << endl;
    ListTraverse(L);

    cout << "L.length" << L.length << endl;

    i = ListEmpty(L);
    cout << "判断是否为空:" << i << endl;

    // 清空线性表
    i = ClearList(&L);
    cout << "进行清空操作:" << i << endl;
    i = ListEmpty(L);
    cout << "判断是否为空:" << i << endl;

    cout << "再次赋值" << endl;
    for (j = 1; j <= 10; j++)
    {
        ListInsert(&L, j, j);
    }

    ListTraverse(L);
    cout << L.length << endl;

    GetElem(L, 5, &e);
    cout << "第5个元素值为:" << e << endl;

    for (j = 3; j <= 4; j++)
    {
        k = LocatElem(L, j);
        if (k)
        {
            cout << "第" << k << "个元素值为:" << j << endl;
        }
        else
        {
            cout << "没有值为" << j << "的元素" << endl;
        }
    }

    k = ListLength(L);
    cout << "线性表长度为" << k << endl;

    for (j = k + 1; j >= k; j--)
    {
        i = ListDelete(&L,j,&e);
        if(i==ERROR)
        {
            cout<<"删除第"<<j<<"个元素失败"<<endl;
        }else{
            cout<<"删除第"<<j<<"个元素成功"<<endl;
        }
    }
    cout<<"一次输出L的元素"<<endl;
    ListTraverse(L);

    j = 5;
    ListDelete(&L,j,&e);
    cout<<"删除第5个元素之后的线性表"<<endl;
    ListTraverse(L);

    // 构造含有十个数的Lb
    i = InitList(&Lb);

    for(j=6;j<15;j++)
    {
        i = ListInsert(&Lb,1,j);
    }

    cout<<"Lb的全部元素"<<endl;
    ListTraverse(Lb);
    unionL(&L,Lb);
    cout<<"合并后的L"<<endl;
    ListTraverse(L);

    return 0;
}

template