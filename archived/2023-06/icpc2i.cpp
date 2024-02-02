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
        vector<int> bcount(n); // bcount[b] gets all (b, d) pair at b
        for (int b=0; b<n; b++) {
            for (int d=b+1; d<n; d++) {
                if (v[b] > v[d]) bcount[b]++;
            }
        }
        ll ans = 0;
        for (int c=0; c<n; c++) {
            // get rid of all (b, d) pair that d == c in bcount[b]
            // since we go c from left to right, all pairs of (b, d) where d <= c are removed
            // now bcount[b] == all (b, d) pair at b and c < d
            int d = c;
            for (int b=0; b<d; b++) {
                if (v[b] > v[d]) bcount[b]--;
            }
            vector<int> bsum(n); // get a prefix sum of bcount
            bsum[0] = bcount[0];
            for (int b=1; b<n; b++) {
                bsum[b] = bsum[b-1] + bcount[b];
            }
            for (int a=0; a<c; a++) {
                // now for (a, c) pair, number of (b, d) pair is sum(bcount[a+1], ..., bcount[c-1])
                if (v[a] < v[c]) ans += bsum[c-1] - bsum[a];
            }
        }
        cout << ans << endl;
    }
}