#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        int l = 0, r = n - 1;
        for (int i=0; i<n; i++) {
            if (s[i] == '1') l = max(l, i);
            if (s[i] == '0') r = min(r, i);
        }
        cout << r - l + 1 << endl;
    }
}