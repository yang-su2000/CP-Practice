#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int mc = 1;
        int cur = 1;
        for (int i=1; i<n; i++) {
            if (a[i] <= a[i-1] + k) cur++;
            else {
                mc = max(mc, cur);
                cur = 1;
            }
        }
        mc = max(mc, cur);
        cout << n - mc << endl;
    }
}