#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<bool> vis(n + 1);
        vector<int> ans;
        for (int i=n; i>=1; i--) {
            int j = i;
            while (!vis[j]) {
                vis[j] = true;
                ans.push_back(j);
                if (j % 2) break;
                j /= 2;
            }
        }
        for (int i=0; i<n; i++) cout << ans[i] << " \n"[i == n-1];
    }
}