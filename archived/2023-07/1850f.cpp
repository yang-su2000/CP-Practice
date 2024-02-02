#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, val;
    cin >> t;
    while (t--) {
        cin >> n;
        map<int, int> m;
        vector<int> flag(n + 1);
        for (int i=0; i<n; i++) {
            cin >> val;
            m[val]++;
        }
        for (auto [val, count]: m) {
            for (int cur=val; cur<=n; cur+=val) {
                flag[cur] += count;
            }
        }
        cout << *max_element(flag.begin(), flag.end()) << endl;
    }
}