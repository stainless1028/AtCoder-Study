#include<bits/stdc++.h>

#define Size 200032
#define inf 0x3f3f3f3f
#define endl "\n"
#define sp " "
#define int int64_t
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define rep(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)

const int MOD = 1e9 + 7;

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
using pic = pair<int, char>;
using pci = pair<char, int>;
using vpii = vector<pii>;
using vpic = vector<pic>;
using vpci = vector<pci>;
using vtiii = vector<tiii>;

pii operator+(const pii& a, const pii& b) {
    return { a.first + b.first, a.second + b.second };
}
pii operator-(const pii& a, const pii& b) {
    return { a.first - b.first, a.second - b.second };
}

pii dxy[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

bool is_1122string(string str) {
    if (str[0] + 1 != str[str.length() - 1]) return false;
    if (str[0] != str[str.length() / 2 - 1] || str[str.length() / 2] != str[str.length() - 1]) return false;
    return true;
}

void Solve() {
    string s;
    cin >> s;
    cout << is_1122string(s) << endl;
}

int32_t main() {
    cin.tie()->sync_with_stdio(0);
    int t = 1999;
    //cin >> t;
    while(t--)
        Solve();
    return 0;
}