#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        int g = __gcd(a, b);
        if (g != 1) {
            cout << 2 << endl;
            cout << a - 1 << " " << 1 << endl;
            cout << a << " " << b << endl;
        } else {
            cout << 1 << endl;
            cout << a << " " << b << endl;
        }
    }
}