#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

class Node {
public:
    int idx;
    vector<Node*> childs;
    Node(int idx): idx(idx) {}
};

int main() {
    int q, flag, x, y;
    cin >> q;
    int idx = 0;
    unordered_map<int, Node*> m;
    while (q--) {
        cin >> flag;
        if (flag == 1) {
            cin >> x;
            if (!m.count(x)) {
                m[x] = new Node(-1);
            }
            m[x]->childs.push_back(new Node(idx));
            idx++;
        } else {
            cin >> x >> y;
            if (x == y) continue;
            if (!m.count(y)) {
                m[y] = new Node(-1);
            }
            if (m.count(x)) {
                m[y]->childs.push_back(m[x]);
                m[x] = new Node(-1);
            }
        }
    }
    vector<int> ans(idx);
    function<void(int, Node*)> dfs = [&](int val, Node* node) {
        if (node->idx != -1) ans[node->idx] = val;
        for (Node* child: node->childs) {
            dfs(val, child);
        }
    };
    for (auto &[val, node]: m) {
        dfs(val, node);
    }
    for (int i=0; i<idx; i++) {
        cout << ans[i] << " \n"[i == idx-1];
    }
}