#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int T, t, q, qtype;
    cin >> T;
    while (T--) {
        string s[2];
        cin >> s[0] >> s[1];
        cin >> t >> q;
        int n = s[0].size();
        queue<pair<int, int>> qt; // query 1 block pos, ending time (index)
        vector<bool> st(n); // unmatched indexes
        int count = 0;
        for (int i=0; i<n; i++) {
            if (s[0][i] != s[1][i]) {
                st[i] = true;
                count++;
            }
        }
        for (int i=0; i<q; i++) {
            cin >> qtype;
            if (qtype == 1) {
                int pos;
                cin >> pos;
                pos--;
                if (st[pos]) {
                    st[pos] = false;
                    count--;
                }
                qt.push({pos, i + t});
            } else if (qtype == 2) {
                int p[2], pos[2];
                cin >> p[0] >> pos[0] >> p[1] >> pos[1];
                p[0]--, p[1]--;
                pos[0]--, pos[1]--;
                swap(s[p[0]][pos[0]], s[p[1]][pos[1]]);
                if (s[0][pos[0]] != s[1][pos[0]] && !st[pos[0]]) {
                    st[pos[0]] = true;
                    count++;
                }
                else if (s[0][pos[0]] == s[1][pos[0]] && st[pos[0]]) {
                    st[pos[0]] = false;
                    count--;
                }
                if (s[0][pos[1]] != s[1][pos[1]] && !st[pos[1]]) {
                    st[pos[1]] = true;
                    count++;
                }
                else if (s[0][pos[1]] == s[1][pos[1]] && st[pos[1]]) {
                    st[pos[1]] = false;
                    count--;
                }
            } else if (qtype == 3) {
                while (!qt.empty() && qt.front().second <= i) {
                    int pos = qt.front().first;
                    qt.pop();
                    if (s[0][pos] != s[1][pos] && !st[pos]) {
                        st[pos] = true;
                        count++;
                    }
                    else if (s[0][pos] == s[1][pos] && st[pos]) {
                        st[pos] = false;
                        count--;
                    }
                }
                if (count == 0) cout << "Yes" << endl;
                else cout << "No" << endl;
            }
        }
    }
}