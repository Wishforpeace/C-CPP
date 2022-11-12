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
    void Display();
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

void String::Display()
{
    int i;
    for (i = 0; i < this->len; i++)
    {
        cout << this->string[i];
    }
    cout << endl;
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
    int len_replace, len_s;
    len_replace = strlen(replace);
    len_s = strlen(s);
    int i;
    int dist;

    dist = len_replace - len_s;

    for (i = location; i < location + len_replace; i++)
    {
        this->string[i] = replace[i - location];
    }
    this->string[this->len + dist + 1] = '\0';
    this->len += dist;
}

void Edit::ReplaceChar(char c, char replace)
{
    int i;
    for (i = 0; i < this->len; i++)
    {
        if (this->string[i] == c)
        {
            string[i] = replace;
        }
    }
}

void Edit::DeleteChar(char c)
{
    int i;
    i = 0;
    int last_len;
    while (i <= this->len)
    {
        if (this->len != last_len)
        {
            i--;
        }
        last_len = this->len;
        if (this->string[i] == c)
        {
            this->string[i] = this->string[i + 1];
            this->len--;
        }
        i++;
    }
}

void Edit::DeleteString(char *s)
{
    int location;
    if (!(this->isSubstring(s, &location)))
    {
        cout << "请正确输入子串" << endl;
    }

    int i;
    int len_s = strlen(s);
    for (i = location; i < location + len_s; i++)
    {
        this->string[i] = this->string[i + len_s];
        this->len--;
    }
}
int main()
{
    char a[] = "hello world";
    Edit s1(a);
    char b[] = "world";
    char replace[] = "C++";
    s1.Display();
    s1.ReplaceString(b, replace);

    s1.Display();

    s1.ReplaceChar('e', 'a');
    s1.Display();

    s1.DeleteChar('+');
    s1.Display();

    char s[] = "hallo";
    s1.DeleteString(s);
    s1.Display();
}