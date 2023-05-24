#include <bits/stdc++.h>
using namespace std;

void foo(int n, string& a, string& b) {
    int a0 = 0, a1 = 0, b0 = 0, b1 = 0;
    for (char &c:a) {
        if (c == '0') a0++;
        else a1++;
    }
    for (char &c:b) {
        if (c == '0') b0++;
        else b1++;
    }
    if (!((a0 == b0 and a1 == b1) or (a0 == b1 and a1 == b0))) {
        cout << "No" << endl;
        return;
    }
    bool same_flag = (a0 == b0 and a1 == b1);
    cout << "Yes" << endl;
    int k = 0;
    int l = 0, r = n-1;
    vector<int> ls;
    vector<int> rs;
    while (l <= r and a[l] == '0') l++;
    while (l <= r and a[r] == '0') a[r--] = '1';
    if (r+2 <= n) {
        k++;
        ls.emplace_back(r+2);
        rs.emplace_back(n);
    }
    r = n-1;
    while (l <= r) {
        k++;
        ls.emplace_back(l+1);
        rs.emplace_back(r+1);
        char c = a[l];
        while (l <= r and a[l] == c) l++;
        while (l <= r and a[r] == c) r--;
    }
    // 1, remain, all
    k += 3;
    ls.emplace_back(1);
    rs.emplace_back(1);
    ls.emplace_back(2);
    rs.emplace_back(n);
    ls.emplace_back(1);
    rs.emplace_back(n);
    cout << k << endl;
    for (int i=0; i<k; i++) cout << ls[i] << ' ' << rs[i] << endl;
}

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, n;
    string a, b;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        cin >> a >> b;
        foo(n, a, b);
    }
}