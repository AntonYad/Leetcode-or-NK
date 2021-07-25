class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        if (head == nullptr)
        {
            return v;
        }
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }
        reverse(v.begin(), v.end());
        return v;
    }
};