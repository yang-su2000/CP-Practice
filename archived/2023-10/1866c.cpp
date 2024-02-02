#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    string s;
    ll p;
    cin >> t;
    while (t--) {
        cin >> s >> p;
        p--;
        int n = (int) s.length();
        int l = -1, r = n-1;
        while (l < r) {
            int mid = l + (r - l) / 2 + 1;
            ll sum = ((ll) n + n - mid) * (mid + 1) / 2;
            if (sum <= p) l = mid;
            else r = mid - 1;
        }
        // if (p >= n) p -= (n + n - l) * (l + 1) / 2;
        // else l = -1;
        p -= ((ll) n + n - l) * (l + 1) / 2;
        // cout << l << ", " << p << ": ";
        stack<pair<char, int>> st;
        vector<int> v(n);
        int count = 0;
        for (int i=0; i<n; i++) {
            while (!st.empty() && st.top().first > s[i]) {
                v[st.top().second] = count++;
                st.pop();
            }
            st.push(make_pair(s[i], i));
        }
        while (!st.empty()) {
            v[st.top().second] = count++;
            st.pop();
        }
        // for (int i=0; i<n; i++) cout << v[i] << " ";
        // cout << endl;
        string s2;
        for (int i=0; i<n; i++) {
            if (v[i] > l) s2 += s[i];
        }
        // cout << s2 << endl;
        cout << s2[p];
    }
}