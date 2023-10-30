#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n), b(m);
    for (int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i=0; i<m; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<vector<int>> v(m);
    bool valid = false;
    int ai = 0, bi = 0;
    while (ai < n && bi < m) {
        int target = b[bi].first;
        int lo = a[ai].first;
        int count = 0;
        valid = false;
        while (ai < n) {
            count++;
            ai++;
            if (lo >= target / count) {
                valid = true;
                break;
            }
        }
        if (!valid) break;
        int idx = b[bi].second;
        for (int i=count; i>0; i--) {
            v[idx].push_back(a[ai-i].second);
        }
        bi++;
    }
    if (!valid || bi < m) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (int i=0; i<m; i++) {
            int s = (int) v[i].size();
            cout << s << " ";
            for (int j=0; j<s; j++) {
                cout << v[i][j] + 1 << " \n"[j == s-1];
            }
        }
    }
}