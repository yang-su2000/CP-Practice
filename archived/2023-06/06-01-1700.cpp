#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp
// ./a < input

#define ll long long

int main() {
    string s;
    cin >> s;
    int i = s.length()-1;
    vector<int> v; // -1: ")"
    while (i >= 0) {
        char c = s[i];
        if (c == '>') {
            i -= 2;
        } else if (c == ')') {
            v.push_back(-1);
            i--;
        } else if (c == '(') {
            if (v.back() == -1) {
                v.back() = 0; // () -> 0
            } else {
                int val = v.back(); // (val)
                v.pop_back();
                v.back() = val;
            }
            if (v.size() >= 2 && v[v.size()-2] != -1) { // val1, val2
                int val1 = v.back();
                v.pop_back();
                int val2 = v.back();
                v.back() = max(val1 + 1, val2);
            }
            i--;
        } else {
            cout << "INVALID: " << c << endl;
            break;
        }
    }
    cout << v.back() << endl;
}