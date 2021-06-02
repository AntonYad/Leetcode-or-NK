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
                //当前节点的孩子入队
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