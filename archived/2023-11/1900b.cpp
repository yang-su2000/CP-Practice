#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        a %= 2;
        b %= 2;
        c %= 2;
        if (b == c) cout << 1;
        else cout << 0;
        cout << " ";
        if (a == c) cout << 1;
        else cout << 0;
        cout << " ";
        if (a == b) cout << 1;
        else cout << 0;
        cout << endl;
    }
}