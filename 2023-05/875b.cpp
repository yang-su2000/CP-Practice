#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n, tmp;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(2*n+1), b(2*n+1);
        int cur = 0;
        int count = 0;
        for (int i=0; i<n; i++) {
            cin >> tmp;
            if (cur == tmp) count++;
            else {
                if (a[cur] < count) {
                    a[cur] = count;
                }
                cur = tmp;
                count = 1;
            }
        }
        if (a[cur] < count) a[cur] = count;
        cur = 0;
        count = 0;
        for (int i=0; i<n; i++) {
            cin >> tmp;
            if (cur == tmp) count++;
            else {
                if (b[cur] < count) {
                    b[cur] = count;
                }
                cur = tmp;
                count = 1;
            }
        }
        if (b[cur] < count) b[cur] = count;
        int ans = 0;
        for (int i=0; i<2*n+1; i++) {
            // cout << a[i] << " " << b[i] << ", ";
            ans = max(ans, a[i] + b[i]);
        }
        cout << ans << endl;
    }
}