#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, val;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> vis(n);
        list<pair<int, int>> a;
        int maxval = 0;
        for (int i=0; i<n; i++) {
            cin >> val;
            a.push_back(make_pair(val, i));
            maxval = max(maxval, val);
        }
        vector<queue<pair<list<pair<int, int>>::iterator, int>>> v(maxval + 1);
        function<bool(list<pair<int, int>>::iterator, bool)> update = [&](list<pair<int, int>>::iterator it, bool is_erase) {
            int mid = it->first;
            int l = -2, r = -2;
            if (it != a.begin()) l = prev(it)->first;
            if (next(it) != a.end()) r = next(it)->first;
            if (l + 1 == mid or mid - 1 == r) {
                auto it_r = next(it);
                if (is_erase) {
                    vis[it->second] = true;
                    a.erase(it);
                    if (l - 1 == r) v[l].push(make_pair(prev(it_r), prev(it_r)->second));
                    else if (l + 1 == r) v[r].push(make_pair(it_r, it_r->second));
                } else {
                    v[mid].push(make_pair(it, it->second));
                }
                return true;
            }
            return false;
        };
        // init
        for (auto it = a.begin(); it != a.end(); it++) {
            int val = it->first;
            update(it, false);
        }
        // update
        bool ans = true;
        for (int i=maxval; i>=1; i--) {
            // for (auto it: a) cout << it.first << " ";
            // cout << endl;
            while (!v[i].empty()) {
                auto [it, idx] = v[i].front();
                v[i].pop();
                if (vis[idx]) continue;
                if (!update(it, true)) {
                    ans = false;
                    break;
                }
            }
            if (!ans) break;
        }
        if (ans and a.size() == 1 and a.begin()->first == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}