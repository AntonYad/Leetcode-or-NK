class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
		{
			return head;
		}
		ListNode* prev = head;
		ListNode* cur = head->next;
		ListNode* next = prev->next;
		while (cur)
		{
			prev->next = prev->next->next;
			if (cur->next != nullptr)
				cur->next = cur->next->next;
			else
			{
				cur->next = nullptr;
				break;
			}

			prev = prev->next;
			cur = cur->next;
		}
		prev->next = next;
		return head;
	}
};