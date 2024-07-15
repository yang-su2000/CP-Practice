#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    string a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        bool change = false;
        for (int i=0; i<a.length(); i++) {
            if (change) {
                if (a[i] < b[i]) swap(a[i], b[i]);
            } else {
                if (a[i] < b[i]) change = true;
            }
        }
        cout << a << endl;
        cout << b << endl;
    }
}