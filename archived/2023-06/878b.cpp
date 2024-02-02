#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int i = 0;
        int n2 = n;
        while (n) {
            n >>= 1;
            i++;
        }
        // cout << "[" << i << ", " << n2 << ", " << k << "] ";
        if (i > k) {
            cout << (int) pow(2, k) << endl;
        } else {
            cout << n2 + 1 << endl;
        }
    }
}