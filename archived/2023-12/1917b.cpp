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
        set<char> st;
        for (char c: s) {
            st.insert(c);
            ans += (int) st.size();
        }
        cout << ans << endl;
    }
}