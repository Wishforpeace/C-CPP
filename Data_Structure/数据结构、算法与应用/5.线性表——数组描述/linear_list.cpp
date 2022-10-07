#include<iostream>
using namespace std;
//1.创建线性表
//2.撤销线性表
//3.确定线性表是否为空
//4.确定线性表的长度
//5.按一个给定的索引查找一个元素
//6.按照给定元素查找其索引
//7.按照给定索引删除一个元素
//8.按照给定索引插入一个元素
//9.从左往右输出元素
template<class T>
class linearList
{
private:
    /* data */
public:
    virtual  linearList(){}
    
    virtual bool empty() const = 0;
    //返回true，当且仅当线性表为空

    virtual int size() const = 0;
    //返回线性表的元素个数
  
    virtual T& get(int theIndex)const = 0;
    //返回索引为theIndex

    virtual int indexOf(const T& theElement)const = 0;
    //返回元素theElement第一次出现时的索引

    virtual void erase(int theIndex) = 0;
    //删除索引为theIndex的元素

    virtual void insert(int theIndex,const T& theElement) = 0;
    //把theElement插入线性表中索引为theIndex的位置上

    virtual void output(ostream& out)const = 0;
    //线性表插入输出流
};

//改变一个一维数组的长度
template<class T>
void changeLength1D(T*& a,int oldLength,int newLength)
{
    if(newLength<0)
    {
        throw illegalParameterValue("new length must be>=0");
    }
    T* temp = new T[newLength];
    int number = min(oldLength,newLength);
    
}

int main()
{

}