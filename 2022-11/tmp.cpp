#include <bits/stdc++.h>
using namespace std;

vector<int> foo(int k, vector<int>& ls) {
    auto cmp = [](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    };
    vector<pair<int, int>> v;
    set<int> s;
    for (int i=0; i<ls.size(); i++) {
        v.push_back({ls[i], i});
        s.insert(i);
    }
    sort(v.begin(), v.end(), [](auto a, auto b){
        if (a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    });
    vector<int> ans(ls.size());
    for (auto &p:v) {
        int val = p.first;
        int i = p.second;
        auto it = s.find(i);
        bool done = true;
        int j = 0;
        while (j < k) {
            if (++it == s.end()) {
                ans[i] = -1;
                done = false;
                break;
            }
            if (ls[*it] >= val) j++;
        }
        if (done) {
            ans[i] = *it + 1;
        }
        s.erase(i);
        cout << val << "/" << i << "/";
        for (auto &a:s) cout << a << " ";
        cout << endl;
    }
    return ans;
}

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, k, n, tmp;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> k;
        cin >> n;
        vector<int> ls;
        for (int i=0; i<n; i++) {
            cin >> tmp;
            ls.push_back(tmp);
        }
        for (auto &i: foo(k, ls)) {
            cout << i << " ";
        }
        cout << endl;
    }
}