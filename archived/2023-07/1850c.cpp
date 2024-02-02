#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<string> v(8);
        for (int i=0; i<8; i++) cin >> v[i];
        int r = -1, c = -1;
        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                if (v[i][j] != '.') {
                    r = i;
                    c = j;
                    break;
                }
            }
            if (r != -1) break;
        }
        string ans;
        while (r < 8 && v[r][c] != '.') {
            ans += v[r][c];
            r++;
        }
        cout << ans << endl;
    }
}