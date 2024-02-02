#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> b(n);
    vector<ll> p(m);
    set<ll> s;
    for (ll &x: b) cin >> x;
    for (ll &x: p) cin >> x;
    function<void(int, ll, ll)> dfs = [&](int count, ll a, ll b) {
        if (count == m) {
            if (a == b) s.insert(a + b);
            return;
        }
        dfs(count + 1, a, b);
        dfs(count + 1, a + p[count], b);
        dfs(count + 1, a, b + p[count]);
    };
    dfs(0, 0, 0);
    set<ll> s2;
    for (ll v1: b) {
        for (ll v2: s) s2.insert(v1 + v2);
    }
    for (ll v: s2) cout << v << endl;
}