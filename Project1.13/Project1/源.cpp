
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int Count(int n){
//	int count = 0;
//	if (n < 0 || n > 500000){
//		return -1;
//	}
//	for (int i = 2; i <= n; ++i){
//		int sum = 0;
//		for (int j = 2; j <= sqrt(i); ++j){
//			if (i % j == 0){
//				if (i / j == j){
//					sum += j;
//				}
//				else{
//					sum += j + (i / j);
//				}
//			}
//		}
//		if (sum + 1 == i){
//			++count;
//		}
//	}
//	return count;
//}
//int main(){
//	int n;
//	while (cin >> n){
//		cout << Count(n) << endl;
//	}
//	return 0;
//}
#include<stdio.h>
int main()
{
	long long a = 1, b = 2, c = 3;
	printf("%d %d %d", a, b, c);
	return 0;
}