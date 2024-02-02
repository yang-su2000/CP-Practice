#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int n, k, r;
    cin >> n >> k >> r;
    vector<bool> b(n);
    for (int i=0; i<k; i++) {
        int tmp;
        cin >> tmp;
        b[--tmp] = true;
    }
    vector<int> psum(n);
    psum[0] = b[0];
    for (int i=1; i<n; i++) {
        psum[i] = psum[i-1] + b[i];
    }
    // for (int i=0; i<n; i++) cout << psum[i] << " ";
    // cout << endl;
    int ans = 0;
    for (int i=r-1; i<n; i++) {
        psum[i] += ans;
        int cur = psum[i];
        if (i - r >= 0) cur -= psum[i-r];
        if (cur == 1) {
            ans++;
            if (b[i]) psum[i-1]++;
            psum[i]++;
        } else if (cur == 0) {
            ans += 2;
            psum[i-1]++;
            psum[i] += 2;
        }
    }
    // for (int i=0; i<n; i++) cout << psum[i] << " ";
    // cout << endl;
    cout << ans << endl;
}