#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int prev = -1, cnt = 0;
    vector<pair<int, int>> v;
    for (char c : s) {
        if (prev == c - '0')
            cnt++;
        else {
            v.emplace_back(prev, cnt);
            cnt = 1;
            prev = c - '0';
        }
    }
    v.emplace_back(prev, cnt);

    int ans = 0;
    for (int i=1; i<v.size(); i++) {
        if (v[i-1].first + 1 == v[i].first)
            ans += min(v[i-1].second, v[i].second);
    }

    cout << ans;
}