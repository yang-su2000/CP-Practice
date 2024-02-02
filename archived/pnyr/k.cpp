#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    vector<int> a(6), b(6);
    for (int &x: a) cin >> x;
    for (int &x: b) cin >> x;
    int c1 = 0, c2 = 0;
    for (int x: a) {
        for (int y: b) {
            if (x > y) c1++;
            else if (x < y) c2++;
        }
    }
    double ans;
    if (c1 == 0 and c2 == 0) ans = 0.5;
    else ans = (double) c1 / (c1 + c2);
    printf("%.5lf\n", ans);
}