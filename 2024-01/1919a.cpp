#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    ll a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if ((a + b) % 2) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
}