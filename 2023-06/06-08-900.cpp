#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for (int i=0; i<n/2; i++) {
            for (int j=0; j<m/2; j++) {
                int flag = i + j;
                if (flag % 2) {
                    v[i*2][j*2] = 1;
                    v[i*2+1][j*2+1] = 1;
                } else {
                    v[i*2][j*2+1] = 1;
                    v[i*2+1][j*2] = 1;
                }
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cout << v[i][j] << " \n"[j == m-1];
            }
        }
    }
}