#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

void foo(int n, vector<int>& ls) {
    vector<vector<int>> A(n);
    vector<bool> colored(n);
    int a, b;
    for (int i=0; i<n-1; i++) {
        cin >> a >> b;
        A[a-1].emplace_back(b-1);
        A[b-1].emplace_back(a-1);
    }
    vector<int> d(n, n);
    int ans = INT_MAX;
    for (int i=0; i<n; i++) {
        int cur = ls[i];
        ans = min(ans, d[cur]);
        if (i > 0) cout << ans << " \n"[i == n-1];
        queue<int> q;
        q.push(cur);
        d[cur] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int child: A[node]) {
                int dist = d[node] + 1;
                if (dist < min(ans, d[child])) { // !!!
                    d[child] = dist;
                    q.push(child);
                }
            }
        }
    }
}

int main() {
    int t, n, tmp;
    vector<int> ls;
    cin >> t;
    while (t--) {
        cin >> n;
        ls.resize(n);
        for (int i=0; i<n; i++) {
            cin >> tmp;
            ls[i] = tmp-1;
        }
        foo(n, ls);
    }
}