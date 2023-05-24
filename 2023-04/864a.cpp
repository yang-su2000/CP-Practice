#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, n, m, x1, y1, x2, y2;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 4;
        {
            int cur = 4;
            if (x1 == 1 or x1 == n) cur--;
            if (y1 == 1 or y1 == m) cur--;
            ans = min(ans, cur);
        }
        {
            int cur = 4;
            if (x2 == 1 or x2 == n) cur--;
            if (y2 == 1 or y2 == m) cur--;
            ans = min(ans, cur);
        }
        cout << ans << endl;
    }
}