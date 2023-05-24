#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

bool foo(int n, vector<string>& ls) {
    vector<string> v;
    for (auto &s: ls) {
        if (s.length() == n-1) v.push_back(s);
    }
    int m = 2 * n - 2;
    // string pre;
    // string suf;
    // if (ls[0][0] == ls[2][0] and ls[1][0] == ls[3][ls[3].length()-1]) {
    //     pre = ls[ls.size()-2];
    //     suf = ls[1];
    // } else {
    //     pre = ls[ls.size()-1];
    //     suf = ls[0];
    // }
    // {
    //     string s = ls[m-1]
    // }
    string s = v[0] + v[1];
    // cout << s;
    // map<char, int> pre;
    // map<char, int> suf;
    // for (auto &s: ls) {
    //     pre[s[0]]++;
    //     suf[s[s.length()-1]]++;
    // }
    // set<char> c1, c2;
    // for (auto &p: pre) {
    //     if (p.second >= n - 1) c1.insert(p.first);
    // }
    // for (auto &p: suf) {
    //     if (p.second >= n - 1) c2.insert(p.second);
    // }
    // // cout << c1 << c2;
    // vector<string> cand;
    // for (auto &s: ls) {
    //     if (s.length() == n - 1) {
    //         if (c1.count(s[0])) {
    //             for (char c: c2) cand.push_back(s + c);
    //         }
    //         if (c2.count(s[s.length()-1])) {
    //             for (char c: c1) cand.push_back(c + s);
    //         }
    //     }
    // }
    // vector<string> cand2;
    // for (auto &s: cand) {
    //     for ()
    // }
    string sr = s;
    reverse(sr.begin(), sr.end());
    return sr == s;
}

int main() {
    int t, n, tmp;
    vector<string> ls;
    cin >> t;
    while (t--) {
        cin >> n;
        ls.resize(2 * n - 2);
        for (int i=0; i<2 * n - 2; i++) {
            cin >> ls[i];
        }
        if (foo(n, ls)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}