#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int foo(int n, int m, vector<int>& a, vector<int>& c) {
    vector<int> t(n);
    for (int i: a) t[i-1]++;
    priority_queue<int> pq;
    for (int i: t) {
        if (i > 0) pq.push(i);
    }
    priority_queue<int> pc;
    for (int i: c) pc.push(i);
    int ans = 0;
    while (!pc.empty() and !pq.empty()) {
        int cap = pc.top();
        pc.pop();
        int ppl = pq.top();
        pq.pop();
        if (ppl <= cap) ans += ppl;
        else ans += cap, pq.push(ppl - cap);
    }
    return ans;
}

int main() {
    int t, m, n, tmp;
    vector<int> a, c;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        a.resize(n);
        c.resize(m);
        for (int i=0; i<n; i++) {
            cin >> tmp;
            a[i] = tmp;
        }
        for (int i=0; i<m; i++) {
            cin >> tmp;
            c[i] = tmp;
        }
        cout << foo(n, m, a, c) << endl;
    }
}