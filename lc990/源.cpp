class UnionFindSet
{
public:
    // ��ʼʱ����������Ԫ��ȫ������Ϊ1
    UnionFindSet(size_t size)
        : _ufs(size, -1)
    {}

    // ��һ��Ԫ�صı�ţ��ҵ���Ԫ�����ڼ��ϵ�����
    int FindRoot(int index)
    {
        // ��������д洢���Ǹ������ҵ�������һֱ����
        while (_ufs[index] >= 0)
        {
            index = _ufs[index];
        }

        return index;
    }

    bool Union(int x1, int x2)
    {
        int root1 = FindRoot(x1);
        int root2 = FindRoot(x2);

        // x1�Ѿ���x2��ͬһ������
        if (root1 == root2)
            return false;

        // ������������Ԫ�غϲ�
        _ufs[root1] += _ufs[root2];

        // ������һ���������Ƹı������һ��
        _ufs[root2] = root1;
        return true;
    }

    // �����и����ĸ�������Ϊ���ϵĸ���
    size_t Count()const
    {
        size_t count = 0;
        for (auto e : _ufs)
        {
            if (e < 0)
                ++count;
        }

        return count;
    }

private:
    vector<int> _ufs;
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFindSet ufs(26);
        for (size_t i = 0; i < equations.size(); ++i)
        {
            // ���Ⱥ����˵��ַ��ϲ���һ��������
            if ('=' == equations[i][1])
            {
                ufs.Union(equations[i][0] - 'a', equations[i][3] - 'a');
            }
        }
        for (size_t i = 0; i < equations.size(); ++i)
        {
            // ���Ⱥ����˵��ַ��ϲ���һ��������
            if ('!' == equations[i][1])
            {
                // ���"!="���˵��ַ���ͬһ�������У�������
                if (ufs.FindRoot(equations[i][0] - 'a') == ufs.FindRoot(equations[i][3] -
                    'a'))
                    return false;
            }
        }

        return true;
    }
};