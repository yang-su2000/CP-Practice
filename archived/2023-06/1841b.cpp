#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n, tmp;
    cin >> t;
    while (t--) {
        cin >> n;
        int cstart = 0;
        int cmax = 0;
        int cmin = 0;
        bool ismax = false;
        bool ismin = false;
        for (int i=0; i<n; i++) {
            cin >> tmp;
            if (!ismax) {
                cstart = tmp;
                cmax = tmp;
                ismax = true;
                cout << 1;
            } else if (!ismin) {
                if (tmp >= cmax) {
                    cmax = tmp;
                    cout << 1;
                } else if (tmp > cstart) {
                    cout << 0;
                } else {
                    ismin = true;
                    cmin = tmp;
                    cout << 1;
                }
            } else {
                if (cmin <= tmp && tmp <= cstart) {
                    cmin = tmp;
                    cout << 1;
                } else {
                    cout << 0;
                }
            }
        }
        cout << endl;
    }
}