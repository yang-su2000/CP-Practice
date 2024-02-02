#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

#define ll long long

int main() {
    vector<ll> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    if (v[0] + v[1] < v[2] / 2) {
        cout << v[0] + v[1] << endl;
        return 0;
    }
    if ((v[0] + v[1] + v[2]) % 3) {
        v[2]--;
    }
    sort(v.begin(), v.end());
    if ((v[0] + v[1] + v[2]) % 3) {
        v[2]--;
    }
    sort(v.begin(), v.end());
    // cout << v[0] << " " << v[1] << " " << v[2] << endl;
    ll asum = (v[1] + v[2] + 4 * v[0]) / 3 - v[0];
    cout << asum << endl;
}