#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    string s;
    ll mod = 998244353;
    cin >> t;
    while (t--) {
        cin >> s;
        int n = (int) s.length();
        ll ans = 0, freq = 1;
        ll count = 1;
        char c = s[0];
        for (int i=1; i<n; i++) {
            if (s[i] == c) {
                count++;
            }
            else {
                ans += count - 1;
                freq = (freq * count) % mod;
                count = 1;
                c = s[i];
            }
        }
        ans += count - 1;
        freq = (freq * count) % mod;
        for (int i=1; i<=ans; i++) {
            freq = (freq * i) % mod;
        }
        cout << ans << " " << freq << endl;
    }
}