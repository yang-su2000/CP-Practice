#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int n;
    cin >> n;
    int idx = -1;
    vector<int> a(n-1);
    for (int i=0; i<n-1; i++) {
        cin >> a[i];
        if (a[i] >= n) idx = i;
    }
    if (idx == -1) {
        vector<int> b(n);
        for (int i=1; i<n; i++) b[i] = b[i-1] ^ a[i-1];
        for (int i=0; i<n; i++) cout << b[i] << " \n"[i == n-1];
        return 0;
    }
    vector<int> b(n);
    for (int s=idx-1; s<=idx+1; s++) {
        if (s < 0 or s >= n) continue;
        b[s] = n-1;
        for (int i=s-1; i>=0; i--) b[i] = b[i+1] ^ a[i];
        for (int i=s+1; i<n; i++) b[i] = b[i-1] ^ a[i-1];
        bool valid = true;
        vector<bool> f(n-1);
        for (int i=1; i<n; i++) {
            if (b[i] >= n or f[b[i]]) {
                valid = false;
                break;
            }
            f[b[i]] = true;
        }
        if (valid) {
            for (int i=0; i<n; i++) cout << b[i] << " \n"[i == n-1];
            return 0;
        }
    }
}