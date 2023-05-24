#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

bool foo(int n, vector<int>& ls) {
    vector<bool> flag(n);
    int gcd = INT_MAX;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int g = __gcd(ls[i], ls[j]);
            if (g <= 2) {
                gcd = g;
                flag[i] = true;
                flag[j] = true;
                break;
            }
        }
        if (gcd <= 2) break;
    }
    if (gcd > 2) return false;
    if (n == 2) return true;
    int remain = n - 1;
    int l = 3;
    while (remain) {
        for (int i=0; i<n; i++) {
            if (flag[i]) continue;
            int g = __gcd(gcd, ls[i]);
            if (g <= l) {
                gcd = g;
                flag[i] = true;
                break;
            }
        }
        if (gcd > l) return false;
        remain--;
        l++;
    }
    return true;
}

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
        if (foo(n, ls)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}