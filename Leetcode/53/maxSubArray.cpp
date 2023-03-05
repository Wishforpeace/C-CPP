#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 超时
class Solution1
{
public:
    // 暴力
    int maxSubArray(vector<int> &nums)
    {
        int i, j;
        int maxSum = nums[0];
        int sum;
        for (i = 0; i < nums.size(); i++)
        {
            for (j = 0; j < nums.size() - i; j++)
            {
                // cout << i << " " << j << endl;
                sum = Sum(nums, i, j);
                if (maxSum < sum)
                {
                    maxSum = sum;
                }
                // cout << sum << endl;
            }
        }
        return maxSum;
    }

    int Sum(vector<int> &nums, int start, int end)
    {
        int sum = 0;
        for (vector<int>::iterator iter = nums.begin() + start; iter != nums.begin() + start + end + 1; iter++)
        {
            sum += *iter;
        }
        return sum;
    }
};

class Solution2
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int pre = 0, maxAns = nums[0];

        for (const auto &x : nums)
        {
            // 比较加上与不加上
            //  cout << "pre\t"
            //       << "x\t"
            //       << "pre+x" << endl;
            //  cout << pre << "\t" << x << "\t" << pre + x << endl;
            pre = max(pre + x, x);
            // cout << "pre\t"
            //      << "maxAns" << endl;
            // cout << pre << "\t" << maxAns << endl;
            maxAns = max(maxAns, pre);
            // cout << "maxAns" << endl;
            // cout << maxAns << endl;
        }
        return maxAns;
    }
};

int main(void)
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution1 s1;
    cout << s1.maxSubArray(nums) << endl;
    Solution2 s2;
    cout << s2.maxSubArray(nums) << endl;
}