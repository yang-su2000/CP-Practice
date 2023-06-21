#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, tmp;
    cin >> t;
    while (t--) {
        cin >> n;
        ll sum = 0;
        ll ans = 0;
        bool pos = true;
        for (int i=0; i<n; i++) {
            cin >> tmp;
            sum += abs(tmp);
            if (pos) {
                if (tmp >= 0);
                else {
                    pos = false;
                    ans++;
                }
            } else {
                if (tmp > 0) {
                    pos = true;
                } else;
            }
        }
        cout << sum << " " << ans << endl;
        // vector<int> a;
        // for (int i=0; i<n; i++) {
        //     cin >> tmp;
        //     if (tmp) a.push_back(tmp);
        // }
        // for (int i: a) cout << i << ' ';
        // cout << endl;
        // ll sum = 0;
        // int pos = 0, neg = 0;
        // if (a.empty()) {
        //     cout << 0 << " " << 0 << endl;
        //     continue;
        // }
        // if (a[0] > 0) {
        //     pos = 0;
        //     neg = 1;
        // } else if (a[0] < 0) {
        //     pos = 1;
        //     neg = 0;
        // }
        // sum += abs(a[0]);
        // cout << pos << ' ' << neg << endl;
        // int pos2, neg2;
        // for (int i=1; i<(int) a.size(); i++) {
        //     if (a[i] > 0) {
        //         pos2 = min(pos, neg + 1);
        //         neg2 = min(pos + 1, neg + 1);
        //     } else if (a[i] < 0) {
        //         pos2 = min(neg + 1, pos + 1);
        //         neg2 = min(neg, pos + 1);
        //     }
        //     pos = pos2;
        //     neg = neg2;
        //     sum += abs(a[i]);
        //     cout << pos << ' ' << neg << endl;
        // }
        // cout << sum << " " << min(pos, neg + 1) << endl;
    }
}