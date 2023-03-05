#ifndef linearList_
#define linearList_
#include <iostream>

using namespcae std;

template <class T>
class linearList
{
public:
    virtual ~linearList(){};
    // 是否空
    virtual bool ListEmpty() const = 0;
    // 返回线性表大小
    virtual int ListLength() const = 0;
    // 由元素位置获取元素值
    virtual T &GetElem(int theIndex) const = 0;
    // 由元素获取元素索引
    virtual int LocateElem(const T &theElement) const = 0;
    // 根据索引插入某一元素
    virtual void ListInsert(int theIndex, const T &theElemen) = 0;
    // 根据索引删除某一元素
    virtual void ListDelete(int theIndex) = 0;
    // 输入线性表
    virtual void OutPut(ostream &out) const = 0;
};

#endif