class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
        {
            return NULL;
        }
        Node* cur = head;
        while (cur)
        {
            //Node* newnode=(Node*)malloc(sizeof(Node));
            Node* newnode = new Node(cur->val);
            newnode->next = NULL;
            newnode->random = NULL;

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
            {
                copy->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        cur = head;
        Node* newhead = head->next;
        while (cur->next)
        {
            Node* copy = cur->next;
            cur->next = copy->next;
            cur = copy;
        }
        return newhead;
    }
};