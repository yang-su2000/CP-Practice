#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, val;
    cin >> t;
    while (t--) {
        cin >> n;
        ll sum = 0;
        while (n--) {
            cin >> val;
            sum += val;
        }
        ll base = sqrt(sum);
        if (base * base == sum) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}