#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        int ans = 0;
        int cur = 0;
        char c = s[0];
        for (char c2: s) {
            if (c == c2) cur++;
            else {
                ans = max(ans, cur);
                c = c2;
                cur = 1;
            }
        }
        ans = max(ans, cur);
        cout << ans + 1 << endl;
    }
}