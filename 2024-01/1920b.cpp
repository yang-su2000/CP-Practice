#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, k, x;
    cin >> t;
    while (t--) {
        cin >> n >> k >> x;
        vector<int> a(n);
        for (int &i: a) cin >> i;
        sort(a.begin(), a.end());
        vector<int> p(n + 1);
        vector<int> b(n + 1);
        for (int i=1; i<=n; i++) p[i] = p[i-1] + a[i-1];
        for (int i=1; i<=n; i++) b[i] = b[i-1] + -abs(a[i-1]);
        int ans = INT_MIN;
        for (int i=n; k>=0 && i>=0; i--, k--) {
            int cur = b[i];
            if (i-x >= 0) {
                cur -= b[i-x];
                cur += p[i-x];
            }
            ans = max(ans, cur);
        }
        cout << ans << endl;
    }
}