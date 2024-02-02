#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int l = n + m - 2;
        if (l > k or (k - l) % 2) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        vector<vector<bool>> x(n, vector<bool>(m-1));
        vector<vector<bool>> y(n-1, vector<bool>(m));
        bool flag = true;
        for (int i=0; i<m-1; i++) {
            x[0][i] = flag;
            flag = !flag;
        }
        for (int i=0; i<n-1; i++) {
            y[i][m-1] = flag;
            flag = !flag;
        }
        x[1][0] = true;
        if (y[n-3][m-1]) {
            y[n-2][m-2] = true;
        } else {
            x[n-2][m-2] = true;
            x[n-1][m-2] = true;
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m-1; j++) {
                cout << "BR"[x[i][j]];
                cout << " \n"[j == m-2];
            }
        }
        for (int i=0; i<n-1; i++) {
            for (int j=0; j<m; j++) {
                cout << "BR"[y[i][j]];
                cout << " \n"[j == m-1];
            }
        }
    }
}