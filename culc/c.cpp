#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    string s;
    cin >> s;
    int n = (int) s.length();
    vector<int> v;
    int l = 0, r = n-1;
    while (l < r) {
        while (l < r && s[r] == 'c') r--;
        while (l < r && s[l] != 'c') l++;
        if (l < r) {
            v.push_back(l);
            v.push_back(r);
            l++, r--;
        }
    }
    if (v.empty()) {
        cout << 1 << endl;
        cout << 1 << endl;
        return 0;
    }
    sort(v.begin(), v.end());
    int k = (int) v.size();
    cout << k << endl;
    for (int i=0; i<k; i++) {
        cout << v[i] + 1 << " \n"[i == k-1];
    }
}