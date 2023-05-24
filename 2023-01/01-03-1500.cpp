#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, n, tmp;
    vector<int> ls;
    unordered_map<int, int> mc;
    vector<int> mcc;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        ls.clear();
        ls.resize(n);
        mc.clear();
        mcc.clear();
        for (int i=0; i<n; i++) {
            cin >> tmp;
            ls[i] = tmp;
        }
        for (int i:ls) mc[i]++;
        for (auto p:mc) {
            if (p.second >= mcc.size()) mcc.resize(p.second + 1);
            mcc[p.second]++;
        }
        int ans = INT_MAX;
        int l = n, r = 0;
        int rcount = 0;
        for (int i=mcc.size()-1; i>=0; i--) {
            l -= i * mcc[i];
            ans = min(ans, l + r);
            rcount += mcc[i];
            if (i) r += rcount;
        }
        cout << ans << endl;
    }
}