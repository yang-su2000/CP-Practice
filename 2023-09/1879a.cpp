#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, s, e;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s >> e;
        int w = s;
        int times = e;
        for (int i=1; i<n; i++) {
            cin >> s >> e;
            if (s >= w and e >= times) {
                w = -1;
            }
        }
        cout << w << endl;
    }
}