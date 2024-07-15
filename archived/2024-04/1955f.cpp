#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> v(4);
        for (int i=0; i<4; i++) cin >> v[i];
        int ans = 0;
        if (v[0] % 2 and v[1] % 2 and v[2] % 2) ans++;
        for (int i=0; i<4; i++) {
            ans += v[i] / 2;
        }
        cout << ans << endl;
    }
}