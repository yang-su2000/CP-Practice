#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, m, q, x;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<pair<int, int>> segs(m);
        for (int i=0; i<m; i++) {
            cin >> segs[i].first >> segs[i].second;
            segs[i].first--;
            segs[i].second--;
        }
        cin >> q;
        vector<int> time(n, -1);
        vector<bool> flag(n);
        vector<int> psum(n);
        for (int i=0; i<q; i++) {
            cin >> x;
            x--;
            time[x] = i + 1;
            flag[x] = true;
        }
        if (flag[0]) psum[0] = 1;
        for (int i=1; i<n; i++) {
            psum[i] = psum[i-1] + flag[i];
        }
        bool done = false;
        for (auto &[l, r]: segs) {
            int len = r - l + 1;
            int count = psum[r];
            if (l) count -= psum[l-1];
            if (count > len / 2) {
                done = true;
                break;
            }
        }
        if (!done) {
            cout << -1 << endl;
            continue;
        }
        int a = 1;
        int b = q;
        while (a < b) {
            int mid = a + (b - a) / 2;
            vector<bool> flag2(n);
            vector<int> psum2(n);
            for (int i=0; i<n; i++) {
                if (time[i] != -1 && time[i] <= mid) flag2[i] = true;
            }
            if (flag2[0]) psum2[0] = 1;
            for (int i=1; i<n; i++) {
                psum2[i] = psum2[i-1] + flag2[i];
            }
            bool done = false;
            for (auto &[l, r]: segs) {
                int len = r - l + 1;
                int count = psum2[r];
                if (l) count -= psum2[l-1];
                if (count > len / 2) {
                    done = true;
                    break;
                }
            }
            // cout << a << ", " << mid << ", " << b << ", " << done << endl;
            if (done) {
                b = mid;
            } else {
                a = mid + 1;
            }
        }
        cout << a << endl;
    }
}