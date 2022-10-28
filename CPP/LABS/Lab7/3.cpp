#include <iostream>

using namespace std;
//实现集合运算的 = | +

class Set
{
private:
    int n;
    int *set;

public:
    Set(int n = 0, int *new_set = NULL)
    {
        this->n = n;
        if (n != 0 && new_set == NULL)
        {
            set = new int[n];
        }
        set = new_set;
    };
    ~Set();
    void ShowElement() const;

    Set operator|(const Set &s) const;
    bool operator=(const Set &s) const;
};

Set::~Set()
{
    if (set == NULL)
    {
        n = 0;
        delete set;
        this->set = NULL;
    }
}
// 是否相等
bool Set::operator=(const Set &s) const
{
    if (this->n != s.n)
    {
        return false;
    }
    int count[100] = {0};
    int i, j;
    for (i = 0; i < this->n; i++)
    {
        count[this->set[i]]++;
    }
    for (j = 0; j < s.n; j++)
    {
        count[s.set[j]]++;
    }
    for (i = 0; i < 100; i++)
    {
        if (count[i] == 1)
        {
            return false;
        }
    }
    return true;
}
// 并集运算重载
Set Set::operator|(const Set &s) const
{
    int n = 0;
    int *newset;
    newset = new int[this->n + s.n];
    int i, j;
    for (i = 0; i < this->n; i++)
    {
        newset[n++] = this->set[i];
    }
    int flag;
    for (j = 0; j < s.n; j++)
    {
        flag = 0;
        for (i = 0; i < this->n; i++)
        {
            if (this->set[i] != s.set[j])
            {
                flag++;
            }
        }
        if (flag == this->n)
        {
            newset[n++] = s.set[j];
        }
    }
    Set NewSet(n, newset);
    return NewSet;
};
void Set::ShowElement() const
{
    int i;
    for (i = 0; i < this->n; i++)
    {
        cout << this->set[i] << " ";
    }
    cout << endl;
}
int main()
{
    int a[] = {1, 2, 3, 5, 6};
    Set set1(5, a);
    cout << "集合A:" << endl;
    set1.ShowElement();
    int b[] = {1, 3, 5, 7, 9};
    Set set2(5, b);
    cout << "集合B:" << endl;
    set2.ShowElement();
    int c[] = {1, 3, 6, 2, 5};
    Set set3(5, c);
    cout << "集合C:" << endl;
    set3.ShowElement();
    cout << "A | B:" << endl;
    (set1 | set2).ShowElement();
    if ((set1 = set2))
    {
        cout << "A = B" << endl;
    }
    else
    {
        cout << "A != B" << endl;
    }

    if ((set1 = set3))
    {
        cout << "A = C" << endl;
    }
    else
    {
        cout << "A != C" << endl;
    }
}