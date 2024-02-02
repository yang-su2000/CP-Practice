#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int a, b;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        while (n--) {
            cin >> a >> b;
            b = -b;
            pq.push({a, b});
        }
        ll ans = 0;
        deque<int> d;
        while (!pq.empty()) {
            auto [a, b] = pq.top();
            // cout << a << " " << b << ", ";
            pq.pop();
            ans -= b;
            d.push_back(a);
            int count = d.size();
            while (!d.empty() and d.front() <= count) d.pop_front();
            while (!pq.empty() and pq.top().first <= count) {
                pq.pop();
            }
        }
        cout << ans << endl;
    }
}