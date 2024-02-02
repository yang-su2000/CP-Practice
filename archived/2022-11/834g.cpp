#include <bits/stdc++.h>
using namespace std;

vector<int> foo(int n, vector<int>& bs) {
    vector<bool> ls(n + 1, false);
    for (int &b:bs) {
        if (ls[b]) return {-1};
        ls[b] = true;
    }
    map<int, queue<int>> m;
    int i=1;
    while (i<=n) {
        while (i<=n && ls[i]) i++;
        if (i>n) break;
        int k=i;
        queue<int> q;
        while (i<=n && !ls[i]) q.push(i++);
        m[k]=q;
    }
    unordered_map<int, int> bm;
    i=n;
    while (i>=1 and (int) bm.size() < n/2) {
        while (i>=1 && !ls[i]) i--;
        int j=i;
        while (i>=2 && ls[i-1]) i--;
        // cout << i << j << endl;
        for (int b=i; b<=j; b++) {
            auto p=m.lower_bound(b);
            if (p==m.begin()) return {-1};
            p--;
            int v=p->second.front();
            p->second.pop();
            if (!p->second.size()) m.erase(p->first);
            bm[b] = v;
        }
        i--;
    }
    vector<int> ans;
    for (int &b:bs) {
        int v=bm[b];
        ans.emplace_back(v);
        ans.emplace_back(b);
    }
    // cout << "end" << endl;
    return ans;
}

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, n, tmp;
    vector<int> ls;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        ls.clear();
        ls.resize(n / 2);
        for (int i=0; i<n / 2; i++) {
            cin >> tmp;
            ls[i] = tmp;
        }
        bool space = false;
        for (int &i: foo(n, ls)) {
            if (!space) space = true;
            else cout << " ";
            cout << i;
        }
        cout << endl;
    }
}