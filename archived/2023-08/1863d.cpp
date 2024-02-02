#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<string> v(n);
        for (int i=0; i<n; i++) cin >> v[i];
        bool valid = true;
        for (int i=0; i<n; i++) {
            int count = 0;
            for (int j=0; j<m; j++) {
                if (v[i][j] != '.') count++;
            }
            if (count % 2) valid = false;
        }
        for (int j=0; j<m; j++) {
            int count = 0;
            for (int i=0; i<n; i++) {
                if (v[i][j] != '.') count++;
            }
            if (count % 2) valid = false;
        }
        if (!valid) {
            cout << -1 << endl;
            continue;
        }
        vector<int> u(n, -1);
        vector<int> l(m, -1);
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (v[i][j] == 'U') {
                    if (u[i] == -1) {
                        u[i] = j;
                    } else {
                        int j2 = u[i];
                        ans[i][j2] = 1;
                        ans[i+1][j2] = -1;
                        ans[i][j] = -1;
                        ans[i+1][j] = 1;
                        u[i] = -1;
                    }
                } else if (v[i][j] == 'L') {
                    if (l[j] == -1) {
                        l[j] = i;
                    } else {
                        int i2 = l[j];
                        ans[i2][j] = 1;
                        ans[i2][j+1] = -1;
                        ans[i][j] = -1;
                        ans[i][j+1] = 1;
                        l[j] = -1;
                    }
                }
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (ans[i][j] == 1) cout << 'W';
                else if (ans[i][j] == -1) cout << 'B';
                else cout << '.';
            }
            cout << endl;
        }
    }
}