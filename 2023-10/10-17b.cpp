#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> b(n);
        for (int i=0; i<n; i++) cin >> b[i];
        int count = 0;
        int ans = 0;
        int cur = 0;
        for (int i=0; i<n; i++) {
            if (b[i] == 1) {
                count++;
                cur++;
                ans = max(ans, cur);
            } else {
                cur = (count - 1 + 1) / 2;
                if (count > 0) cur++;
                ans = max(ans, cur);
            }
        }
        cout << ans << endl;
    }
}