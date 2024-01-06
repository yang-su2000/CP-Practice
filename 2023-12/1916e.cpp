#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> p(n);
        vector<int> a(n);
        for (int i=1; i<n; i++) cin >> p[i];
        for (int i=0; i<n; i++) {
            cin >> a[i];
            a[i]--;
        }
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        vector<vector<int>> A(n);
        for (int i=1; i<n; i++) {
            int parent = p[i]-1;
            A[i].push_back(parent);
            A[parent].push_back(i);
        }
        vector<int> count(n);
        vector<int> ans(n);
        int diff = 0;
        ll maxval = 0;
        function<void(int, int)> dfs = [&](int node, int parent) {
            if (count[a[node]] == 0) diff++;
            count[a[node]]++;
            ans[node] = diff;
            priority_queue<int> pq;
            for (int child: A[node]) {
                if (child == parent) continue;
                dfs(child, node);
                pq.push(ans[child]);
            }
            if (count[a[node]] == 1) diff--;
            count[a[node]]--;
        };
        dfs(0, -1);
        cout << maxval << endl;
    }
}