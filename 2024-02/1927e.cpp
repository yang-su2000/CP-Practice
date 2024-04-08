#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(n);
        int val = n;
        bool flag = true;
        for (int i=0; i<k; i++) {
            vector<int> idxs;
            for (int j=i; j<n; j+=k) idxs.push_back(j);
            if (!flag) reverse(idxs.begin(), idxs.end());
            for (int idx: idxs) a[idx] = val--;
            flag = !flag;
        }
        for (int i=0; i<n; i++) cout << a[i] << " \n"[i == n-1];
    }
}