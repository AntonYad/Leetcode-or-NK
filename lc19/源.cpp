class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = head;
        ListNode* cur = head;
        if (head->next == nullptr && n == 1)
        {
            return nullptr;
        }
        while (n--)
        {
            cur = cur->next;
        }

        if (!cur)
        {
            return head->next;
        }
        ListNode* pp = nullptr;
        while (cur)
        {
            pp = prev;
            cur = cur->next;
            prev = prev->next;
        }
        pp->next = prev->next;
        return head;
    }
};