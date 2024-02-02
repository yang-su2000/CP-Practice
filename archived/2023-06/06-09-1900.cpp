#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n, d;
    cin >> t;
    while (t--) {
        cin >> n >> d;
        vector<int> a(n);
        vector<int> diff(n);
        int cmin = d;
        vector<int> idxs;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            if (i == 0) diff[i] = a[i] - 1;
            else diff[i] = a[i] - a[i-1] - 1;
            if (diff[i] < cmin) {
                cmin = diff[i];
                idxs = {i};
            } else if (diff[i] == cmin) {
                idxs.push_back(i);
            }
        }
        diff.push_back(d - a[n-1]);
        // more than 2 min value -> no better way
        // 2 min value and not consecutive -> no better way
        if (idxs.size() > 2 || (idxs.size() == 2 && idxs[0] + 1 != idxs[1])) {
            cout << cmin << endl;
            continue;
        }
        // 2 min value and consecutive -> check first one
        if (idxs.size() == 2) {
            idxs = {idxs[0]};
        // 1 value and not start -> check both previous one and mine
        } else if (idxs.size() == 1 && idxs[0] > 0) {
            idxs = {idxs[0] - 1, idxs[0]};
        }
        // for (int dif: diff) cout << dif << " ";
        // cout << " & ";
        // for (int idx: idxs) cout << idx << " ";
        // cout << endl;
        int ans = 0;
        int dn = (int) diff.size();
        for (int idx: idxs) {
            vector<int> diff2;
            int i = 0;
            while (i < dn) {
                if (i == idx) {
                    diff2.push_back(diff[i] + diff[i+1] + 1);
                    i += 2;
                } else {
                    diff2.push_back(diff[i++]);
                }
            }
            // for (int dif: diff2) cout << dif << " ";
            // cout << " & " << endl;
            int mind = 0;
            int minv = d;
            int dn2 = (int) diff2.size();
            for (int i=0; i<dn2; i++) {
                if (i == dn2 - 1) {
                    mind = max(mind, diff2[i] - 1);
                }
                else {
                    mind = max(mind, (diff2[i] - 1) / 2);
                    minv = min(minv, diff2[i]);
                }
            }
            // cout << mind << " & " << minv << endl;
            ans = max(ans, min(mind, minv));
        }
        cout << ans << endl;
    }
}