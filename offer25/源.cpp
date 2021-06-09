class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l2 == NULL)
        {
            return l1;
        }
        else if (l1 == NULL)
        {
            return l2;
        }
        ListNode* head = new ListNode(l1->val);
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* curhead = head;
        while (cur1 && cur2)
        {

            if (cur1->val < cur2->val)
            {
                //ListNode* next=cur1->next;
                curhead->next = cur1;
                curhead = curhead->next;
                cur1 = cur1->next;
            }
            else if (cur1->val >= cur2->val)
            {
                curhead->next = cur2;
                curhead = curhead->next;
                cur2 = cur2->next;
            }
        }
        if (cur1)
        {
            curhead->next = cur1;
        }
        else
        {
            curhead->next = cur2;
        }
        return head->next;
    }
};