#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, n, s, r, tmp;
    cin >> t;
    while (t--) {
        cin >> n >> s >> r;
        int max_ = s - r;
        cout << max_ << " ";
        vector<int> ans(n - 1, max_);
        int to_minus = (n - 1) * max_ - r;
        for (int i=0; i<ans.size(); i++) {
            if (to_minus == 0) break;
            int tm = min(ans[i]-1, to_minus);
            ans[i] -= tm;
            to_minus -= tm;
        }
        for (int i=0; i<ans.size(); i++) cout << ans[i] << " \n"[i == ans.size()-1];
    }
}