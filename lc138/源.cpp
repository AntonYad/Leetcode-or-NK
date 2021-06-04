class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
        {
            return head;
        }
        Node* cur = head;
        while (cur)
        {
            Node* newnode = new Node(cur->val);
            newnode->random = NULL;
            newnode->next = NULL;

            Node* next = cur->next;
            cur->next = newnode;
            newnode->next = next;

            cur = next;
        }

        cur = head;
        while (cur)
        {
            Node* copy = cur->next;
            if (cur->random)

                copy->random = cur->random->next;

            cur = cur->next->next;
        }
        cur = head;
        Node* newhead = head->next;
        while (cur->next)
        {
            Node* copy = cur->next;
            Node* next = copy->next;
            cur->next = next;
            cur = copy;
        }
        return newhead;
    }
};