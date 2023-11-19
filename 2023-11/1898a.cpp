#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int count = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == 'B') count++;
        }
        if (count == k) {
            cout << 0 << endl;
        } else if (count < k) {
            int i = 0;
            while (count != k) {
                if (s[i] != 'B') {
                    count++;
                }
                i++;
            }
            cout << 1 << endl;
            cout << i << " B" << endl;
        } else {
            int i = 0;
            while (count != k) {
                if (s[i] != 'A') {
                    count--;
                }
                i++;
            }
            cout << 1 << endl;
            cout << i << " A" << endl;
        }
    }
}