#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, n, tmp;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> ls(n-1);
        vector<int> ls2(n, -1);
        vector<int> bound(n, INT_MAX);
        for (int i=0; i<n-1; i++) cin >> ls[i];
        for (int i=0; i<n-1; i++) {
            bound[i] = min(bound[i], ls[i]);
            bound[i+1] = min(bound[i+1], ls[i]);
            ls2[i] = bound[i];
        }
        ls2[n-1] = bound[n-1];
        // for (int i=0; i<n-2; i++) {
        //     if (ls[i] != ls[i+1]) {
        //         if (ls2[i] == -1) {
        //             ls2[i] = 0;
        //             ls2[i+1] = ls[i];
        //             ls2[i+2] = ls[i+1];
        //         } else if (ls2[i+1] == -1) {
        //             ls2[i+1] = ls[i];
        //             ls2[i+2] = ls[i+1];
        //         } else {
        //             ls2[i+2] = ls[i+1];
        //         }
        //     } else {
        //         if (ls2[i] == -1) ls2[i] = 0;
        //         ls2[i+1] = ls[i];
        //     }
        // }
        for (int i=0; i<n; i++) cout << ls2[i] << " \n"[i == n-1];
    }
}