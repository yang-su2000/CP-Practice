#include <bits/stdc++.h>
using namespace std;

class Trie {
    unordered_map<char, Trie*> d;
    int tail = 0;
    int count = 0;
public:
    int find(string &s, int i) {
        if (i == (int) s.size()) {
            if (count > 1) return i;
            return i - 1;
        }
        char c = s[i];
        if (count <= 1 or !d.count(c)) return i - 1;
        return d[c]->find(s, i+1);
    }

    void add(string &s, int i) {
        if (i == (int) s.size()) {
            tail++;
            return;
        }
        char c = s[i];
        if (!d.count(c)) d[c] = new Trie();
        d[c]->add(s, i+1);
    }
    
    int trace() {
        count = tail;
        for (auto p: d) count += p.second->trace();
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> v;
    string s;
    Trie* T = new Trie();
    while (n--) {
        cin >> s;
        v.emplace_back(s);
        T->add(s, 0);
    }
    T->trace();
    for (string &s: v) {
        cout << T->find(s, 0) << endl;
    }
}