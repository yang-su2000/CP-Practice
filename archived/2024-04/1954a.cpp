#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, m, k;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        int lo = n / m;
        if (n % m) lo++;
        if (n - lo > k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}