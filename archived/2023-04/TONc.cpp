#include <bits/stdc++.h>
using namespace std;

#define ll long long

// g++ sample.cpp -o run
// ./run < input.txt

ll foo(int n, int remove, int add, vector<int>& ls) {
    ll ans = LONG_LONG_MAX;
    sort(ls.begin(), ls.end());
    ll cur = 0;
    int i = 0;
    if (ls[i] == 1) {
        i++;
    } else {
        cur = add;
    }
    int pos = 2; // next val
    while (i < n) {
        // cout << i << " " << ls[i] << ",";
        if (ls[i] > pos) {
            ans = min(ans, cur + (ll) remove * (n - i));
            cur += (ll) add * (ls[i] - pos);
            pos = ls[i] + 1;
        } else if (ls[i] < pos) {
            cur += remove;
        } else {
            pos = ls[i] + 1;
        }
        i++;
    }
    // cout << endl;
    ans = min(ans, cur);
    return ans;
}

int main() {
    int t, n, c, d, tmp;
    vector<int> ls;
    cin >> t;
    while (t--) {
        cin >> n >> c >> d;
        ls.resize(n);
        for (int i=0; i<n; i++) {
            cin >> ls[i];
        }
        cout << foo(n, c, d, ls) << endl;
    }
}