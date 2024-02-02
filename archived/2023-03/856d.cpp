#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int n, tmp;
    cin >> n;
    map<int, int> m;
    for (int i=0; i<2*n; i++) {
        cin >> tmp;
        m[tmp]++;
    }
    int f = m.rbegin()->first + 1;
    if (f < 2) {
        cout << 0 << endl;
        exit(0);
    }
    vector<bool> is_prime(f, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= f; i++) {
        if (is_prime[i] && (long long) i * i <= f) {
            for (int j = i * i; j <= f; j += i)
                is_prime[j] = false;
        }
    }
    int bcount = 0;
    for (auto &p: m) {
        if (is_prime[p.first]) bcount++;
    }
    cout << bcount << endl;
    if (bcount < n) {
        cout << 0 << endl;
        exit(0);
    }
    int mod = 998244353;
    long long ans = 1; // bcount! - choose(bcount, n) * sum(# same - 1)
    for (int i=bcount; i>1; i--) {
        ans = (ans * i) % mod;
    }
    cout << ans << endl;
    for (auto &p: m) {
        int count = p.second - 1;
        long long to_reduce = 1;
        for (int i=n; count>0; i--, count--) {
            to_reduce = (to_reduce * i) % mod;
        }
        ans = (ans - to_reduce) % mod;
    }
    cout << ans << endl;
}