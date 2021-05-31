class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next = head->next;
        while (next)
        {
            cur->next = prev;

            prev = cur;
            cur = next;
            next = next->next;
        }
        cur->next = prev;
        prev = cur;
        head = prev;
        return head;
    }
};