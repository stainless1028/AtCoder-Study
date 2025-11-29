#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int& i : v)
        cin >> i;


    for (int i=0; i<n; ++i) {
        int tall = -1;
        for (int j=0; j<i; ++j) {
            if (v[j] > v[i])
                tall = j+1;
        }
        cout << tall << '\n';
    }
}