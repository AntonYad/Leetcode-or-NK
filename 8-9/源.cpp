//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//int cmp(string version1, string version2)
//{
//    int v1 = 0; int v2 = 0; int end = max(version1.size(), version2.size());
//    while (v1 < end || v2 << end)
//    {
//        int sum1 = 0; int sum2 = 0;
//        while (v1 < end && version1[v1] != '.')
//        {
//            sum1 = sum1 * 10 + version1[v1] - '0';
//            v1++;
//        }
//        while (v2 < end && version2[v2] != '.')
//        {
//            sum2 = sum2 * 10 + version2[v2] - '0';
//            v2++;
//        }
//        if (v1 > v2)return 1;
//        if (v1 < v2)return -1;
//        v1++;
//        v2++;
//    }
//    return 0;
//}
//int main()
//{
//    string version1;
//    string version2;
//    cin >> version1;
//    cin >> version2;
//    auto it = cmp(version1, version2);
//    cout << it << endl;
//    return 0;
//}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> getsum(vector<int> v)
{
    sort(v.begin(), v.end());
    vector<vector<int>> vv;
    for (int i = 0; i < v.size(); i++)
    {
        if (i > 0 && v[i] == v[i - 1])
        {
            continue;
        }
        int left = i + 1;
        int right = v.size() - 1;
        while (left < right)
            if (left < right && v[i] + v[left] + v[right]>0)
            {
                right--;
            }
            else if (left < right && v[i] + v[left] + v[right] < 0)
            {
               left++;
          }
           else
             {
                 vv.push_back(vector<int>{v[i], v[left], v[right]});
                while (left < right && v[left] == v[left + 1])
                {
                   left++;
                }
             while (left < right && v[right] == v[right - 1])
               {
                    right--;
               }
                 left++;
                  right--;
        }
    }
    return vv;
}
int main()
{
    vector<int> v = { -1,0,1,2,-1,-1 };
    vector<vector<int>> vv;
    vv=getsum(v);
    for (auto& e : vv)
    {
        for (auto& s : e)
        {
            cout << s << endl;
        }
    }
    return 0;
}