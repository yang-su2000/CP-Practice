#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (ll &i: a) cin >> i;
        vector<ll> p(n);
        p[0] = a[0];
        for (int i=1; i<n; i++) p[i] = p[i-1] + a[i];
        int l = 0, r = n-1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            vector<ll> v;
            for (int i=l; i<=mid; i++) v.push_back(i);
            int k = v.size();
            cout << "? " << k << " ";
            for (int i=0; i<k; i++) cout << v[i] + 1 << " \n"[i == k-1];
            ll w;
            cin >> w;
            ll target = p[mid];
            if (l > 0) target -= p[l-1];
            if (w == target) l = mid + 1;
            else r = mid;
        }
        cout << "! " << l + 1 << endl;
    }
}