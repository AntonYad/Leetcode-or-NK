//给出两个非空的单向链表来表示两个非负的整数。
//
//其中它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字
//
//如果，我们将两个数相加，则会返回一个新的链表来表示它们的和 这两个数都不会以0开头
//
//示例：
//输入：（2->4->3） + (2->6->4) 输出： 4->0->8 原因：342 + 462 = 804
//
//
//
//node* match(node* head1,node* head2)
//{
//	node* cur1 = head1;
//	node* cur2 = head2;
//	int len1=0, len2=0;
//	while (cur1)
//	{
//		len1++;
//		cur1 = cur1->next;
//	}
//	while (cur2)
//	{
//		len2++;
//		cur2 = cur2->next;
//	}
//	if (len2 == 0) 
//	{
//		return cur1;
//	}
//	else if (len1 == 0)
//	{
//		return cur2;
//	}
//	else if (len1 == len2)
//	{
//		int cur1 =  head1;
//		int cur2 =  head2;
//		while (cur1&&cur2)
//		{
//			cur1->val += cur2->val;
//			cur1 = cur1->next;
//			cur2 = cur2->next;
//		}
//		cur1 = head1;
//		int carry = 0;
//		while (cur1)
//		{
//			if (cur1->val >= 10)
//			{
//				cur1->val = (cur1->val) % 10;
//				carry = val / 10;
//			}
//
//		}
//		return cur1;
//	}
//	else// len!=len
//	{
//
//	}
//}
//
//
//
//#include<iostream>
//using namespace std;
//struct node
//{
//	int val;
//	node* next;
//}node;
//
//int main()
//{
//	int n1, n2;
//	cin >> n1;
//	cin >> n2;
//	node* list1;
//	node* list2;
//
//	int cur1 = n1;
//	while (cur1)
//	{
//		int n = cur1 % 10;
//		node* cur = new node(n);
//		cur1 /= 10;
//	}
//	int cur2 = n2;
//	while (cur2)
//	{
//
//	}
//	node* head1 = nullptr;
//	node* head2 = nullptr;
//	while
//}
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//    string str;
//    while (cin >> str)
//    {
//        for (int i = 0; i < str.size(); i++)
//        {
//            if (str[i] == '_')
//            {
//                str[i + 1] -= 32;
//                for (int j = i ;  j < str.size(); j++)
//                {
//                    str[j] = str[j + 1];
//                }
//            }
//        }
//    }
//    cout << str << endl;
//    return 0;
//}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string str;
    while (getline(cin, str))
    {
        reverse(str.begin(), str.end());
        for (int i = 0; i < str.size(); i++)
        {
            int j;
            for (j = i; j < str.size(); j++)
            {
                if (str[j] == ' ')
                {
                    reverse(str.begin() + i, str.begin() + j);

                }
            }
            i = j;
        }
        cout << str << endl;
    }
    return 0;
}