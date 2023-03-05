#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <class T>
class Test
{
private:
    vector<T> a;
    // vector<T> b(5);
    // T b[m];

public:
    Test(int n, vector<T> array);
    void Sort();
    // void Sort(string);
    // void Sort(char);
    void Disp();
};

template <class T>
Test<T>::Test(int n, vector<T> array)
{
    //     typename vector<T>::iterator iter;
    //      for (iter = array.begin(); iter != array.end(); iter++)
    //     {

    //     }
    a.resize(n);
    int i;
    for (i = 0; i < array.size(); i++)
    {
        a[i] = array[i];
    }
}

template <class T>
void Test<T>::Sort()
{
    sort(a.begin(), a.end());
}
template <class T>
void Test<T>::Disp()
{
    typename vector<T>::iterator iter;
    for (iter = a.begin(); iter != a.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> array1 = {4, 5, 1, 6, 2};
    Test<int> a1(array1.size(), array1);
    a1.Sort();
    a1.Disp();

    vector<char> array2 = {'c', 'd', 'e', 'f', 'a', 'b'};
    Test<char> a2(array2.size(), array2);
    a2.Sort();
    a2.Disp();

    vector<string> array3 = {"Thursday", "Crazy", "KFC", "速速vivo50"};
    Test<string> a3(array3.size(), array3);
    a3.Sort();
    a3.Disp();
}