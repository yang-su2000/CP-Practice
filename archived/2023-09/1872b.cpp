#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, d, s;
    cin >> t;
    while (t--) {
        cin >> n;
        int target = INT_MAX;
        for (int i=0; i<n; i++) {
            cin >> d >> s;
            target = min(target, 2 * d + s - 1);
        }
        int k = target / 2;
        cout << k << endl;
    }
}