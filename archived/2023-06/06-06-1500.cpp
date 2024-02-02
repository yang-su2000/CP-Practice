#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n, m, k;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        bool ans = false;
        ll n2 = 0, m2 = 0;
        vector<int> v(k);
        for (int i=0; i<k; i++) {
            cin >> v[i];
            if (v[i] / n >= m || v[i] / m >= n) ans = true;
        }
        if (ans) {
            cout << "Yes" << endl;
            continue;
        }
        bool nflag = true; // even or has >= 3 rows
        bool mflag = true; // even or has >= 3 cols
        if (n % 2) nflag = false;
        if (m % 2) mflag = false;
        for (int i=0; i<k; i++) {
            int n_ = v[i] / m;
            if (n_ >= 2) n2 += n_;
            if (n_ >= 3) nflag = true;
            if (n2 >= n && nflag) {
                ans = true;
                break;
            }
            int m_ = v[i] / n;
            if (m_ >= 2) m2 += m_;
            if (m_ >= 3) mflag = true;
            if (m2 >= m && mflag) {
                ans = true;
                break;
            }
        }
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}