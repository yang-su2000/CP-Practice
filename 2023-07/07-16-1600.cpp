#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        if (n % 2) {
            cout << -1 << endl;
            continue;
        }
        map<pair<char, char>, int> m; // (a, b) count
        map<char, int> m2; // (a, a) count
        for (int i=0; i<n/2; i++) {
            char c1 = s[i], c2 = s[n-i-1];
            if (c1 > c2) swap(c1, c2);
            if (c1 == c2) m2[c1]++;
            else m[{c1, c2}]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto p: m2) {
            pq.push({p.second, p.first});
        }
        int ans = 0;
        while (pq.size() >= 2) {
            auto [count1, c1] = pq.top();
            pq.pop();
            auto [count2, c2] = pq.top();
            pq.pop();
            // cout << "[" << count1 << ", " << c1 << "; " << count2 << ", " << c2 << "]" << endl;
            count1--;
            count2--;
            ans++;
            if (count1) pq.push({count1, c1});
            if (count2) pq.push({count2, c2});
            if (c1 > c2) swap(c1, c2);
            m[{c1, c2}] += 2;
        }
        if (pq.empty()) {
            cout << ans << endl;
            continue;
        }
        auto [count, c] = pq.top();
        // cout << count << ", " << c << ", " << ans << endl;
        // for (auto [p, count2]: m) cout << p.first << ", " << p.second << ": " << count2 << "; ";
        // cout << endl;
        for (auto [p, count2]: m) {
            if (count == 0) break;
            if (p.first == c || p.second == c) continue;
            if (count >= count2) {
                count -= count2;
                ans += count2;
            } else {
                ans += count;
                count = 0;
            }
        }
        if (count) cout << -1 << endl;
        else cout << ans << endl;
    }
}