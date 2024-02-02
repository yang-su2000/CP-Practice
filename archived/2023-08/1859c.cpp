#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int sum = 0;
        for (int i=1; i<=n; i++) {
            sum += i * i;
        }
        int ans = 0;
        for (int i=n; i>=1; i--) {
            sum -= i * i;
            int csum = sum;
            int cmax = 0;
            for (int j=i; j<=n; j++) {
                int cval = j * (n - (j-i));
                csum += cval;
                cmax = max(cmax, cval);
            }
            csum -= cmax;
            ans = max(ans, csum);
        }
        cout << ans << endl;
    }
}