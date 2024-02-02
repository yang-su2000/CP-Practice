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
        set<ll> s;
        s.insert(0);
        bool ans = false;
        bool odd = true;
        ll sum = 0;
        for (ll &x: a) {
            if (odd) sum += x;
            else sum -= x;
            if (s.count(sum)) {
                ans = true;
                break;
            }
            s.insert(sum);
            odd = !odd;
        }
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}