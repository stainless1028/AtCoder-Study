#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    while (x<=300 && y<=300) {
        if (x == y * z) {
            cout << "Yes";
            return 0;
        }
        x++;
        y++;
    }
    cout << "No";
}