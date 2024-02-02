#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        bool ans = true;
        for (int i=2, j=4; i<n; i*=2, j*=2) {
            for (int k=i+1; k<min(j, n); k++) {
                if (a[k-1] > a[k]) {
                    ans = false;
                    break;
                }
            }
        }
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}