class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* beginhead = new ListNode(0);
        beginhead->next = head;
        ListNode* cur = beginhead;
        while (cur->next && cur->next->next)
        {
            ListNode* next = cur->next;
            ListNode* nnnext = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = next;
            cur->next->next->next = nnnext;

            cur = cur->next->next;
        }
        return beginhead->next;
    }
};