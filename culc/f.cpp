#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    vector<bool> one(n, true);
    for (int b=0; b<32; b++) {
        if (k & (1 << b)) {
            for (int i=0; i<n; i++) {
                if (!(a[i] & (1 << b))) one[i] = false;
            }
        }
    }
    vector<int> count1(n);
    for (int i=0; i<n; i++) {
        count1[i] = one[i];
        if (i > 0) count1[i] += count1[i-1];
    }
    vector<vector<int>> count0(n, vector<int>(32));
    for (int b=0; b<32; b++) {
        if (k & (1 << b)) continue;
        for (int i=0; i<n; i++) {
            count0[i][b] = (one[i] and (!(a[i] & (1 << b))));
            if (i > 0) count0[i][b] += count0[i-1][b];
        }
    }
    int l, r;
    while (q--) {
        cin >> l >> r;
        l--, r--;
        int c1 = count1[r];
        if (l > 0) c1 -= count1[l-1];
        if (c1 == 0) {
            cout << "NO" << endl;
            continue;
        }
        bool valid = true;
        for (int b=0; b<32; b++) {
            if (k & (1 << b)) continue;
            int c0 = count0[r][b];
            if (l > 0) c0 -= count0[l-1][b];
            if (c0 == 0) {
                valid = false;
                break;
            }
        }
        if (valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}