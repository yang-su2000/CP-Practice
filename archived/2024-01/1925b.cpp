#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, x, n;
    cin >> t;
    while (t--) {
        cin >> x >> n;
        vector<int> f;
        for (int i=1; i*i<=x; i++) {
            if (x % i == 0) {
                f.push_back(i);
                f.push_back(x / i);
            }
        }
        sort(f.begin(), f.end());
        int ans = 0;
        for (int val: f) {
            if (val >= n) {
                ans = x / val;
                break;
            }
        }
        cout << ans << endl;
    }
}