#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    //暴力
    vector<int> twoSum(vector<int> &nums, int target)
    {

        int i, j;
        for (i = 0; i < nums.size() - 1; i++)
        {

            for (j = i + 1; j < nums.size(); j++)
            {

                if (nums[i] + nums[j] == target)
                {

                    return {i, j};
                }
            }
        }
        return {};
    }
    //哈希
    vector<int> twoSumHash(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end())
            {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    vector<int> result;
    Solution s;
    result = s.twoSumHash(nums, 9);
    cout << result[0] << " , " << result[1] << endl;
}