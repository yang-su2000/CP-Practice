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
        ll ans = 1;
        while (n > 1) {
            ans += n;
            n /= 2;
        }
        cout << ans << endl;
    }
}