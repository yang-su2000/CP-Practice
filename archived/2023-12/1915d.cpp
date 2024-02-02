#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    string s;
    set<char> v {'a', 'e'};
    cin >> t;
    while (t--) {
        cin >> n >> s;
        string s2;
        int i = 0;
        while (i < n) {
            if (i < n - 3 and v.count(s[i + 3])) {
                s2 += s.substr(i, 2);
                i += 2;
            } else {
                s2 += s.substr(i, 3);
                i += 3;
            }
            if (i < n) s2 += '.';
        }
        cout << s2 << endl;
    }
}