class Solution {
public:
    pair<ListNode*, ListNode*> _reverseKGroup(ListNode* head, ListNode* tail)
    {
        ListNode* cur = head;
        ListNode* prev = tail->next;
        while (prev != tail)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return { tail,head };
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode* pre = newhead;
        while (head)
        {
            ListNode* tail = pre;
            for (int i = 0; i < k; i++)
            {
                tail = tail->next;
                if (!tail)
                {
                    return newhead->next;//k>len
                }
            }
            ListNode* next = tail->next;
            pair<ListNode*, ListNode*> result = _reverseKGroup(head, tail);
            head = result.first;
            tail = result.second;

            tail->next = next;
            pre->next = head;
            pre = tail;
            head = pre->next;
        }
        return newhead->next;
    }
};