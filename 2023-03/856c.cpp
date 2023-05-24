#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, n, tmp;
    vector<int> ls;
    cin >> t;
    while (t--) {
        cin >> n;
        ls.resize(n);
        for (int i=0; i<n; i++) {
            cin >> ls[i];
        }
        int l=0, r=0;
        while (r < n) {
            while (l < r) {
                if (ls[l] < r - l + 1) l++;
                else break;
            }
            cout << r - l + 1 << " \n"[r == n-1];
            r++;
        }
    }
}