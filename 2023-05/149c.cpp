#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp
// ./a < input

#define ll long long

int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        char c = '0';
        string ans;
        for (char c2: s) {
            if (c2 == '?') ans += c;
            else {
                c = c2;
                ans += c;
            }
        }
        cout << ans << endl;
    }
}