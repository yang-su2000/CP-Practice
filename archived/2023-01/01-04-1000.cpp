#include <bits/stdc++.h>
using namespace std;

long long foo(int n, vector<long long>& ls) {
    sort(ls.begin(), ls.end());
    long long ans = ls[0];
    long long to_subtract = 0;
    for (int i=0; i<n-1; i++) {
        to_subtract += ls[i];
        ls[i+1] -= to_subtract;
        ans = max(ans, ls[i+1]);
    }
    return ans;
}

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, n, tmp;
    vector<long long> ls;
    cin >> t;
    while (t--) {
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