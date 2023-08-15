#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

struct Trie {
    int level = 0;
    int count = 0;
    Trie* t[2];
};

int main() {
    int t, n, k, tmp;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        for (int i=0; i<n; i++) {
            cin >> tmp;
            a[i] = {tmp, i};
        }
        sort(a.begin(), a.end());
        int ans = -1;
        int ansl = 0, ansr = 0, ansx = 0;
        for (int i=1; i<n; i++) {
            int l = a[i-1].first, r = a[i].first;
            int x = 0;
            for (int j=k-1; j>=0; j--) {
                if (((l & (1 << j)) == 0) && ((r & (1 << j)) == 0)) {
                    x |= (1 << j);
                }
            }
            int val = (l ^ x) & (r ^ x);
            if (val > ans) {
                ans = val;
                ansl = a[i-1].second;
                ansr = a[i].second;
                ansx = x;
            }
        }
        cout << ansl + 1 << " " << ansr + 1 << " " << ansx << endl;
        // Trie* T = new Trie();
        // for (int i=0; i<n; i++) {
        //     Trie* cur = T;
        //     cur->count++;
        //     for (int j=k-1; j>=0; j--) {
        //         bool b = a[i] & (1 << j);
        //         if (!cur->t[b]) {
        //             cur->t[b] = new Trie();
        //             cur->t[b]->level = cur->level + 1;
        //         }
        //         cur = cur->t[b];
        //         cur->count++;
        //     }
        // }
    }
}