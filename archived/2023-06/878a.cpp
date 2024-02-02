#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n, tmp;
    cin >> t;
    while (t--) {
        cin >> n;
        string s;
        cin >> s;
        string ans;
        char c = '/';
        for (int i=0; i<n; i++) {
            if (c == s[i]) {
                if (c != '/') ans += c;
                c = '/';
            } else if (c == '/') c = s[i];
        }
        cout << ans << endl;
    }
}