#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<double> values;
    //自动分配内存
    //至少可以容纳20个
    //如果已经大于20，那么该语句不进行任何操作
    //满20个时，分配更多内存，原有迭代器失效
    values.reserve(20);

    //初始值
    vector<int> test{1, 2, 3, 4, 5, 6, 7, 8, 9};
}