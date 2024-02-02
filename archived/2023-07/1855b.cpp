#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    ll n;
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 1;
        for (ll i=2; i<=n; i++) {
            if (n % i == 0) ans++;
            else break;
        }
        cout << ans << endl;
    }
}