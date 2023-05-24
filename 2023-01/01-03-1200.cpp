#include <bits/stdc++.h>
using namespace std;

long long foo(int n, vector<int>& ls) {
    vector<int> bits(32);
    long long ans = 0;
    for (int i:ls) {
        int bit = 0;
        while (i) {
            i >>= 1;
            bit++;
        }
        ans += bits[bit];
        bits[bit]++;
    }
    return ans;
}

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, n, tmp;
    vector<int> ls;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        ls.clear();
        ls.resize(n);
        for (int i=0; i<n; i++) {
            cin >> tmp;
            ls[i] = tmp;
        }
        cout << foo(n, ls) << endl;
    }
}