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
        sort(a.begin(), a.end());
        for (int i=0; i<n/2; i++) {
            cout << a[i+1] << " " << a[0] << endl;
        }
    }
}