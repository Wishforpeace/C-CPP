#include <iostream>
#include <string.h>
using namespace std;
class String
{
protected:
    char string[100];
    int len;

public:
    String(char *s);
};

String::String(char *s)
{
    this->len = strlen(s);
    int i;
    for (i = 0; i < this->len; i++)
    {
        this->string[i] = s[i];
    }
    // cout << this->len << endl;
}
class Edit : public String
{
public:
    Edit(char *s) : String(s){};
    void ReplaceString(char *s, char *replace);
    void ReplaceChar(char c, char replace);
    void DeleteString(char *s);
    void DeleteChar(char c);
    bool isSubstring(char *s, int *location);
};

bool Edit::isSubstring(char *s, int *location)
{
    int i, j;
    int flag;
    int len2;
    len2 = strlen(s);
    for (i = 0; i <= this->len - len2; i++)
    {
        flag = 0;
        for (j = 0; j < len2; j++)
        {
            // cout << this->string[i + j] << "  " << s[j] << endl;
            if (this->string[i + j] != s[j])
            {
                j = len2;
            }
            else
            {
                flag = j;
            }
        }
        if (flag == len2 - 1)
        {
            *location = i;
            return true;
        }
    }
    return false;
}

void Edit::ReplaceString(char *s, char *replace)
{
    int location;
    if (!this->isSubstring(s, &location))
    {
        cout << "请正确输入子串" << endl;
    }
    cout << location << endl;
    int len_replace, len_s;
    len_replace = strlen(replace);
    len_s = strlen(s);
    int i;
    int dist;
    if (len_replace > len_s)
    {
        dist = len_replace - len_s;
        this->len = len + dist;
        for (i = location + len_s; i < location + len_replace; i++)
        {
            this->string[i + dist] = this->string[i];
        }
    }
    int j;
    for (j = 0; j < this->len; j++)
    {
        cout << this->string[j];
    }
}
int main()
{
    char a[] = "hello world";
    Edit s1(a);
    char b[] = "world";
    char replace[] = "C++wcnmd";
    s1.ReplaceString(b, replace);
}