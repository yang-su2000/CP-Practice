#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, val;
    cin >> t;
    while (t--) {
        cin >> n;
        int count = 0;
        for (int i=1; i<=n; i++) {
            cin >> val;
            if (val == i) count++;
        }
        cout << (count + 1) / 2 << endl;
    }
}