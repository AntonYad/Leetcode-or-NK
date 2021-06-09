class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == NULL)
        {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (k--)
        {
            fast = fast->next;
        }
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};