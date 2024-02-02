#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (string &s: v) cin >> s;
    for (int i=0; i<m; i++) {
        int bot = n-1;
        int cur = n-1;
        while (cur >= 0 and bot >= 0) {
            if (v[cur][i] == '#') bot = cur - 1;
            else if (v[cur][i] == 'o') {
                swap(v[cur][i], v[bot][i]);
                bot--;
            }
            cur--;
        }
    }
    for (string s: v) cout << s << endl;
}