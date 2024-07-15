#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 1) {
            cout << 9999 << endl;
            for (int a=2; a<=10000; a++) {
                cout << a << " " << a - 1 << endl;
            }
            continue;
        }
        string s = to_string(n);
        int l = s.length();
        string ss;
        for (int i=0; i<8; i++) ss += s;
        vector<pair<int, int>> v;
        for (int d=1; d<=8; d++) {
            string cur = ss.substr(0, d);
            int val = stoi(cur);
            if ((val - d) % (n - l) == 0) {
                int a = (val - d) / (n - l);
                int b = a * l - d;
                if (1 <= a and a <= 10000 and 1 <= b and b <= min(10000, a * n)) {
                    v.push_back(make_pair(a, b));
                }
            }
        }
        cout << (int) v.size() << endl;
        for (auto [a, b]: v) {
            cout << a << " " << b << endl;
        }
        // write a hash function
        
    }
}