#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long

// ./run sample.cpp

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), b(n);
        int flag = INT_MIN;
        map<int, int> end_map; // key, val = -1 if key == a else a
        for (int i=0; i<n; i++) {
            cin >> a[i] >> b[i];
            end_map[a[i]] = flag;
            end_map[b[i]] = a[i];
        }
        ll ans = 0;
        ordered_set<int> s;
        for (auto [key, val]: end_map) {
            if (val == flag) {
                s.insert(key);
            } else {
                ans += s.order_of_key(val);
                s.erase(val);
            }
        }
        cout << ans << endl;
    }
}