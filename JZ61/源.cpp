class Solution {
public:
    char* Serialize(TreeNode* root) {
        string str;
        str = _Serialize(root);
        char* s = new char[str.size()];
        for (int i = 0; i < str.size(); i++)
        {
            s[i] = str[i];
        }
        return s;
    }
    TreeNode* Deserialize(char* str) {
        return _Deserialize(str);
    }
private:
    string _Serialize(TreeNode* root)
    {
        if (root == nullptr)
        {
            return "#!";
        }
        string str;
        str = to_string(root->val) + "!";
        str += _Serialize(root->left);
        str += _Serialize(root->right);
        return str;
    }
    TreeNode* _Deserialize(char*& str)
    {
        if (*str == '#')
        {
            ++str;
            return nullptr;
        }
        int sum = 0;
        while (*str != '!')
        {
            sum = sum * 10 + *str - '0';
            str++;
        }
        TreeNode* root = new TreeNode(sum);
        root->left = _Deserialize(++str);
        root->right = _Deserialize(++str);
        return root;
    }
};