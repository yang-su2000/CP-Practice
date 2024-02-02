#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

bool foo(int n, vector<int>& ls) {
    for (int i=0; i<n; i++) {
        if (ls[i] <= i+1) return true;
    }
    return false;
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
        if (foo(n, ls)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}