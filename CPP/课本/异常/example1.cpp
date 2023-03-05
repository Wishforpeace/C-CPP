#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str = "http://c.biancheng.net";
    // char ch1 = str[100]; //下标越界，ch1为垃圾值
    // cout << ch1 << endl;
    // // st检查是否越界
    // char ch2 = str.at(100); //下标越界，抛出异常
    // cout << ch2 << endl;

    //捕获异常
    try
    {
        char ch1 = str[100];
        cout << ch1 << endl;
    }
    catch (exception &e)
    {
        //异常没有被捕获
        //输出垃圾字符
        cout << "[1]out of bound!" << endl;
    }
    try
    {
        char ch2 = str.at(100);
        //捕获异常，跳转，不执行下一语句
        cout << ch2 << endl;
    }
    catch (exception &e)
    { // exception类位于<exception>头文件中
        cout << "[2]out of bound!" << endl;
    }
    return 0;
}