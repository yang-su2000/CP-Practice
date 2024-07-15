#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int &x: a) cin >> x;
        int l = 0;
        while (l < n and !a[l]) l++;
        int r = n - 1;
        while (r >= 0 and !a[r]) r--;
        int ans = 0;
        for (int i=l; i<=r; i++) {
            if (!a[i]) ans++;
        }
        cout << ans << endl;
    }
}