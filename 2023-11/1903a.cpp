#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        bool sorted = true;
        vector<int> a(n);
        for (int &i: a) cin >> i;
        for (int i=1; i<n; i++) {
            if (a[i-1] > a[i]) sorted = false;
        }
        if (sorted or k > 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}