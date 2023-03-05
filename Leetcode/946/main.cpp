#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<char> &pushed, vector<char> &popped)
    {
        stack<char> st;
        int n = pushed.size();
        for (int i = 0, j = 0; i < n; i++)
        {
            //插入数据
            //能够避免产生不必要的临时变量
            st.emplace(pushed[i]);
            while (!st.empty() && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};

int main()
{
    vector<char> pushed = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<char> popped = {'f', 'e', 'd', 'c', 'b', 'a'};
    bool result;
    Solution solution;
    cout << solution.validateStackSequences(pushed, popped) << endl;
}
