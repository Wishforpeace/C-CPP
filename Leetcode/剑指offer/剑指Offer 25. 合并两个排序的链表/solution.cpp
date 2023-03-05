#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class solution
{
public:
    ListNode *mergeTwoList(ListNode *L1, ListNode *L2)
    {
        if (L1 == nullptr)
        {
            return L2;
        }
        else if (L2 == nullptr)
        {
            return L1;
        }
        else if (L1->val < L2->val)
        {
            L1->next = mergeTwoList(L1->next, L2);
            return L1;
        }
        else
        {
            L2->next = mergeTwoList(L1, L2->next);
            return L2;
        }
    }
};
