class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == nullptr)
        {
            return nullptr;
        }
        ListNode* cur = pHead;
        ListNode* prev = nullptr;
        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;

    }
};