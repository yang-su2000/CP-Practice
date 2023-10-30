#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int T, n;
    string s;
    cin >> T;
    while (T--) {
        cin >> n >> s;
        if (n % 2) {
            cout << -1 << endl;
            continue;
        }
        vector<int> ans;
        bool valid = true;
        bool done = false;
        while (valid && !done && (int) ans.size() <= 300) {
            done = true;
            n = (int) s.length();
            int l = 0, r = n - 1;
            while (l < r) {
                if (s[l] != s[r]) {
                    l++, r--;
                } else if (s[l] == '0') {
                    s = s.substr(0, r + 1) + "01" + s.substr(r + 1);
                    done = false;
                    ans.push_back(r + 1);
                    break;
                } else if (s[l] == '1') {
                    s = s.substr(0, l) + "01" + s.substr(l);
                    done = false;
                    ans.push_back(l);
                    break;
                }
            }
            // cout << s << endl;
        }
        int p = (int) ans.size();
        if (!valid || p > 300) {
            cout << -1 << endl;
            continue;
        }
        cout << p << endl;
        for (int i=0; i<p; i++) cout << ans[i] << " \n"[i == p-1];
    }
}