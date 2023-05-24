#include <bits/stdc++.h>
using namespace std;

vector<int> foo(int n, vector<int>& a, int q, vector<pair<int, int>>& ls) {
    vector<int> ans(n);
    ans[0] = 1;
    for (int i=1; i<n; i++) {
        ans[i] = min(min(ans[i-1] + 1, i + 1), a[i]);
    }
    vector<int> sums(n);
    sums[0] = 1;
    for (int i=1; i<n; i++) {
        sums[i] = sums[i-1] + ans[i];
    }
    for (int i=0; i<q; i++) {
        int p = ls[i].first;
        int x = ls[i].second;
        int prev = a[p-1];
        if (prev == x) {
            cout << sums.back() << endl;
            continue;
        }
        a[p-1] = x;
        int sums_i = 0;
        int ans_i = 0;
        if (p-1 > 0) {
            sums_i = sums[p-2];
            ans_i = ans[p-2];
        }
        for (int j=p-1; j<n; j++) {
            ans_i = min(min(ans_i + 1, j + 1), a[j]);
            sums_i += ans_i;
            if (ans_i == ans[j]) {
                sums_i += sums.back() - sums[j];
                break;
            }
        }
        a[p-1] = prev;
        cout << sums_i << endl;
    }
}

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int n, q, tmp, tmp2;
    
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> tmp;
        a[i] = tmp;
    }
    cin >> q;
    vector<pair<int, int>> ls(q);
    for (int i=0; i<q; i++) {
        cin >> tmp;
        cin >> tmp2;
        ls[i] = {tmp, tmp2};
    }
    foo(n, a, q, ls);
}