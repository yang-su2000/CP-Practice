#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, n, x1, y1, x2, y2;
    cin >> t;
    while (t--) {
        cin >> n >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        int n2 = n / 2;
        if (x1 >= n2) x1 = n - x1 - 1;
        if (y1 >= n2) y1 = n - y1 - 1;
        if (x2 >= n2) x2 = n - x2 - 1;
        if (y2 >= n2) y2 = n - y2 - 1;
        cout << abs(min(x1, y1) - min(x2, y2)) << endl;
    }
}