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
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        int minval = INT_MAX;
        int pos = -1;
        for (int i=0; i<n; i++) {
            if (a[i] < minval) {
                minval = a[i];
                pos = i;
            }
        }
        bool valid = true;
        for (int i=pos+1; i<n; i++) {
            if (a[i] < a[i-1]) {
                valid = false;
                break;
            }
        }
        if (!valid) cout << -1 << endl;
        else cout << pos << endl;
    }
}