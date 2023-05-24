#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t;
    long long x;
    cin >> t;
    while (t--) {
        cin >> x;
        if (x % 2) cout << -1 << endl;
        else {
            long long a = x / 2;
            long long b = a * 3;
            long long ans = (a ^ b);
            if (ans == x) cout << a << " " << b << endl;
            else cout << -1 << endl;
        }
    }
}