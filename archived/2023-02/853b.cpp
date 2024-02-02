#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

bool foo(int n, string &s) {
    if (1) {
        int l = n / 2;
        int r = n / 2;
        if (n % 2 == 0) l--;
        int flag = 0; // 0 start, 1 changed, 2 fixed
        while (l >= 0) {
            if (s[l] != s[r]) {
                if (flag == 2) return false;
                else if (flag == 1);
                else flag = 1;
            } else {
                if (flag == 0);
                else if (flag == 1) flag = 2;
                else;
            }
            l--, r++;
        }
    }
    return true;
}

int main() {
    int t, n, tmp;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        if (foo(n, s)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}