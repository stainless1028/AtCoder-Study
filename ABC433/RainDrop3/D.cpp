#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> v(n);
    for (string& s : v)
        cin >> s;

    int cnt = 0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            long long num = stoll(v[i] + v[j]);
            if (num % m == 0)
                cnt++;
        }
    }
    cout << cnt;
}