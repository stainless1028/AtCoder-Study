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

vi parent;

vi v, e;

int Find(int a){
    if(a == parent[a]){
        return a;
    }else{
        return parent[a] = Find(parent[a]);
    }
}

void Union(int a, int b){
    a = Find(a), b = Find(b);
    if(a != b){
        parent[b] = a;
        v[a] += v[b];
        e[a] += e[b] + 1;
    }else{
        e[a]++;
    }
}

void Solve(){
    int N;
    cin >> N;
    set<int> crd;
    vpii xr(N);
    for(auto &[x, r]: xr){
        cin >> x >> r;
        crd.insert(x + r);
        crd.insert(x - r);
    }
    unordered_map<int, int> coord;
    int idx = 0;
    for(const auto &i: crd){
        coord[i] = idx++;
    }
    v.assign(idx, 1);
    e.assign(idx, 0);
    parent.resize(idx);
    iota(parent.begin(), parent.end(), 0);
    for(auto [x, r]: xr){
        Union(coord[x + r], coord[x - r]);
    }
    int ans = 0;
    for(auto i = 0; i < idx; ++i){
        if(parent[i] == i){
            ans += min(v[i], e[i]);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    cin.tie()->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--)
        Solve();
    return 0;
}