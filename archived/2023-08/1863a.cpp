#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, a, q;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> a >> q;
        int cur = a;
        int sum = a;
        cin >> s;
        if (a >= n) {
            cout << "YES" << endl;
            continue;
        }
        bool done = false;
        for (char c: s) {
            if (c == '+') {
                cur++;
                sum++;
            } else {
                cur--;
            }
            if (cur >= n) {
                done = true;
                break;
            }
        }
        // cout << n << " " << a << " " << cur << " " << sum << endl;
        if (done) {
            cout << "YES" << endl;
        } else if (sum >= n) {
            cout << "MAYBE" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}