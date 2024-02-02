#include <bits/stdc++.h>
using namespace std;

int foo(int n, vector<int>& ls) {
    int ans = 0;
    long long csum = 0;
    int cmax = 0;
    int i = 0;
    unordered_map<long long, int> d;
    while (i < n) {
        if (!ls[i]) break;
        csum += ls[i++];
        if (!csum) ans++;
    }
    while (i < n) {
        i++;
        d.clear();
        d[0] = 1;
        csum = 0;
        cmax = 1;
        while (i < n && ls[i]) {
            csum += ls[i++];
            cmax = max(cmax, ++d[csum]);
        }
        ans += cmax;
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