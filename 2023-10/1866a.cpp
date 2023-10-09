#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n <= 6 or n == 9) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            if (n % 3 == 0) cout << 1 << " " << 4 << " " << n - 5 << endl;
            else cout << 1 << " " << 2 << " " << n - 3 << endl;
        }
    }
}