#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    //二分查找
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        int i, j;
        vector<int> intersection;
        unordered_map<int, int> map;
        for (i = 0; i < nums1.size(); i++)
        {
            map[nums1[i]]++;
        }
        for (j = 0; j < nums2.size(); j++)
        {
            
        }
    }
};
int main()
{
    vector<int> nums1 = {1, 2, 2, 1}, nums2 = {2, 2};
    Solution s;
    s.intersect(nums1, nums2);
}