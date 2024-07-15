#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int &i: a) cin >> i;
        vector<bool> v(n);
        int ans = 0;
        for (int i: a) {
            i--;
            if (v[i]) ans++;
            v[i] = true;
        }
        cout << ans << endl;
    }
}