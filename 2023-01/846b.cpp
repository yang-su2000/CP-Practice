#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

long long foo(int n, vector<long long>& ls) {
    long long lsum = 0, rsum = accumulate(ls.begin(), ls.end(), 0ll);
    long long ans = 0;
    for (int i=0; i<n-1; i++) lsum += ls[i], rsum -= ls[i], ans = max(ans, __gcd(lsum, rsum));
    return ans;
}

int main() {
    int t, n, tmp;
    vector<long long> ls;
    cin >> t;
    while (t--) {
        cin >> n;
        ls.resize(n);
        for (int i=0; i<n; i++) {
            cin >> tmp;
            ls[i] = tmp;
        }
        cout << foo(n, ls) << endl;
    }
}