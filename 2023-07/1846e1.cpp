#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int limit = 1e6;
    vector<bool> ans(limit+1);
    int i = 2;
    while (1) {
        ll cur = i * i;
        ll total = 1 + i + i * i;
        if (total > limit) break;
        while (total <= limit) {
            ans[total] = true;
            cur *= i;
            total += cur;
        }
        i++;
    }
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (ans[n]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}