#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int pos = -1;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            if (a[i] > 0) pos = i;
        }
        if (pos == -1) {
            cout << n - 1 << endl;
            for (int i=n-1; i>=1; i--) {
                cout << i << " " << i+1 << endl;
            }
            continue;
        }
        int k = 2 * (n - 1) + 7;
        cout << k << endl;
        for (int i=0; i<6; i++) {
            cout << pos+1 << " " << pos+1 << endl; 
        }
        cout << 1 << " " << pos+1 << endl;
        for (int i=0; i<n-1; i++) {
            cout << i+2 << " " << i+1 << endl;
            cout << i+2 << " " << i+1 << endl;
        }
    }
}