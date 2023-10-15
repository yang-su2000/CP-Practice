#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int n;
    ll h;
    cin >> n >> h;
    vector<ll> a(n + 1);
    int remain = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i] > 0) remain++;
    }
    ll time = 0;
    int i = 0;
    h += a[1];
    if (a[1] > 0) remain--;
    h--;
    time++;
    i++;
    if (h == 0) {
        cout << "NO" << endl;
        return 0;
    }
    while (i < n && 0 < h && h < 1e9) {
        if (a[i+1] == 0) {
            h--;
            time++;
        } else if (remain >= 2) {
            if (h >= 2) {
                if (h % 2) {
                    time += h / 2 * 2;
                    h = 1;
                } else {
                    time += h - 2;
                    h = 2;
                }
            }
            h = a[i+1] + time;
            remain--;
            time++;
        } else {
            h += a[i+1] + time;
            remain--;
            h--;
            time++;
        }
        i++;
    }
    // cout << h << " ";
    if (0 < h) cout << "YES" << endl;
    else cout << "NO" << endl;
}