#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, a, b, c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        int x = (c + 1) / 2;
        int y = c - x;
        if (a + x > b + y) cout << "First" << endl;
        else cout << "Second" << endl;
    }
}