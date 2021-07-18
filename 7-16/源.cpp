//#include<iostream>
//using namespace std;
//int main()
//{
//    int n;
//    while (cin >> n)
//    {
//        int cur = 0;
//        int empty = n;
//        int left = 0;
//        while (empty >= 3)
//        {
//            cur += (empty / 3);
//            left = empty % 3;
//            empty = left + empty / 3;
//            if (empty == 2)
//            {
//                cur++;
//            }
//        }
//        cout << cur << endl;
//    }
//    return 0;
//}
//#include<iostream>
//#include<set>
//using namespace std;
//int main()
//{
//    int n;
//    while (cin >> n)
//    {
//        set<int> s;
//        for (int i = 0; i < n; i++)
//        {
//            int num = rand() % 1000 + 1;
//            s.insert(num);
//        }
//        for (auto& e : s)
//        {
//            cout << e << endl;
//        }
//    }
//    return 0;
//}
class Solution {
public:
    int dfs(const string& s, int l, int r, int k) {
        vector<int> cnt(26, 0);
        for (int i = l; i <= r; i++) {
            cnt[s[i] - 'a']++;
        }

        char split = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0 && cnt[i] < k) {
                split = i + 'a';
                break;
            }
        }
        if (split == 0) {
            return r - l + 1;
        }

        int i = l;
        int ret = 0;
        while (i <= r) {
            while (i <= r && s[i] == split) {
                i++;
            }
            if (i > r) {
                break;
            }
            int start = i;
            while (i <= r && s[i] != split) {
                i++;
            }

            int length = dfs(s, start, i - 1, k);
            ret = max(ret, length);
        }
        return ret;
    }

    int longestSubstring(string s, int k) {
        int n = s.length();
        return dfs(s, 0, n - 1, k);
    }
};

���ߣ�LeetCode-Solution
���ӣ�https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/solution/zhi-shao-you-kge-zhong-fu-zi-fu-de-zui-c-o6ww/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������