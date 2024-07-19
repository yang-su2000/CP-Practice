#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int q, n;
    string s, t;
    cin >> q;
    while (q--) {
        cin >> n >> s >> t;
        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') break;
            if (s[i] != t[i]) {
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
}