#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long



int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i=0; i<n; i++) cin >> s[i];
    map<pair<int, int>, ll> m; // (digit len, digit sum) -> count
    for (int i=0; i<n; i++) {
        int len = (int) s[i].length();
        int sum = 0;
        for (char c: s[i]) sum += c - '0';
        m[make_pair(len, sum)]++;
    }
    ll ans = 0;
    for (int i=0; i<n; i++) {
        int len1 = (int) s[i].length();
        string s2 = s[i];
        reverse(s2.begin(), s2.end());
        // cout << s[i] << endl;
        for (int len2=len1-1; len2>=0; len2--) {
            int len = len1 + len2;
            if (len % 2) continue;
            int sum1 = 0;
            int sum2 = 0;
            for (int j=0; j<len/2; j++) sum1 += s[i][j] - '0';
            for (int j=len/2; j<len1; j++) sum2 += s[i][j] - '0';
            auto p = make_pair(len2, sum1 - sum2);
            if (m.count(p)) {
                // cout << len << " " << p.first << " " << p.second << "->" << m[p] << endl;
                ans += m[p];
            }
            int sum3 = 0;
            int sum4 = 0;
            for (int j=0; j<len/2; j++) sum3 += s2[j] - '0';
            for (int j=len/2; j<len1; j++) sum4 += s2[j] - '0';
            auto p2 = make_pair(len2, sum3 - sum4);
            if (m.count(p2)) {
                // cout << len << " " << p2.first << " " << p2.second << "->" << m[p2] << endl;
                ans += m[p2];
            }
        }
    }
    for (auto p: m) {
        ans += p.second * p.second;
    }
    cout << ans << endl;
}