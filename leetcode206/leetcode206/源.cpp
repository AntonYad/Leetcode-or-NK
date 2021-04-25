class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* cur = head;
		ListNode* prev = NULL;
		ListNode* tmp;
		while (cur)
		{
			tmp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = tmp;
		}
		return prev;
	}
};