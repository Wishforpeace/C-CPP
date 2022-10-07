#include <iostream>

using namespace std;

class illegalParameterValue
{
private:
    string message;
public:
    illegalParameterValue(string theMessage = "Illegal parameter value")
    {message = theMessage;}
    void outputMessage(){cout<<message<<endl;}
};



template <class T>
struct chainNode
{
    //数据成员
    T element;
    chainNode<T> *next;

    // 方法
    chainNode() {}
    chainNode(const T &element)
    {
        // 函数中某个变量与成员变量名字相同，this来表示
        this->element = element;
    }
    chainNode(const T &element, chainNode<T> *netx)
    {
        this->element = element;
        this->next = next;
    }
};
template <class T>
class chain : public linearlist<T>
{
private:
    /* data */
public:
    //构造函数，复制构造函数和析构函数
    chain(int initialCapacity = 10);
    chain(const chain<T> &);
    ~chain();

    //抽象数据类型ADT的方法
    //检验是否为空
    bool empty() const { return listSize == 0; }
    //获取链表大小
    int size() const { return listSize; }
    //根据索引获取线性表的值
    T &get(int theIndex) const;
    //根据数值，查询索引
    int indexOf(const T &theElement) const;
    //删除元素
    void erase(int theIndex);
    //插入元素
    void insert(int theIndex, const T &theElement) const;
    //输出线性表
    void output(ostream &out) const;

protected:
    void checkIndex(int theIndex)const;
    //如果索引无效，抛出异常
    chainNode<T>* firstNode; //指向链表第一个节点的指针
    int listSize; //线性表的元素个数

};
template<class T>
chain<T> :: chain(int initialCapacity)
{
    // 析构函数
    if(initialCapacity<1)
    {
        ostringstream s;
        s<<"Initial capacityn = "<<initialCapacity<<"Must be > 0";
        throw illegalParameterValue(s.str());
    }
    firstNode = NULL;
    listSize = 0;
}

template<class T>
chain<T>::chain(const chain<T>& theList)
{
    //复制构造函数
    listSize = theList.
}
int mian()
{
}