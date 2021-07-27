/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (pHead == nullptr)
        {
            return nullptr;
        }
        RandomListNode* cur = pHead;
        while (cur)
        {
            RandomListNode* next = cur->next;
            RandomListNode* newnode = new RandomListNode(cur->label);

            cur->next = newnode;
            newnode->next = next;
            cur = next;
        }
        cur = pHead;
        while (cur)
        {
            if (cur->random)
            {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        RandomListNode* newhead = pHead->next;
        cur = pHead;
        while (cur->next)
        {
            RandomListNode* copy = cur->next;
            RandomListNode* next = copy->next;
            cur->next = next;
            cur = copy;
        }
        return newhead;
    }
};