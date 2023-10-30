#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int T, n, q;
    cin >> T;
    while (T--) {
        cin >> n >> q;
        vector<int> a(n), x(q);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<q; i++) cin >> x[i];
        set<int> vis;
        for (int b: x) {
            if (vis.count(b)) continue;
            vis.insert(b);
            int val = (1 << b);
            for (int i=0; i<n; i++) {
                if (a[i] % val == 0) a[i] += val / 2;
            }
        }
        for (int i=0; i<n; i++) cout << a[i] << " \n"[i == n-1];
    }
}