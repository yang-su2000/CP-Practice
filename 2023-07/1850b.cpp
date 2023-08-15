#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), b(n);
        for (int i=0; i<n; i++) {
            cin >> a[i] >> b[i];
        }
        int quality = 0;
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (a[i] <= 10) {
                if (b[i] > quality) {
                    quality = b[i];
                    ans = i + 1;
                }
            }
        }
        cout << ans << endl;
    }
}