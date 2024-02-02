#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        string s;
        char c = 'a';
        while (k) {
            s += c;
            c++;
            k--;
        }
        string ans;
        while (n) {
            ans += s;
            n--;
        }
        cout << ans << endl;
    }
}