#include <bits/stdc++.h>
using namespace std;

long long foo(long long n, string& s) {
    long long zeros = 0;
    long long ones = 0;
    for (auto &i:s) {
        if (i == '0') zeros++;
        else ones++;
    }
    long long ans = zeros * ones;
    long long count = 0;
    char c = '/';
    for (auto &i:s) {
        if (c != i) {
            ans = max(ans, count*count);
            count = 1;
            c = i;
        } else count++;
    }
    ans = max(ans, count*count);
    return ans;
}

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    long long t, n;
    string s;
    cin >> t;
    for (long long i=0; i<t; i++) {
        cin >> n;
        cin >> s;
        cout << foo(n, s) << endl;
    }
}