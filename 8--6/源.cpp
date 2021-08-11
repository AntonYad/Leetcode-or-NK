//#include<iostream>
//#include<vector>
//#include<math.h>
//#include<algorithm>
//using namespace std;
//int Count(vector<int> vx, vector<int> vy, int q1, int q2, int p, int n)
//{
//    int sum = q1 + q2;
//    for (int i = 0; i < vx.size(); i++)
//    {
//        if (vx[i] <= (sum + p) && vx[i] >= (sum - p))
//        {
//            n++;
//        }
//    }
//    for (int i = 0; i < vy.size(); i++)
//    {
//        for (int j = i + 1; j < vy.size(); j++)
//        {
//            if (vy[i] + vy[j] <= (sum + p) && vy[i] + vy[j] >= (sum - p))
//            {
//                n++;
//            }
//        }
//    }
//    return n;
//}
//int main()
//{
//    int q1, q2, p;
//    while (cin >> q1 >> q2 >> p)
//    {
//        int x;
//        cin >> x;
//        vector<int> vx(x, 0);
//        for (int i = 0; i < x; i++)
//        {
//            cin >> vx[i];
//        }
//        int y;
//        cin >> y;
//        vector<int> vy(y, 0);
//        for (int i = 0; i < y; i++)
//        {
//            cin >> vy[i];
//        }
//
//        int n = 0;
//        cout << Count(vx, vy, q1, q2, p, n) << endl;
//    }
//    return 0;
//}


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
int Time(vector<int> v, int N, int T1, int T2, int T3, int T4)
{
    int time = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] == v[i + 1])
        {
            time += T1;
        }
        else if (v[i] > v[i + 1])
        {
            if (T3 > T4 + T2)
            {
                time += T4 + T2;
            }
            else
            {
                time += T3;
            }
        }
        else if (v[i] < v[i + 1])
        {
            if (T2 > T4 + T3)
            {
                time += T4 + T3;
            }
            else
            {
                time += T3;
            }
        }
    }
    return time;
}
int main()
{
    int N, T1, T2, T3, T4;
    while (cin >> N >> T1 >> T2 >> T3 >> T4)
    {
        vector<int> v(N, 0);
        for (int i = 0; i < N; i++)
        {
            cin >> v[i];
        }
        cout << Time(v, N, T1, T2, T3, T4) << endl;;
    }
    return 0;
}

//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//#include<math.h>
//using namespace std;
//int Time(vector<int> v, int N, int T1, int T2, int T3, int T4)
//{
//    int flag = 1;
//    int time = 0;
//    int i = 0;
//    int len = (v.size() - 1) / 2;
//    while (i < v.size())
//    {
//        if (v[i] == v[i + 2])
//        {
//            time += T1;
//        }
//        else if (v[i] > v[i + 2])
//        {
//            if (T3 > T4 + T2)
//            {
//                if (flag == 1)
//                {
//                    i = i + 1;
//                }
//                else
//                {
//                    i = i - 1;
//                }
//                flag *= -1;
//                time += T4 + T2;
//            }
//            else
//            {
//                time += T3;
//            }
//        }
//        else if (v[i] < v[i + 2])
//        {
//            if (T2 > T4 + T3)
//            {
//                if (flag == 1)
//                {
//                    i = i + 1;
//                }
//                else
//                {
//                    i = i - 1;
//                }
//                flag *= -1;
//                time += T4 + T3;
//            }
//            else
//            {
//                time += T3;
//            }
//        }
//        i = i + 2;
//    }
//    return time;
//}
//int main()
//{
//    int N, T1, T2, T3, T4;
//    while (cin >> N >> T1 >> T2 >> T3 >> T4)
//    {
//        vector<int> v;
//        for (int i = 0; i < N; i++)
//        {
//            int num;
//            cin >> num;
//            v.push_back(num);
//            v.push_back(N - num);
//        }
//        cout << Time(v, N, T1, T2, T3, T4) << endl;;
//    }
//    return 0;
//}