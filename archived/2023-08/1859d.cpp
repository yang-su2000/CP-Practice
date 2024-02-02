#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, q, x;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> v(n, vector<int>(4));
        for (int i=0; i<n; i++) {
            cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];
        }
        sort(v.begin(), v.end());
        vector<int> mval(n, -1);
        function<int(int)> dfs = [&](int i){
            return 0;
        };
        cin >> q;
        for (int i=0; i<q; i++) {
            cin >> x;
        }
    }
}