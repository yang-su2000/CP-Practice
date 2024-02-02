#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int T, n, m;
    string s, t;
    cin >> T;
    while (T--) {
        cin >> n >> m >> s >> t;
        bool need0 = false, need1 = false;
        for (int i=1; i<n; i++) {
            if (s[i-1] == s[i]) {
                if (s[i] == '0') need1 = true;
                else need0 = true;
            }
        }
        bool tgood = true;
        int has = -1;
        for (int i=1; i<m; i++) {
            if (t[i-1] == t[i]) {
                tgood = false;
                break;
            }
        }
        if (tgood && t[0] == t[m-1]) {
            if (t[0] == '1') has = 1;
            else has = 0;
        }
        if (!need0 && !need1) {
            cout << "Yes" << endl;
        } else if (need0 && !need1 && has == 0) {
            cout << "Yes" << endl;
        } else if (!need0 && need1 && has == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}