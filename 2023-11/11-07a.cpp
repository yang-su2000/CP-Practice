#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> x(n), y(n);
        for (int i=0; i<n; i++) cin >> x[i] >> y[i];
        if (n % 2) {
            cout << 1 << endl;
            continue;
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        ll xc = x[n/2] - x[n/2-1] + 1;
        ll yc = y[n/2] - y[n/2-1] + 1;
        cout << xc * yc << endl;
    }
}