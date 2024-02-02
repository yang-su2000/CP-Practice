#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        bool pos;
        vector<int> nidxs;
        vector<int> ans(n, 1);
        int val = 0;
        for (int i=0; i<n; i++) {
            char c = s[i];
            if (c == '(') val++;
            else val--;
            if (val < 0) pos = false;
            else if (val > 0) pos = true;
            if (!pos) {
                nidxs.push_back(i);
            }
        }
        if (val != 0) {
            cout << -1 << endl;
        } else {
            if (nidxs.size() == n) nidxs.clear();
            if (nidxs.empty()) cout << 1 << endl;
            else cout << 2 << endl;
            for (int i: nidxs) ans[i] = 2;
            for (int i=0; i<n; i++) {
                cout << ans[i] << " \n"[i == n-1];
            }
        }
    }
}