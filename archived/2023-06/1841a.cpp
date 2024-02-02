#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n <= 4) cout << "Bob" << endl;
        else cout << "Alice" << endl;
    }
}