#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> merged(m + n);
        int i = 0, j = 0;
        int index = 0;
        while (i < m || j < n)
        {
            if (i == m)
            {
                merged[index++] = nums2[j++];
            }
            else if (j == n)
            {
                merged[index++] = nums1[i++];
            }
            else
            {
                if (nums1[i] < nums2[j])
                {
                    merged[index++] = nums1[i++];
                }
                if (nums1[i] > nums2[j])
                {
                    merged[index++] = nums2[j++];
                }
                if (nums1[i] == nums2[j])
                {
                    merged[index++] = nums1[i++];
                    merged[index++] = nums2[j++];
                }
            }
        }

        for (i = 0; i < m + n; i++)
        {
            nums1[i] = merged[i];
        }
        for (i = 0; i < m + n; i++)
        {
            cout << nums1[i] << " ";
        }
    }
};

int main(void)
{
    vector<int> nums1 = {2, 0}, nums2 = {1};
    // cout << "nums1" << nums1[0] << endl;
    Solution s;
    s.merge(nums1, 1, nums2, 1);
}