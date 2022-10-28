
typedef struct ListNode Node;
struct ListNode *insertionSortList(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    { //链表为空或只有一个节点直接返回
        return head;
    }
    Node *sorthead = head; //定义新的链表，把原链表的每个节点有序插入到新链表中去
    Node *cur = head->next;
    Node *sorttail = head; //新链表的尾结点，方便尾插
    sorttail->next = NULL; //尾结点的next域置空
    while (cur)
    {
        Node *sortcur = sorthead;
        Node *prev = NULL;
        while (sortcur && cur->val >= sortcur->val)
        { //原链表的cur节点在新链表中找到插入的位置
            prev = sortcur;
            sortcur = sortcur->next;
        }
        if (sortcur == NULL)
        { //原链表的cur节点比新链表中每个节点都大，执行尾插
            sorttail->next = cur;
            cur = cur->next;
            sorttail = sorttail->next;
            sorttail->next = NULL;
        }
        else if (prev == NULL)
        { // cur节点比新链表中每个节点都小，执行头插
            Node *next = cur->next;
            cur->next = sorthead;
            sorthead = cur;
            cur = next;
        }
        else
        { //不是尾插，也不是头插，指定位置插入
            prev->next = cur;
            cur = cur->next;
            prev->next->next = sortcur;
        }
    }
    head = sorthead;
    return head; //返回原链表的头
}
