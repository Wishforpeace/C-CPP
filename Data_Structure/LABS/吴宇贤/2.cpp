#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
	bool StackList(vector<char> &pushed, vector<char> &popped)
	{
		int i, j;
		i = 0;
		j = 0;
		stack<char> st;
		for (i = 0; i < pushed.size(); i++)
		{
			st.push(pushed[i]);
			//				cout<<pushed[i]<<endl;
			//				cout<<st.top()<<endl;
			//				cout<<popped[j]<<endl;
			while ((!st.empty()) && (st.top() == popped[j]))
			{
				// cout << st.top() << " " << popped[j] << endl;
				//					cout<<st.top()<<endl;
				st.pop();
				//					cout<<st.top()<<endl;
				j++;
			}
		}

		return st.empty();
	}
};
int main()
{
	vector<char> pushed(10);
	vector<char> popped(10);

	int i, j;
	char letter1, letter2;
	printf("pushed:");
	for (i = 0; i < 6; i++)
	{
		scanf("%c", &letter1);
		pushed[i] = letter1;
	}
	getchar();
	printf("popped:");
	for (j = 0; j < 6; j++)
	{
		scanf("%c", &letter2);
		popped[j] = letter2;
	}

	Solution s;
	cout << s.StackList(pushed, popped) << endl;
}
