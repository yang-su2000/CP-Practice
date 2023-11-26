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
        vector<int> l(n), r(n);
        for (int i=0; i<n; i++) {
            cin >> l[i] >> r[i];
            l[i]--, r[i]--;
        }
        function<int(int)> dfs = [&](int node) {
            if (l[node] == -1 and r[node] == -1) return 0;
            int val = 0;
            if (s[node] == 'U') val++;
            int lval = INT_MAX, rval = INT_MAX;
            if (l[node] != -1) {
                lval = val;
                if (s[node] == 'R') lval++;
                lval += dfs(l[node]);
            }
            if (r[node] != -1) {
                rval = val;
                if (s[node] == 'L') rval++;
                rval += dfs(r[node]);
            }
            return min(lval, rval);
        };
        int ans = dfs(0);
        cout << ans << endl;
    }
}