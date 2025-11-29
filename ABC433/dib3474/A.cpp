#include <iostream>
#include <algorithm>
using namespace std;

// x + t / y + t == z
// x + t = zy + zt
// t - zt = zy - x
// t = (zy - x) / (1 - z)
// t >= 0 && t is integer
// zy - x <= 0

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    int t1 = z * y - x;
    int t2 = 1 - z;
    if (t1 <= 0 && t1 % t2 == 0) cout << "Yes";
    else cout << "No";  
}