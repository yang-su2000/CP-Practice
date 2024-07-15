#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

// turn [a_offset, ..., a_offset+mex-1] with [0, ..., 0] to [1, ..., mex]
int construct(int offset, int mex, bool is_print) {
    if (mex == 1) {
        if (is_print) cout << offset << " " << offset << endl;
        return 1;
    }
    int count = construct(offset, mex - 1, is_print);
    if (is_print) cout << offset << " " << offset + mex - 1 << endl; // now [mex, ..., mex]
    count++;
    if (is_print) cout << offset << " " << offset + mex - 2 << endl; // now [0, ..., 0, mex]
    count++;
    count += construct(offset, mex - 1, is_print);
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    vector<pair<int, int>> max_v;
    int max_sum = 0;
    for (int i=0; i<(1 << n); i++) {
        if (((i >> (n - 1)) & 1) == 0) continue;
        vector<pair<int, int>> v;
        int sum = 0;
        int cur = 0;
        int l = 0;
        for (int b=0; b<n; b++) {
            cur += a[b];
            l++;
            if ((i >> b) & 1) {
                if (l * l > cur) {
                    v.push_back(make_pair(b - l + 1, b));
                }
                sum += max(l * l, cur);
                cur = 0;
                l = 0;
            }
        }
        if (sum > max_sum) {
            max_sum = sum;
            max_v = v;
        }
    }
    // debug
    // for (auto [l, r]: max_v) cout << l << " " << r << endl;
    // cout << max_sum << endl;
    int ops = 0;
    for (auto [l, r]: max_v) {
        for (int i=l; i<=r; i++) {
            if (a[i] != 0) {
                ops++;
            }
        }
        l++, r++;
        if (l == r) {
            ops += construct(l, 1, false);
        } else {
            ops += construct(l, r - l, false);
            ops++;
        }
    }
    cout << max_sum << " " << ops << endl;
    for (auto [l, r]: max_v) {
        for (int i=l; i<=r; i++) {
            if (a[i] != 0) {
                cout << i + 1 << " " << i + 1 << endl;
            }
        }
        l++, r++;
        if (l == r) {
            construct(l, 1, true);
        } else {
            construct(l, r - l, true);
            cout << l << " " << r << endl;
        }
    }
}