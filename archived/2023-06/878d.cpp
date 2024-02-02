#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int l = 0, r = v.back() - 1;
        function<bool(int)> solve = [&](int time) {
            int r_ = v[0] + time;
            int count = 0;
            for (int i=1; i<n; i++) {
                int l_ = v[i] - time;
                if (r_ < l_) {
                    if (++count == 3) return false;
                    r_ = v[i] + time;
                }
            }
            return true;
        };
        while (l < r) {
            int mid = (r - l) / 2 + l;
            bool ret = solve(mid);
            // cout << l << ", " << r << ", " << mid << ", " << ret << endl;
            if (ret) r = mid;
            else l = mid+1;
        }
        cout << l << endl;
    }
}