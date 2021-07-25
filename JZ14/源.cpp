}; */
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == nullptr)
        {
            return nullptr;
        }
        ListNode* cur = pListHead;
        int len = 0;
        while (cur)
        {
            len++;
            cur = cur->next;
        }
        if (k > len)
        {
            return nullptr;
        }
        len = len - k;
        while (len--)
        {
            pListHead = pListHead->next;
        }
        return pListHead;
    }
};