#include <bits/stdc++.h>
using namespace std;

struct Trie {
    unordered_map<int, Trie*> childs;
    vector<int> cur;
    void buildTrie(string &s, int i, int idx) {
        if (i == s.length()) {
            cur.push_back(idx);
            return;
        }
        int c = s[i] - 'a';
        if (!childs.count(c)) childs[c] = new Trie();
        childs[c]->buildTrie(s, i + 1, idx);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<string> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    vector<string> ops(q);
    vector<string> pre(q), suf(q);
    for (int i=0; i<q; i++) {
        cin >> ops[i] >> pre[i] >> suf[i];
        reverse(suf[i].begin(), suf[i].end());
    }
    vector<int> ans(q);
    Trie* pre_t = new Trie();
    Trie* suf_t = new Trie();
    for (int i=0; i<q; i++) {
        pre_t->buildTrie(pre[i], 0, i);
    }
    for (int i=0; i<q; i++) {
        suf_t->buildTrie(suf[i], 0, i);
    }
    for (int i=0; i<n; i++) {
        Trie* pre_c = pre_t;
        Trie* suf_c = suf_t;
        int l = v[i].length();
        for (int j=0; j<l; j++) {
            int pc = v[i][j] - 'a';
            int sc = v[i][l-j-1] - 'a';
            unordered_map<int, int> m; // pre_bit suf_bit
            if (pre_c && pre_c->childs.count(pc)) {
                pre_c = pre_c->childs[pc];
                for (int idx: pre_c->cur) m[idx] |= 2;
            } else {
                pre_c = nullptr;
            }
            if (suf_c && suf_c->childs.count(sc)) {
                suf_c = suf_c->childs[sc];
                for (int idx: suf_c->cur) m[idx] |= 1;
            } else {
                suf_c = nullptr;
            }
            for (auto [idx, bit]: m) {
                if (ops[idx] == "AND") {
                    if (bit == 3) ans[idx]++;
                } else if (ops[idx] == "XOR") {
                    if (bit == 2 || bit == 1) ans[idx]++;
                } else {
                    if (bit > 0) ans[idx]++;
                }
            }
            if (!pre_c && !suf_c) break;
        }
    }
    for (int i=0; i<q; i++) {
        cout << ans[i] << endl;
    }
}