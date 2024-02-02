#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

#define ll long long

int main() {
    int t, n, tmp;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> ls(n);
        for (int i=0; i<n; i++) cin >> ls[i];
        if (n % 2) {
            cout << "Yes" << endl;
            continue;
        }
        ll cum = 0;
        for (int i=1; i<n; i+=2) cum += ls[i] - ls[i-1];
        if (cum >= 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}