#include <bits/stdc++.h>
using namespace std;

#define ll long long

// g++ sample.cpp -o run
// ./run < input.txt

// class Union {
// public:
//     vector<int> p;
//     vector<int> s;

//     Union(int n) {
//         p.resize(n);
//         s.resize(n);
//         for (int i=0; i<n; i++) {
//             p[i] = i;
//             s[i] = 1;
//         }
//     }

//     int find(int i) {
//         if (i == p[i]) return i;
//         p[i] = find(p[i]);
//         return p[i];
//     }

//     void link(int i, int j) {
//         i = p[i], j = p[j];
//         p[i] = j;
//         s[j] += s[i];
//     }
// };

void bt(vector<bool>& flag, int n, int k, const vector<vector<int>>& v, int idx, ll& ans) {
    if (k == 0 or idx == (int) v.size()) {
        ll cur = 0ll;
        ll count = 0ll;
        for (int i=0; i<n; i++) {
            if (flag[i]) count++;
            else cur += count * (count + 1) / 2, count = 0;
        }
        cur += count * (count + 1) / 2;
        ans = max(ans, cur);
        return;
    }
    for (int i: v[idx]) flag[i] = true;
    bt(flag, n, k-1, v, idx+1, ans);
    for (int i: v[idx]) flag[i] = false;
    if (idx + k <= n) {
        bt(flag, n, k, v, idx+1, ans);
    }
}

int main() {
    int t, n, k, tmp;
    string a, b;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin >> a >> b;
        ll ans = 0ll;
        vector<bool> flag(n);
        map<char, vector<int>> m;
        for (int i=0; i<n; i++) {
            if (a[i] == b[i]) flag[i] = true;
            else m[a[i]].emplace_back(i);
        }
        vector<vector<int>> v;
        for (auto &p: m) {
            v.emplace_back(p.second);
            // cout << p.first << ":";
            // for (int i: p.second) cout << i << " ";
            // cout << endl;
        }
        bt(flag, n, k, v, 0, ans);
        cout << ans << endl;
    }
}