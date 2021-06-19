class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while (cur)
        {
            if (cur->val == val)
            {
                if (cur == head)
                {
                    ListNode* temp = head;
                    head = head->next;
                    cur = head;
                    delete temp;
                }
                else
                {
                    ListNode* temp = cur;
                    prev->next = cur->next;
                    cur = cur->next;
                    delete temp;
                }
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};


