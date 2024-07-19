#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

class Union {
public:
    vector<int> p, size;
    Union(int n) {
        p.resize(n);
        size.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    void link(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (size[x] < size[y]) {
                p[x] = y;
                size[y] += size[x];
            } else {
                p[y] = x;
                size[x] += size[y];
            }
        }
    }
};

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Union u(n);
        vector<pair<int, int>> ops(n);
        for (int op = n - 1; op >= 1; op--) {
            vector<int> remainder(op, -1);
            for (int i = 0; i < n; i++) {
                int r = a[i] % op;
                if (remainder[r] == -1) {
                    remainder[r] = i;
                    continue;
                }
                int j = remainder[r];
                if (u.find(i) != u.find(j)) {
                    u.link(i, j);
                    ops[op] = make_pair(i, j);
                    break;
                }
            }
        }
        cout << "YES" << endl;
        for (int i = 1; i < n; i++) {
            cout << ops[i].first + 1 << " " << ops[i].second + 1 << endl;
        }
    }
}