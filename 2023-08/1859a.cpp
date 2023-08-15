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
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (a[0] == a[n-1]) {
            cout << -1 << endl;
        } else {
            vector<int> c;
            int j = -1;
            for (int i=n-1; i>=0; i--) {
                if (a[i] == a[n-1]) c.push_back(a[i]);
                else {
                    j = i;
                    break;
                }
            }
            cout << j+1 << ' ' << n-j-1 << endl;
            for (int i=0; i<=j; i++) cout << a[i] << " \n"[i == j];
            for (int i=0; i<(int)c.size(); i++) cout << c[i] << " \n"[i == (int)c.size()-1];
        }
    }
}