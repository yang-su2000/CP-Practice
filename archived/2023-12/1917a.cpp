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
        for (int &x: a) cin >> x;
        bool pos = true;
        for (int &x: a) {
            if (x == 0) {
                pos = false;
                break;
            } else if (x < 0) pos = !pos;
        }
        if (pos) cout << "1" << endl << "1 0" << endl;
        else cout << "0" << endl;
    }
}