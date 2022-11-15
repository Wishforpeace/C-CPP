#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
    //不满足负数案例
    // public:
    //     bool containsDuplicate(vector<int> &nums)
    //     {
    //         int *a;
    //         vector<int> count(10);
    //         for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
    //         {
    //             // cout << *iter << endl;
    //             count[*iter]++;
    //         }
    //         for (vector<int>::iterator iter = count.begin(); iter != count.end(); iter++)
    //         {
    //             if (*iter >= 2)
    //             {
    //                 return true;
    //             }
    //         }
    //         return false;
    //     }
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> s;
        //循环赋值，x等于nums[i]
        for (int x : nums)
        {
            //此时已经能够找到x，并且x不是最后一个刚插入的
            if (s.find(x) != s.end())
            {
                return true;
            }
            //插入x
            s.insert(x);
        }
        return false;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    Solution s;
    cout << s.containsDuplicate(nums);
}