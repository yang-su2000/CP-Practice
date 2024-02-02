#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, n, tmp;
    vector<int> ls;
    cin >> t;
    while (t--) {
        cin >> n;
        ls.resize(n-1);
        vector<bool> b(n+1);
        for (int i=0; i<n-1; i++) {
            cin >> tmp;
            ls[i] = tmp;
            b[tmp] = true;
        }
        vector<int> ans = ls;
        int to_add;
        for (int i=1; i<=n; i++) {
            if (!b[i]) {
                to_add = i;
                break;
            }
        }
        int n2 = n-1;
        unordered_set<int> l, r;
        while (n2--) {
            ls.resize(n-1);
            bool flag = false;
            for (int i=0; i<n-1; i++) {
                cin >> tmp;
                ls[i] = tmp;
                if (tmp == to_add) flag = true;
                else if (!flag) l.insert(tmp);
                else r.insert(tmp);
            }
        }
        if (!r.empty()) {
            bool flag = false;
            for (int i=0; i<n-1; i++) {
                if (!flag and r.count(ans[i])) {
                    cout << to_add << " ";
                    flag = true;
                }
                cout << ans[i] << " \n"[i == ans.size()-1];
            }
        } else {
            for (int i=0; i<n-1; i++) {
                cout << ans[i] << " ";
            }
            cout << to_add << endl;
        }
    }
}