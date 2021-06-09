class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val)
        {
            return head->next;
        }
        if (head == NULL)
        {
            return NULL;
        }
        ListNode* cur = head->next;
        ListNode* prev = head;
        while (cur)
        {
            if (cur->val == val)
            {
                prev->next = cur->next;
            }
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};