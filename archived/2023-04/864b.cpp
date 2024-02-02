#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<vector<int>> A(n, vector<int>(n));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin >> A[i][j];
            }
        }
        int diff = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (A[i][j] != A[n-i-1][n-j-1]) diff++;
            }
        }
        diff /= 2;
        k -= diff;
        // cout << diff << " ";
        if (k < 0 or (k % 2 == 1 and n % 2 == 0)) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}