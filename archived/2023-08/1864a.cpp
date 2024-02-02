#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, x, y, n;
    cin >> t;
    while (t--) {
        cin >> x >> y >> n;
        vector<int> ans;
        int dec = 1;
        ans.push_back(y);
        while ((int) ans.size() < n) {
            ans.push_back(ans.back() - dec);
            dec++;
        }
        if (ans.back() < x) {
            cout << -1 << endl;
        } else {
            ans.back() = x;
            for (int i=n-1; i>=0; i--) {
                cout << ans[i] << " \n"[i == 0];
            }
        }
    }
}