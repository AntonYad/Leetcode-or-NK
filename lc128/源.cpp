class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for (int x : nums) hash.insert(x);      //注意哈希set的插入方式

        int maxLen = 0;

        for (int x : nums)              //遍历每一个数
            if (!hash.count(x - 1))     //当前数之前不连续，即当前数为连续序列的第一个数时
            {
                int curNum = x;
                int curLen = 1;

                while (hash.count(curNum + 1))  //判断当前数之后是否连续
                {
                    curNum++;
                    curLen++;
                }

                maxLen = max(maxLen, curLen);   //每次遍历更新最大长度
            }

        return maxLen;
    }
};