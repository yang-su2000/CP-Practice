#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        if (abs(a - b) > 1 or a + b + 2 > n) {
            cout << -1 << endl;
            continue;
        }
        if (a == 0 and b == 0) {
            for (int i=0; i<n; i++) cout << i + 1 << " \n"[i == n-1];
            continue;
        }
        vector<int> ans(n);
        int lo = 1, hi = n;
        bool flag;
        if (a >= b) {
            ans[0] = lo++;
            flag = true;
        } else {
            ans[0] = hi--;
            flag = false;
        }
        for (int i=1; i<n; i++) {
            if (flag) {
                ans[i] = hi--;
                a--;
            } else {
                ans[i] = lo++;
                b--;
            }
            if (a > 0 or b > 0) flag = !flag;
        }
        for (int i=0; i<n; i++) {
            cout << ans[i] << " \n"[i == n-1];
        }
    }
}