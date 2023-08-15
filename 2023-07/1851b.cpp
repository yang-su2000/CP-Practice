#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v(n);
        vector<int> even, odd;
        vector<int> ei, oi;
        for (int i=0; i<n; i++) {
            cin >> v[i];
            if (v[i] % 2 == 0) {
                even.push_back(v[i]);
                ei.push_back(i);
            } else {
                odd.push_back(v[i]);
                oi.push_back(i);
            }
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        sort(ei.begin(), ei.end());
        sort(oi.begin(), oi.end());
        for (int i=0; i<(int)even.size(); i++) {
            v[ei[i]] = even[i];
        }
        for (int i=0; i<(int)odd.size(); i++) {
            v[oi[i]] = odd[i];
        }
        bool ans = true;
        for (int i=1; i<n; i++) {
            if (v[i] < v[i-1]) {
                ans = false;
                break;
            }
        }
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}