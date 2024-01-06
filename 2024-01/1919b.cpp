#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int ans = 0;
        for (char c: s) {
            if (c == '+') ans++;
            else ans--;
        }
        cout << abs(ans) << endl;
    }
}