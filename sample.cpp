#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp
// ./a < input

#define ll long long
#define pii pair<int, int>
#define PQ priority_queue<int>
#define PQ2 priority_queue<int, vector<int>, greater<>>

long long foo(int n, vector<int>& ls) {
    return 0;
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
        cout << foo(n, ls) << endl;
    }
}