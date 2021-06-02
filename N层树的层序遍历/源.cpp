class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> tree;
        q.push(root);
        if (root == nullptr)
        {
            return tree;
        }
        while (!q.empty())
        {
            int size = q.size();
            vector<int> row;
            while (size--)
            {
                Node* cur = q.front();
                q.pop();
                row.push_back(cur->val);
                //��ǰ�ڵ�ĺ������
                for (Node* e : cur->children)
                {
                    q.push(e);
                }
            }
            tree.push_back(row);
        }

        return tree;
    }
};