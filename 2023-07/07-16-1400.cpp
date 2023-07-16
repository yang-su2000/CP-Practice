#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    string s;
    t = 1;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        cin >> s;
        int l = -1;
        int r = -1;
        for (int i=0; i<n; i++) {
            if (s[i] == '1') {
                if (l == -1) {
                    l = i;
                    r = i;
                } else {
                    r = i;
                }
            } else {
                if (l != -1) sort(a.begin() + l, a.begin() + r + 2);
                l = -1, r = -1;
            }
        }
        if (l != -1) sort(a.begin() + l, a.begin() + r + 2);
        bool ans = true;
        for (int i=0; i<n-1; i++) {
            if (a[i] > a[i+1]) {
                ans = false;
                break;
            }
        }
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}