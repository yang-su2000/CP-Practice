#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

void print(int n) {
    for (int i=1; i<=n; i++) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        ll s = 0;
        for (ll i=1, j=1; i<=n; i++, j+=2) {
            s += i * j;
        }
        int m = 2 * n;
        cout << s << " " << m << endl;
        int row = n, col = n;
        for (int i=2*n-1; i>=0; i--) {
            if (i % 2) {
                cout << 1 << " " << row << " ";
                row--;
            } else {
                cout << 2 << " " << col << " ";
                col--;
            }
            print(n);
        }
    }
}