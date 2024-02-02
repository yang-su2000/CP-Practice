#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, n, m, r, c, d1, d2, d3;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        // get top left
        cout << "? " << 1 << " " << 1 << endl;
        cin >> d1;
        // get row and col
        if (d1+1 <= n && d1+1 <= m) {
            cout << "? " << d1+1 << " " << 1 << endl;
            cin >> d2;
            cout << "? " << 1 << " " << d1+1 << endl;
            cin >> d3;
            if (d1 == d2) {
                // max(i, j) = j
                cout << "! " << d3+1 << " " << d1+1 << endl;
            } else if (d1 == d3) {
                // max(i, j) = i
                cout << "! " << d1+1 << " " << d2+1 << endl;
            } else {
                exit(1); // non-reachable
            }
        } else if (d1+1 <= n) {
            cout << "? " << d1+1 << " " << 1 << endl;
            cin >> d2;
            cout << "! " << d1+1 << " " << d2+1 << endl;
        } else if (d1+1 <= m) {
            cout << "? " << 1 << " " << d1+1 << endl;
            cin >> d3;
            cout << "! " << d3+1 << " " << d1+1 << endl;
        } else {
            exit(1); // non-reachable
        }
    }
}