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
        for (int i=0; i<n; i++) {
            if (ls[i] == 1) ls[i]++;
            if (i > 0 and ls[i] % ls[i-1] == 0) ls[i]++;
        }
        for (int i=0; i<n; i++) {
            cout << ls[i] << " \n"[i == n-1];
        }
    }
}