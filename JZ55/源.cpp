class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (pHead == nullptr)
        {
            return nullptr;
        }
        ListNode* slow = pHead;
        ListNode* fast = pHead;
        while (fast && fast->next)
        {

            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                break;
            }
        }
        if (!fast || !fast->next)
        {
            return nullptr;
        }
        slow = pHead;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};