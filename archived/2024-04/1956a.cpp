#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, k, q, n;
    cin >> t;
    while (t--) {
        cin >> k >> q;
        vector<int> a(k);
        for (int &i: a) cin >> i;
        while (q--) {
            vector<int> b = a;
            cin >> n;
            while (n > 0) {
                while (!b.empty() and b.back() > n) b.pop_back();
                if (b.empty()) break;
                n = max(0, n - (int) b.size());
            }
            cout << n << " ";
        }
        cout << endl;
    }
}