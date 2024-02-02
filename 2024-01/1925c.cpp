#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, k, m;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> k >> m >> s;
        set<char> st;
        string ans;
        for (char c: s) {
            st.insert(c);
            if ((int) st.size() == k) {
                st.clear();
                ans += c;
                if (ans.length() == n) break;
            }
        }
        if (ans.length() == n) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
        for (char c='a'; c<'a' + k; c++) {
            if (!st.count(c)) {
                ans += c;
                break;
            }
        }
        while (ans.length() < n) ans += 'a';
        cout << ans << endl;
    }
}