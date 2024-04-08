#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> a(n);
        for (ll &x: a) cin >> x;
        vector<ll> psum(n);
        psum[0] = a[0];
        for (int i=1; i<n; i++) psum[i] = psum[i-1] + a[i];
        vector<int> pr(n);
        int j = 0;
        for (int i=0; i<n; i++) {
            while (j < n and a[j] == a[i]) j++;
            pr[i] = j;
            // cout << pr[i] << " ";
        }
        // cout << endl;
        vector<int> ans(n, INT_MAX);
        function<bool(int, int, ll)> valid = [&](int l, int r, ll target){
            if (l < r) {
                int r_valid = pr[l];
                if (r < r_valid) return a[l] > target;
            }
            ll sum = psum[r];
            if (l > 0) sum -= psum[l-1];
            return sum > target;
        };
        for (int i=0; i<n; i++) {
            if (i > 0) {
                int l1 = 0, r1 = i-1;
                while (l1 < r1) {
                    int mid = l1 + (r1 - l1) / 2 + 1;
                    if (valid(mid, i-1, a[i])) l1 = mid;
                    else r1 = mid-1;
                }
                // cout << i << " @ l1: " << l1 << " " << valid(l1, i-1, a[i]) << endl;
                if (l1 >= 0 and valid(l1, i-1, a[i])) {
                    ans[i] = min(ans[i], i - l1);
                }
            }
            if (i < n-1) {
                int l2 = i+1, r2 = n-1;
                while (l2 < r2) {
                    int mid = l2 + (r2 - l2) / 2;
                    // cout << l2 << " " << mid << " " << r2 << " -> ";
                    if (valid(i+1, mid, a[i])) r2 = mid;
                    else l2 = mid+1;
                }
                // cout << i << " @ l2: " << l2 << " " << valid(i+1, l2, a[i]) << endl;
                if (l2 < n and valid(i+1, l2, a[i])) {
                    ans[i] = min(ans[i], l2 - i);
                }
            }
        }
        for (int i=0; i<n; i++) {
            if (ans[i] == INT_MAX) ans[i] = -1;
            cout << ans[i] << " \n"[i == n-1];
        }
    }
}