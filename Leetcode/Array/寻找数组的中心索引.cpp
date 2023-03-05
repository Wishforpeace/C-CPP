#include <iostream>
#include <numeric>
using namespace std;

class Solution
{
public:
    int pivotIndex(int nums[])
    {
        int total = accumulate();
        cout << total;
    }
    int accumulate()
    {
        return 0;
    }
};
int main()
{
    Solution solve;
    int nums[] = {1, 2, 4, 5, 3, 5, 2};
    solve.pivotIndex(nums);
}