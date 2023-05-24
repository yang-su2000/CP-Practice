#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

#define ll long long

int main() {
    int t, n, m, tmp;
    int p, v, val;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> ls(n+m, -1);
        vector<int> idxs(n+m, -1);
        vector<int> counts(n+m);
        for (int i=0; i<n; i++) {
            cin >> tmp;
            tmp--;
            idxs[tmp] = 0;
            ls[i] = tmp;
        }
        for (int i=1; i<m+1; i++) {
            cin >> p >> v;
            p--;
            v--;
            val = ls[p];
            counts[val] += i - idxs[val];
            idxs[val] = -1;
            ls[p] = v;
            idxs[v] = i;
        }
        for (int i=0; i<n+m; i++) {
            if (idxs[i] >= 0) {
                counts[i] += m+1 - idxs[i];
            }
        }
        ll ans = ((ll) m + 1) * m * n;
        for (int i: counts) {
            ans -= (ll) i * (i - 1) / 2;
        }
        cout << ans << endl;
    }
}