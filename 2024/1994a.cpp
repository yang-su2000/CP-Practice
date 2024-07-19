#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, m, tmp;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (n == 1 and m == 1) {
            cin >> tmp;
            cout << -1 << endl;
            continue;
        }
        vector<int> a(n * m), b(n * m);
        for (int i = 0; i < n * m; i++) {
            cin >> a[i];
        }
        b[0] = a[n * m - 1];
        for (int i = 1; i < n * m; i++) {
            b[i] = a[i - 1];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << b[i * m + j] << " ";
            }
            cout << endl;
        }
    }
}