#include <iostream>
#include <vector>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        stack<int> s;
        int e;
        ListNode *p;
        p = head;

        vector<int> result;
        while (p != NULL)
        {
            result.insert(result.begin(), p->val);
            p = p->next;
        }
        return result;
    }
};