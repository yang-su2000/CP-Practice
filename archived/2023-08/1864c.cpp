#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, x;
    cin >> t;
    while (t--) {
        cin >> x;
        function<vector<int>(int)> factors = [&](int val) {
            vector<int> ret;
            for (int i=2; i*i<=val; i++) {
                while (val % i == 0) {
                    ret.push_back(i);
                    val /= i;
                }
            }
            if (val != 1) ret.push_back(val);
            return ret;
        };
        vector<int> ans {x};
        vector<int> cur {x};
        while (!cur.empty()) {
            int val = cur.back();
            cur.pop_back();
            // cout << val << " ";
            if (val == 1) continue;
            vector<int> nxt = factors(val);
            if ((int) nxt.size() == 1) {
                ans.push_back(ans.back() - ans.back() / nxt[0]);
                cur.push_back(nxt[0] - 1);
            } else {
                for (int i: factors(val)) cur.push_back(i);
            }
        }
        int n = (int) ans.size();
        cout << n << endl;
        for (int i=0; i<n; i++) {
            cout << ans[i] << " \n"[i == n-1]; 
        }
        // continue;
        map<int, int> m;
        for (int j=0; j<n-1; j++) {
            int diff = ans[j] - ans[j+1];
            if (m.count(diff) && m[diff] == 2) {
                cout << "WRONG AT " << diff << endl;
            }
            m[diff]++;
        }
    }
}