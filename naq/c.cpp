#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, double>> v(n); // future, quantity
    int f;
    double q;
    for (int i=0; i<n; i++) {
        scanf("%lf%d", &v[i].second, &v[i].first);
    }
    double l = 0.0, r = 0.0;
    for (int i=0; i<n; i++) r = max(r, v[i].second / k);
    double eps = 1e-9;
    bool global = false;
    while (l + eps <= r) {
        double mid = l + (r - l) / 2;
        priority_queue<pair<int, double>, vector<pair<int, double>>, greater<>> pq; // future, quantity
        bool valid = true;
        for (int i=0; i<n; i++) {
            f = v[i].first + i - 1, q = v[i].second;
            pq.push(make_pair(f, q));
            // cout << i << " " << f << " " << q << endl;
            while (!pq.empty() && pq.top().first < i) pq.pop();
            double target = mid * k;
            while (!pq.empty() && abs(target) >= eps) {
                f = pq.top().first;
                q = pq.top().second;
                pq.pop();
                if (q <= target) {
                    target -= q;
                } else {
                    q -= target;
                    target = 0;
                    pq.push(make_pair(f, q));
                    break;
                }
            }
            if (abs(target) >= eps) {
                valid = false;
                break;
            }
        }
        if (valid) {
            global = true;
            l = mid;
        } else r = mid;
    }
    if (global) printf("%.9f\n", l);
    else cout << -1 << endl;
}