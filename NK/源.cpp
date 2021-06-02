#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            continue;
        }
        cin.get();
        vector<string> v(n);
        for (int i = 0; i < n; ++i) {
            getline(cin, v[i]);
            if (v[i].find(",") != string::npos ||
                v[i].find(" ") != string::npos) {
                v[i].insert(0, "\"");
                v[i].insert(v[i].size(), "\"");
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << v[i];
            if (i < n - 1) {
                cout << ", ";
            }
            else {
                cout << endl;
            }
        }
    }
    return 0;
}