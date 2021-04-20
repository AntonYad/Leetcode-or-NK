#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i){
		cin >> v[i];
	}
	int ret = 1;
	for (int i = 1; i < n - 1; ++i){
		if (v[i - 1] < v[i] && v[i] > v[i + 1] || v[i - 1] > v[i] && v[i] < v[i + 1]){
			++ret;
			if (i != n - 3){
				++i;
			}
		}
	}
	cout << ret << endl;
	return 0;
}