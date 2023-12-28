#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

// get minimium starting position where t in s
int kmp(vector<int>& s, vector<int>& t) {
    int n = s.size();
    int m = t.size();
    // for (int i=0; i<n; i++) cout << s[i] << " \n"[i == n-1];
    // for (int i=0; i<m; i++) cout << t[i] << " \n"[i == m-1];
    string ss = to_string(s[0]);
    for (int i=1; i<n; i++) {
        ss += " " + to_string(s[i]);
    }
    string tt = to_string(t[0]);
    for (int i=1; i<m; i++) {
        tt += " " + to_string(t[i]);
    }
    auto p = ss.find(tt);
    if (p == string::npos) {
        // cout << n << endl;
        return n;
    }
    int ans = 0;
    // cout << ss << ", " << tt << ", " << p << endl;
    for (int i=0; i<p; i++) {
        if (ss[i] == ' ') ans++;
    }
    // cout << ans << endl;
    return ans;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int &i: a) cin >> i;
        vector<int> b = a;
        sort(b.begin(), b.end());
        for (int i=0; i<n; i++) b.push_back(b[i]);
        vector<int> a2 = a;
        reverse(a2.begin(), a2.end());
        vector<int> b2 = b;
        reverse(b2.begin(), b2.end());
        int ans1 = kmp(b, a);
        int ans2 = kmp(b, a2) + 1;
        int ans3 = kmp(b2, a) + 1;
        int ans4 = kmp(b2, a2) + 2;
        // cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << endl;
        int ans = min(min(ans1, ans2), min(ans3, ans4));
        if (ans < n) cout << ans << endl;
        else cout << -1 << endl;
    }
}