#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v(n);
        vector<unordered_map<int, int>> vm(n); // v[idx]: sum -> min_ops
        for (int i=0; i<n; i++) cin >> v[i];
        for (int i=0; i<n; i++) {
            int csum = 0;
            for (int j=i; j>=0; j--) {
                csum += v[j];
                if (j>=1 && vm[j-1].count(csum)) vm[i][csum] = i-j + vm[j-1][csum];
            }
            vm[i][csum] = i;
            // cout << i << ": ";
            // for (auto [sum, min_ops]: vm[i]) {
            //     cout << "[" << sum << ", " << min_ops << "] ";
            // }
            // cout << endl;
        }
        int ans = n-1;
        for (auto [sum, min_ops]: vm[n-1]) {
            ans = min(ans, min_ops);
        }
        cout << ans << endl;
    }
}