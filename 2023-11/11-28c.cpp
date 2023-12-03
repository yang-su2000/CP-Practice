#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int &i: a) cin >> i;
        sort(a.begin(), a.end());
        vector<int> d;
        d.push_back(a.front() - 1 + n - a.back());
        // cout << d.front() << " ";
        for (int i=1; i<m; i++) d.push_back(a[i] - a[i-1] - 1);
        sort(d.begin(), d.end());
        int good = 0;
        int n2 = d.size();
        int day = 0;
        for (int i=n2-1; i>=0; i--) {
            d[i] -= day;
            if (d[i] <= 0) break;
            good++;
            d[i] -= 2;
            day += 2;
            if (d[i] <= 0) continue;
            good += d[i];
            day += 2;
        }
        cout << n - good << endl;
    }
}