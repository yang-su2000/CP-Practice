#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        map<int, int> m;
        for (int i: a) m[i]++;
        int s = (int) m.size();
        if (s > 2) {
            cout << "No" << endl;
            continue;
        } else if (s == 1) {
            cout << "Yes" << endl;
            continue;
        }
        int c1 = m.begin()->second;
        int c2 = m.rbegin()->second;
        if (n % 2) {
            if (abs(c1 - c2) == 1) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else {
            if (abs(c1 - c2) == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}