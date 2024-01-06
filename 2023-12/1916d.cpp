#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 1) {
            cout << 1 << endl;
            continue;
        } else if (n == 3) {
            cout << 169 << endl;
            cout << 196 << endl;
            cout << 961 << endl;
            continue;
        }
        int len = n/2;
        for (int i=0; i<len; i++) {
            int j = len-i-1;
            cout << "1" << string(j, '0') << "6" << string(j, '0') << "9" << string(i * 2, '0') << endl;
        }
        cout << "196" << string(n-3, '0') << endl;
        for (int i=0; i<len; i++) {
            int j = len-i-1;
            cout << "9" << string(j, '0') << "6" << string(j, '0') << "1" << string(i * 2, '0') << endl;
        }
        // map<string, vector<string>> m;
        // for (ll i=0; i<100000; i++) {
        //     string s = to_string(i * i);
        //     // cout << s << " ";
        //     if (s.length() == n) {
        //         string s2 = s;
        //         sort(s2.begin(), s2.end());
        //         m[s2].push_back(s);
        //     }
        // }
        // for (auto [s, ss]: m) {
        //     if ((int) ss.size() >= n) {
        //         cout << s << ": ";
        //         for (string s2: ss) cout << s2 << " ";
        //         cout << endl;
        //     }
        // }
        // cout << endl;
    }
}