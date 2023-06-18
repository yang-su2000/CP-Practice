#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t;
    map<char, ll> m {{'A', 1}, {'B', 10}, {'C', 100}, {'D', 1000}, {'E', 10000}};
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = (int) s.length();
        vector<int> v;
        for (int i=0; i<n; i++) {
            while (!v.empty() && s[v.back()] < s[i]) v.pop_back();
            v.push_back(i);
        }
        // for (int i: v) cout << s[i];
        // cout << endl;
        for (int i=0; i<(int)v.size(); i++) {
            int l = 0;
            if (i > 0) l = v[i-1]+1;
            int r = v[i]-1;
            int idx = -1;
            for (int j=l; j<=r; j++) {
                if (idx == -1 || s[j] > s[idx]) idx = j;
            }
            if (idx != -1) {
                s[idx] = 'E';
                break;
            } else if (s[v[i]] != 'E') {
                s[v[i]] = 'E';
                break;
            }
        }
        // cout << s << endl;
        ll ans = 0;
        vector<int> v2;
        for (int i=0; i<n; i++) {
            while (!v2.empty() && s[v2.back()] < s[i]) {
                ans -= m[s[v2.back()]];
                v2.pop_back();
            }
            v2.push_back(i);
        }
        // for (int i: v2) cout << s[i];
        // cout << endl;
        for (int i: v2) ans += m[s[i]];
        cout << ans << endl;
    }
}