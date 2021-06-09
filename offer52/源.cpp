class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }
        int conuntA = 0;
        int conuntB = 0;
        ListNode* cura = headA;
        ListNode* curb = headB;
        while (cura)
        {
            conuntA++;
            cura = cura->next;
        }
        while (curb)
        {
            conuntB++;
            curb = curb->next;
        }
        cura = headA;
        curb = headB;
        int num = abs(conuntA - conuntB);
        if (conuntA > conuntB)
        {
            while (num--)
            {
                cura = cura->next;
            }
        }
        else
        {
            while (num--)
            {
                curb = curb->next;
            }
        }
        while (cura && curb)
        {
            if (cura == curb)
            {
                return cura;
            }
            else
            {
                cura = cura->next;
                curb = curb->next;
            }
        }
        return NULL;
    }
};