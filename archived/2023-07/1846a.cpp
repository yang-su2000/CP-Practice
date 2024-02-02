#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, a, b;
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0;
        for (int i=0; i<n; i++) {
            cin >> a >> b;
            if (a > b) ans++;
        }
        cout << ans << endl;
    }
}