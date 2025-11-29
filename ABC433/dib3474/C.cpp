#include <iostream>
#include <string>
using namespace std;

bool is_1122string(string str) {
    if (str[0] + 1 != str[str.length() - 1]) return false;
    if (str[0] != str[str.length() / 2 - 1] || str[str.length() / 2] != str[str.length() - 1]) return false;
    return true;
}

int main() {
    string s;
    cin >> s;
    int count = 0;
    for (int i = 3; i < (1 << s.length()); i = i << 1) {
        string temp;
        for (int j = 0; j < s.length(); j++) {
            if (i & (1 << j)) {
                temp += s[j];
            }
        }
        if (is_1122string(temp)) count++;
    }
    for (int i = 15; i < (1 << s.length()); i = i << 1) {
        string temp;
        for (int j = 0; j < s.length(); j++) {
            if (i & (1 << j)) {
                temp += s[j];
            }
        }
        if (is_1122string(temp)) count++;
    }
    for (int i = 63; i < (1 << s.length()); i = i << 1) {
        string temp;
        for (int j = 0; j < s.length(); j++) {
            if (i & (1 << j)) {
                temp += s[j];
            }
        }
        if (is_1122string(temp)) count++;
    }
    if (is_1122string(temp)) count++;
    cout << count;
}