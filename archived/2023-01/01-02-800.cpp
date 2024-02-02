#include <bits/stdc++.h>
using namespace std;

int foo(int n) {
    string s = to_string(n);
    if ((s.back() - '0') % 2 == 0) return 0;
    if ((s.front() - '0') % 2 == 0) return 1;
    for (char &c: s) {
        if ((c - '0') % 2 == 0) return 2;
    }
    return -1;
}

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, n;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        cout << foo(n) << endl;
    }
}