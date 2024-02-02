#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> c(n);
        for (int i=0; i<n; i++) cin >> c[i];
        if (c[0] == c[n-1]) {
            int count = 0;
            for (int i=0; i<n; i++) {
                if (c[i] == c[0]) count++;
            }
            if (count >= k) cout << "Yes" << endl;
            else cout << "No" << endl;
            continue;
        }
        if (k == 1) {
            cout << "Yes" << endl;
            continue;
        }
        int count0 = 0, count1 = 0;
        for (int i=0; i<n; i++) {
            if (c[i] == c[n-1]) count1++;
        }
        bool ans = false;
        for (int i=0; i<n; i++) {
            if (c[i] == c[0]) count0++;
            if (c[i] == c[n-1]) count1--;
            if (min(count0, count1) >= k) {
                ans = true;
                break;
            }
        }
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}