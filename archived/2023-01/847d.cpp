#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int foo(int n, vector<int>& ls) {
    multiset<int> ans;
    sort(ls.begin(), ls.end());
    for (int i: ls) {
        if (ans.count(i)) {
            // cout << i << "+1" << " ";
            ans.erase(ans.lower_bound(i));
            ans.insert(i+1);
        } else {
            // cout << "[" << i << "+1]" << " ";
            ans.insert(i+1);
        }
    }
    return (int) ans.size();
}

int main() {
    int t, n, tmp;
    vector<int> ls;
    cin >> t;
    while (t--) {
        cin >> n;
        ls.resize(n);
        for (int i=0; i<n; i++) {
            cin >> tmp;
            ls[i] = tmp;
        }
        cout << foo(n, ls) << endl;
    }
}