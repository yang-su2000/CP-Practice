#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, m, h, val;
    cin >> t;
    while (t--) {
        cin >> n >> m >> h;
        priority_queue<tuple<int, ll, int>> pq;
        for (int i=1; i<=n; i++) {
            priority_queue<int, vector<int>, greater<>> cur;
            for (int j=0; j<m; j++) {
                cin >> val;
                cur.push(val);
            }
            int time = h;
            int taken = 0;
            int score = 0;
            ll penalty = 0;
            while (!cur.empty() && time - cur.top() >= 0) {
                taken += cur.top();
                penalty += taken;
                score++;
                time -= cur.top();
                cur.pop();
            }
            // cout << score << ", " << penalty << ", " << i << ", " << taken << endl;
            pq.push(make_tuple(score, -penalty, -i));
        }
        int rank = 1;
        while (1) {
            auto [score, penalty, i] = pq.top();
            if (i == -1) {
                cout << rank << endl;
                break;
            }
            pq.pop();
            rank++;
        }
    }
}