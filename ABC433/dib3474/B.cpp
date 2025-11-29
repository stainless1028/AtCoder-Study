#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> num(n);
    for (int &e : num) cin >> e;

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = i; j >= 0; j--) {
            if (num[j] > num[i]) {
                cout << j + 1 << '\n';
                found = true;
                break;
            }
        }
        if (!found) cout << -1 << '\n';
    }
}