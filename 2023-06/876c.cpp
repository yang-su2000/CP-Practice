#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        if (v.back() == 1) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        vector<int> ans;
        int l=0;
        while (l<n and v[l] == 0) {
            ans.push_back(0);
            l++;
        }
        while (l<n) {
            int r=l;
            while (v[r] == 1) {
                r++;
            }
            // cout << "[" << l << " " << r << " ";
            ans.push_back(r-l);
            for (int i=l; i<r; i++) ans.push_back(0);
            l=r+1;
            while (l<n and v[l] == 0) {
                ans.push_back(0);
                l++;
            }
        }
        for (int i=n-1; i>=0; i--) {
            cout << ans[i] << " \n"[i == 0];
        }
    }
}