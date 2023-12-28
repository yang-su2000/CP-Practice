#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, val;
    cin >> t;
    while (t--) {
        cin >> n;
        ll sum = 0;
        while (n--) {
            cin >> val;
            sum += val;
        }
        ll ans = 0;
        for (ll i=0; i<=sum; i++) {
            if (i * i == sum) {
                ans = i;
                break;
            } else if (i * i > sum) break;
        }
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}