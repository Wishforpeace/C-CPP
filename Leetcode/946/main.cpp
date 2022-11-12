#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> st;
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
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 3, 5, 1, 2};
    bool result;
    Solution solution;
    cout << solution.validateStackSequences(pushed, popped) << endl;
}
