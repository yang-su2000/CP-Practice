#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        map<ll, int> m;
        for (int i: a) m[i]++;
        int ans = 0;
        for (auto p: m) {
            while (p.second > 0 and m[p.first * x] > 0) {
                p.second--;
                m[p.first * x]--;
            }
            ans += p.second;
        }
        cout << ans << endl;
    }
}