#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

class Trie {
public:
    int val;
    Trie* child[2];

    void add(int pre_xor) {
        Trie* tmp = this;
        for (int i=8; i>=0; i--) {
            bool cur = pre_xor & (1 << i);
            if (!tmp->child[cur]) {
                tmp->child[cur] = new Trie();
            }
            tmp = tmp->child[cur];
        }
        tmp->val = pre_xor;
    }

    int get(int pre_xor) {
        Trie* tmp = this;
        for (int i=8; i>=0; i--) {
            bool cur = pre_xor & (1 << i);
            if (tmp->child[1-cur]) tmp = tmp->child[1-cur];
            else if (tmp->child[cur]) tmp = tmp->child[cur];
        }
        return pre_xor ^ (tmp->val);
    }
};

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        Trie* root = new Trie();
        int ans = 0;
        int pre_xor = 0;
        for (int i=0; i<n; i++) {
            pre_xor ^= a[i];
            root->add(pre_xor);
            int sub = root->get(pre_xor);
            ans = max(ans, max(pre_xor, sub));
            // cout << pre_xor << ", " << sub << endl;
        }
        cout << ans << endl;
    }
}