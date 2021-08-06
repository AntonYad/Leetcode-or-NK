//#include<iostream>
//#include<vector>
//#include<string>
//#include<queue>
//using namespace std;
//void dfs(int n, int k, int& sum, int& index, int& count)
//{
//    if (sum > n || (index == k && sum != n))
//    {
//        return;
//    }
//    if (sum == n && index == k)
//    {
//        count++;
//        return;
//    }
//    for (int i = 1; i <= n/2; i++)
//    {
//        sum = sum + i;
//        index++;
//        dfs(n, k, sum, index, count);
//        index--;
//        sum = sum - i;
//    }
//}
//int divide(int n, int k) {
//    // write code here
//    int sum = 0;
//    int index = 0;
//    int count = 0;
//    vector<int> used(n + 1, 0);
//    dfs(n, k, sum, index, count);
//    return count;
//}
//int main()
//{
//    int a=divide(7, 3);
//    cout << a << endl;
//    return 0;
//}
// Chapter14_5.cpp : Defines the entry point for the application.
// 数的划分
// 将整数n分成k份，且每份不能为空，任意两种划分方案不能相同（不考虑顺序）。
// 求整数n分为k份，共有多少种不同的分法。
// 输入两个整数n,k(6<n<=200,2<=k<=6)。
// 输出一个整数，即有几种不同的分法。

#include<iostream>
using namespace std;

int main()
{
	int n, k;
	cout << "输入整数n和划分的份数k:";
	cin >> n >> k;
	int dp[201][7];
	//全部初始化为0
	memset(dp, 0, sizeof(dp));
	//对于dp[0][0]作特殊处理（为了后面的动态转移方程能够起作用）
	dp[0][0] = 1;
	int i, j;
	//i的取值范围是1~n（不能超过给定的整数）
	for (i = 1; i <= n; i++)
		//j的范围是1~k（不能超过需要划分的份数）
		for (j = 1; j <= k; j++)
		{
			//划分的分数要小于等于该数本身
			if (i >= j)
				//动态转移方程
				dp[i][j] = dp[i - j][j] + dp[i - 1][j - 1];
		}
	cout << "共有" << dp[n][k] << "种分法" << endl;
	system("pause");
	return 0;
}
void merge(vector<int> num,int begin,int end)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge(num, begin, mid);
		merge(num, mid + 1, end);
		mergesort(num, temp, begin, mid, end);
	}
}


int getint()
{
	if (c >= 0 && c <= 9)
	{
		c = c - '0';
	}
	else
	{
		c = c - 'a' + 10;
	}
}
char getchar()
{

}

string add(string a, string b)
{
	int carry = 0;
	int a_end = a.size() - 1;
	int b_end = b.size() - 1;
	while (a >= 0 || b >= 0)
	{
		int first  = a >= 0 ? a - '0' : 0;
		int second = b >= 0 ? b - '0' : 0;
		int temp = a + b + carry;
		res += temp % 10;
		carry = temp / 10;
	}
	if (carry)
	{
		res += carry;
	}
	reverse(res.begin(), res.end());
	return res;
}
multimap aalgorithm priority semaphore 


Node* ListSort(Node* head)
{
	if (head == nullptr)
	{
		return head;
	}
	Node* mid = FindMid();
	Node* begin = head;
	auto newhead = _ListSort(begin, mid);
		return head;
}
Node* FindMid(Node* head)
{
	Node* prev = nullpter;
	Node* fast = head;
	Node* slow = head;
	while (fast&&fast->next)
	{
		prev = slow;
		
	}
}
Node* _ListSort()
{
	new newhead;
	while (begin&&mid)
	{
		if (begin < mid)
		{
			newhead-
		}
	}
	Node* del = newhead;
	newhead=
	free(newhead);
	return cur;
}





unordered_map<int, list<pair<int, int>>::iteartor> um;
int capacity;
list<pair<int, int>> list;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode()
		:left(nullptr), right(nullptr)
	{
	 }
};
vector<int> WatchTree(TreeNode* root)
{
	queue<TreeNode*> q;
	q.push(root);
	cur,prev
	while (!q.empty()||cur)
	{
		while (cur)
		{
			q.push(cur);
			cur = cur->left;
		}

		if (prev == nullptr || cur->right == prev)
		{
			v.push_back(cur->val);
			q.pop();
			prev = cur;
		}
		else
		{
			cur = cur->right;
		}
	}
}
#include<iostream>
#include<unordered_map>

int minlen = INT_MAX;
unordered_map<char, int> us;
unordered_map<char, int> ut;
for (auto& e : t)
{
	ut[e]++;
}
int j = 0;
string res;
for (int i = 0; i < s.size(); i++)
{
	us[s[i]]++;
	if (us[s[i]] <= ut[s[i]]) count++;
	while (us[s[j]]>ut[s[j]]) {
		us[s[j]]--;
		j++;
	}
	if (count == t.size())
	{
		if (minlen==INT_MAX||minlen > i - j + 1)
		{
			res = s.substr(j, i - j + 1);
		}
	}
}
return res;


ans = nullptr;
sort()
{
	if (a == nullptr)return b;
	if (b == nullptr)return a;
	Listnode* head = new Listnode(-1);
	List* head1 = a; List* head2 = b;
	for (a&&b)
	{

	}
}
for (int i = 0; i < l.size(); i++)
{
	ans = sort(ans, l[i]);
}


void Make(vector<int> pre, vector<int> inorder, int previ,int begin,int end)
{
	if (previ == pre.size())
	{
		return nullptr;
	}
	if (begin>end)
	{
		return nullptr;
	}
	int rooti = begin;
	while (rooti < =end)
	{
		if (inorder[rooti] == pre[previ])
		{
			break;
		}
		else
		{
			rooti++;
		}
	}
	TreeNode* root = new TreeNode(inorder[i]);
	previ++;
	root->left = Make(pre, in, previ, begin, rooti - 1);
	root->right = Make(rooti + 1, end);
}

for ()
{
	for ()
	{
		if (ma[i][j] == 1)
		{
			maxside = max()
				int maysize = min(row - i, col - j);
			for (int k = 1; k <= maysize; k++)
			{
				if (mar[i + k][j + k] == ''0)
					break;
				int flag=true;
				for (int m = 1; m <= k)
				{
					if (mar[i+m][j]||mar[i][j+m])
				}
			}
		}
	}
}int n m size
for (int i = 0; i < m.size(); i++)
{
	v.push_back([row][col])
	if (d = 0)
	{
		row==0&&<
			col==

	}
}



