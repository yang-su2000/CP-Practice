#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

#define ll long long

int main() {
    int t, n, tmp;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> ls(n);
        ll odd = 0, even = 0;
        for (int i=0; i<n; i++) {
            cin >> ls[i];
            if (i % 2) odd += ls[i];
            else even += ls[i];
        }
        if (odd < even) {
            for (int i=0; i<n; i++) {
                if (i % 2) cout << 1;
                else cout << ls[i];
                cout << " \n"[i == n - 1];
            }
        } else {
            for (int i=0; i<n; i++) {
                if (i % 2 == 0) cout << 1;
                else cout << ls[i];
                cout << " \n"[i == n - 1];
            }
        }
    }
}