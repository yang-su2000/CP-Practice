#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, m, k;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k >> s;
        vector<int> v;
        v.push_back(0);
        for (int i=0; i<n; i++) {
            if (s[i] == 'L') v.push_back(i+1);
        }
        v.push_back(n+1);
        int idx = 0;
        while (k >= 0 and idx < (int) v.size() - 1) {
            if (v[idx+1] - v[idx] <= m) {
                idx++;
                continue;
            }
            int i = v[idx] + m;
            bool flag = true;
            while (i < v[idx+1]) {
                if (s[i-1] == 'C') {
                    flag = false;
                    break;
                }
                k--;
                i++;
            }
            if (!flag or k < 0) break;
            idx++;
        }
        // cout << k << endl;
        if (k >= 0 and idx == (int) v.size() - 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}