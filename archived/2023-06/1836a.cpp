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
        vector<int> ls(n);
        vector<int> v(100);
        for (int i=0; i<n; i++) {
            cin >> ls[i];
        }
        sort(ls.begin(), ls.end());
        bool flag = true;
        for (int i=0; i<n; i++) {
            v[ls[i]]++;
            if (ls[i] > 0 && v[ls[i]] > v[ls[i]-1]) flag = false;
        }
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}