#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) a[i] = i+1;
    // for (int i=1; i<n; i++) {
    //     if (__gcd(a[i], a[i-1]) != 1) cout << i << endl;
    // }
    // if (__gcd(a[0], a[n-1]) != 1) cout << n << endl;
    for (int i=0; i<n; i++) {
        cout << a[i] << " \n"[i == n-1];
    }
}