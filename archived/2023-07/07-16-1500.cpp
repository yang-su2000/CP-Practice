#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

struct Trie {
    Trie* t[2];
};

int main() {
    int n;
    cin >> n;
    Trie* T = new Trie();
    vector<int> ans;
    for (int i=2; i<=n; i++) {
        Trie* cur = T;
        bool add = true;
        // cout << i << ": ";
        for (int j=2; j<=i; j++) {
            bool flag = (i % j == 0);
            // cout << flag;
            if (!cur->t[flag]) {
                if (j <= i-1 && flag) add = false;
                cur->t[flag] = new Trie();
            }
            cur = cur->t[flag];
        }
        // cout << ": " << add << endl;
        if (add) ans.push_back(i);
    }
    int k = (int) ans.size();
    cout << k << endl;
    for (int i=0; i<k; i++) cout << ans[i] << " \n"[i == k-1];
}