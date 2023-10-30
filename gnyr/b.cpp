#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int r, f;
    cin >> r >> f;
    double d = 180 * f / r % 360;
    if (d < 90 || d > 270) cout << "up" << endl;
    else cout << "down" << endl;
}