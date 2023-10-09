#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, a, b, c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        int ans = (abs(a - b) + 2 * c - 1) / (2 * c);
        cout << ans << endl;
    }
}