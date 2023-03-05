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
private:
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        ListNode *pA = headA;
        ListNode *pB = headB;
        while (pA != pB)
        {
            pA = (pA == nullptr) ? headB : headA->next;
            pB = (pB == nullptr) ? headA : headB->next;
        }
        return pA;
    }
};
