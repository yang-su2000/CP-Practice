#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n, tmp;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> tmp;
            cout << n + 1 - tmp << " \n"[i == n-1];
        }
    }
}