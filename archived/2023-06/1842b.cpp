#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n, x, tmp;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        int cur = 0;
        for (int i=0; i<3; i++) {
            bool valid = true;
            for (int j=0; j<n; j++) {
                cin >> tmp;
                if ((x & tmp) != tmp) valid = false;
                if (valid) cur |= tmp;
            }
        }
        if (cur == x) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}