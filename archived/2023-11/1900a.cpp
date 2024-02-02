#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int ans = 0;
        int count = 0;
        bool f = false;
        for (char c: s) {
            if (c == '.') {
                count++;
                ans++;
            } else count = 0;
            if (count >= 3) {
                f = true;
                break;
            }
        }
        if (f) cout << 2 << endl;
        else cout << ans << endl;
    }
}