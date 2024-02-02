#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, k;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin >> s;
        if (k % 2 == 0) {
            sort(s.begin(), s.end());
            cout << s << endl;
            continue;
        }
        string s1, s2;
        for (int i=0; i<n; i++) {
            if (i % 2 == 0) s1 += s[i];
            else s2 += s[i];
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        string ans;
        int i1 = 0, i2 = 0;
        for (int i=0; i<n; i++) {
            if (i % 2 == 0) ans += s1[i1++];
            else ans += s2[i2++];
        }
        cout << ans << endl;
    }
}