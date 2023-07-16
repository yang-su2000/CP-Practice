#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, m, start, limit;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> m >> s;
        limit = (1 << n);
        start = stoi(s, 0, 2);
        vector<int> cost(m);
        vector<int> a(m);
        vector<int> b(m);
        for (int i=0; i<m; i++) {
            cin >> cost[i];
            cin >> s;
            a[i] = stoi(s, 0, 2);
            cin >> s;
            b[i] = stoi(s, 0, 2);
        }
        vector<vector<pair<int, int>>> A(limit + 1);
        for (int node=0; node<=limit; node++) {
            for (int i=0; i<m; i++) {
                int child = (node & (~a[i])) | b[i];
                A[node].push_back({child, cost[i]});
            }
        }
        vector<int> d(limit + 1, INT_MAX);
        d[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, start});
        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();
            if (d[node] < dist) continue;
            for (auto [child, w]: A[node]) {
                int dist2 = dist + w;
                if (dist2 < d[child]) {
                    d[child] = dist2;
                    pq.push({dist2, child});
                }
            }
        }
        if (d[0] == INT_MAX) cout << -1 << endl;
        else cout << d[0] << endl;
    }
}