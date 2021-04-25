//class Solution {
//public:
//	ListNode* removeElements(ListNode* head, int val) {
//		if (head == NULL)
//		{
//			return NULL;
//		}
//		while (head != NULL&&head->val == val)
//		{
//			ListNode* tmp = head;
//			head = head->next;
//			delete tmp;
//		}
//		ListNode* cur = head;
//		while (cur != NULL&&cur->next != NULL)
//		{
//			if (cur->next->val == val)
//			{
//				ListNode* tmp = cur->next;
//				cur->next = cur->next->next;
//
//				delete tmp;
//			}
//			else
//				cur = cur->next;
//		}
//		return head;
//	}
//};
class Solution
{
public:
	ListNode* removeElements(ListNode* head, int val)
	{
		ListNode* newhead = new ListNode(0);
		newhead->next = head;
		ListNode* cur = newhead;
		while (cur->next != NULL)
		{
			if (cur->next->val == val)
			{
				ListNode* tmp = cur->next;
				cur->next = cur->next->next;
				delete tmp;
			}
			else
			{
				cur = cur->next;
			}
		}
		return newhead->next;
	}
};