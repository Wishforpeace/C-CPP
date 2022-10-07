#include <iostream>
#include <string.h>
using namespace std;
class String
{
private:
    string Origin;

public:
    String(string origin);
    bool MatchSubsting(const string str);
    ~String();
};

String::String(string origin)
{
    this->Origin = origin;
}

String::~String()
{
}
bool String::MatchSubsting(const string str)
{
    int len;
    len = str.size();
    int i, j;
    j = 0;
    int flag;
    for (i = 0; i < len; i++)
    {
        if (Origin[i + j] != str[i])
        {
            j++;
            i = 0;
            flag = 0;
            continue;
        }
        flag = 1;
    }
    if (flag == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string substring;
    cout << "字符串为:hello world" << endl;
    cout << "请输入子串:";
    cin >> substring;
    String str("hello world");
    bool judge;
    judge = str.MatchSubsting(substring);
    if (judge)
    {
        cout << substring << "是子串" << endl;
    }
    else
    {
        cout << substring << "不是子串" << endl;
    }
}