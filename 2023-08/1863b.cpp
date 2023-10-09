#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) cin >> v[i];
        vector<int> idxs(n);
        for (int i=0; i<n; i++) {
            idxs[v[i]-1] = i;
        }
        int ans = 0;
        for (int i=1; i<n; i++) {
            if (idxs[i] < idxs[i-1]) ans++;
        }
        cout << ans << endl;
    }
}