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

int grid[2002][2002], pfx[2002][2002];

void Solve() {
    int N;
    cin >> N;
    vector<tuple<int, int, int, int>> udlr(N);
    for(auto &[u, d, l, r]: udlr){
        cin >> u >> d >> l >> r;
        grid[u][l]++;
        grid[u][r + 1]--;
        grid[d + 1][l]--;
        grid[d + 1][r + 1]++;
    }
    for(auto i = 1; i <= 2000; ++i){
        for(auto j = 1; j <= 2000; ++j){
            grid[i][j] += grid[i][j - 1];
        }
    }
    for(auto i = 1; i <= 2000; ++i){
        for(auto j = 1; j <= 2000; ++j){
            grid[i][j] += grid[i - 1][j];
        }
    }
    int ans = 0;
    for(auto i = 1; i <= 2000; ++i){
        for(auto j = 1; j <= 2000; ++j){
            if(grid[i][j] == 0){
                ans++;
            }
            if(grid[i][j] == 1){
                pfx[i][j] = 1 + pfx[i - 1][j] + pfx[i][j - 1] - pfx[i - 1][j - 1];
            }else{
                pfx[i][j] = pfx[i - 1][j] + pfx[i][j - 1] - pfx[i - 1][j - 1];
            }
        }
    }
    for(const auto &[u, d, l, r]: udlr){
        int hidden = pfx[d][r] - pfx[u - 1][r] - pfx[d][l - 1] + pfx[u - 1][l - 1];
        cout << ans + hidden << endl;
    }
    
}

int32_t main() {
    cin.tie()->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--)
        Solve();
    return 0;
}