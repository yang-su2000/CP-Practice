#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int &x: a) cin >> x;
        int lo = INT_MAX, hi = INT_MAX;
        int ans = 0;
        for (int x: a) {
            if (lo > hi) swap(lo, hi);
            if (x <= lo) lo = x;
            else if (x <= hi) hi = x;
            else {lo = x, ans++;}
        }
        cout << ans << endl;
    }
}