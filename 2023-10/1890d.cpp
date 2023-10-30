#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int T, n;
    ll c;
    cin >> T;
    while (T--) {
        cin >> n >> c;
        vector<ll> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        for (int i=1; i<n; i++) pq.push(make_pair(c * (i + 1) - a[i], i));
        bool valid = true;
        ll sum = a[0];
        while (!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();
            if (sum >= val) sum += a[idx];
            else {
                valid = false;
                break;
            }
        }
        if (valid) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}