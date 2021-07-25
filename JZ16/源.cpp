class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while (pHead1 && pHead2)
        {
            if (pHead1->val > pHead2->val)
            {
                head->next = pHead2;
                pHead2 = pHead2->next;
            }
            else
            {
                head->next = pHead1;
                pHead1 = pHead1->next;
            }
            head = head->next;
        }
        if (pHead1)
        {
            head->next = pHead1;
        }
        if (pHead2)
        {
            head->next = pHead2;
        }
        return cur->next;
    }
};