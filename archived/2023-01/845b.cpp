#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, n;
    long long ans;
    cin >> t;
    vector<long long> ls(1e5 + 1);
    vector<long long> ls2(1e5 + 1);
    ls[1] = 1;
    ls2[1] = 1;
    long long mod = 1e9 + 7;
    for (int i=2; i<=1e5; i++) {
        ls[i] = (ls[i-1] * i) % mod;
        ls2[i] = (ls2[i-1] + ls[i]) % mod;
        // cout << ls[i] << " " << ls2[i] << " ";
    }
    // cout << endl;
    while (t--) {
        cin >> n;
        ans = (((ls2[n-1] * n) % mod * (n - 1)) % mod + ((ls[n] * n) % mod * (n - 1) / 2) % mod) % mod;
        cout << ans << endl;
    }
}