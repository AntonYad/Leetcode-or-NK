class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for (int x : nums) hash.insert(x);      //ע���ϣset�Ĳ��뷽ʽ

        int maxLen = 0;

        for (int x : nums)              //����ÿһ����
            if (!hash.count(x - 1))     //��ǰ��֮ǰ������������ǰ��Ϊ�������еĵ�һ����ʱ
            {
                int curNum = x;
                int curLen = 1;

                while (hash.count(curNum + 1))  //�жϵ�ǰ��֮���Ƿ�����
                {
                    curNum++;
                    curLen++;
                }

                maxLen = max(maxLen, curLen);   //ÿ�α���������󳤶�
            }

        return maxLen;
    }
};