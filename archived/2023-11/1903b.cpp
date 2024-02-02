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
        vector<vector<int>> M(n, vector<int>(n));
        for (int i=0; i<n; i++) {
            for (int &j: M[i]) cin >> j;
        }
        vector<int> ans(n, (1 << 30) - 1);
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int b=0; b<30; b++) {
                    if ((M[i][j] >> b) & 1) continue;
                    ans[i] &= ~(1 << b);
                    ans[j] &= ~(1 << b);
                }
            }
        }
        bool valid = true;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if ((ans[i] | ans[j]) != M[i][j]) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }
        if (valid) {
            cout << "YES" << endl;
            for (int i=0; i<n; i++) cout << ans[i] << " \n"[i == n-1];
        } else cout << "NO" << endl;
    }
}