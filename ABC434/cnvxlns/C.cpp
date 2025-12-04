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

void Solve() {
    int N, H;
    cin >> N >> H;
    vector<pair<int, pii>> h(N);
    for(auto& [t, range] : h) {
    auto &[l, u] = range;
        cin >> t >> l >> u;
    }
    int tprev = 0;
    pii possiblerange = {H, H};
    bool flag = true;
    for(const auto &[t, range]: h){
        auto [l, u] = range;
        auto [minh, maxh] = possiblerange;
        
        minh = max(minh - (t - tprev), l);
        maxh = min(maxh + (t - tprev), u);

        if(minh > maxh){
            flag = false;
            break;
        }
        possiblerange = {minh, maxh};
        tprev = t;
    }
    cout << (flag ? "Yes" : "No") << endl;
}

int32_t main() {
    cin.tie()->sync_with_stdio(0);
    int t = 1999;
    cin >> t;
    while(t--)
        Solve();
    return 0;
}