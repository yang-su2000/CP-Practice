#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<int, int>> v(n);
        for (int i=0; i<n; i++) cin >> v[i].first;
        for (int i=0; i<n; i++) cin >> v[i].second;
        sort(v.begin(), v.end());
        for (int i=0; i<n; i++) cout << v[i].first << " \n"[i == n-1];
        for (int i=0; i<n; i++) cout << v[i].second << " \n"[i == n-1];
    }
}