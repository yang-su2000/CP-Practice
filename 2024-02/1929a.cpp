#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int &x: a) cin >> x;
        sort(a.begin(), a.end());
        cout << a.back() - a.front() << endl;
    }
}