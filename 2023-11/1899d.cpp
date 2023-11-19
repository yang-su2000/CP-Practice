#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        map<int, int> m;
        ll ans = 0;
        for (int i=0; i<n; i++) {
            if (a[i] == 1) ans += m[2];
            if (a[i] == 2) ans += m[1];
            ans += m[a[i]];
            m[a[i]]++;
        }
        cout << ans << endl;
    }
}