#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(n);
        priority_queue<int> pq;
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        for (int i=0; i<n-1; i++) {
            pq.push(abs(a[i+1]-a[i]));
        }
        --k;
        while (k) {
            pq.pop();
            --k;
        }
        int ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        cout << ans << endl;
    }
}