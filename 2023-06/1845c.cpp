#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, m;
    string s, l, r;
    cin >> t;
    while (t--) {
        cin >> s >> m >> l >> r;
        int i = 0;
        int p = -1;
        int n = (int) s.length();
        while (i < m && p < n) {
            char c1 = l[i];
            char c2 = r[i];
            int p2 = p + 1;
            for (char c=c1; c<=c2; c++) {
                int pi = p + 1;
                while (pi < n && s[pi] != c) pi++;
                p2 = max(p2, pi);
            }
            p = p2;
            i++;
        }
        if (p < n) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}