#include <vector>
#include <iostream>
using namespace std;

#define ll long long

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int n, k;
    cin >> n >> k; // 1 <= n <= 100, 1 <= 1e9 <= k
    vector<vector<int>> A(n, vector<int>(n));
    vector<int> vis(2 * n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> A[i][j]; // 0 or 1
        }
    }
    int q;
    ll s, t;
    cin >> q; // 1 <= q <= 100
    for (int flag=1; flag<=q; flag++) {
        cin >> s >> t; // 1 <= s, t <= n * k
        (--s) %= (2 * n);
        (--t) %= (2 * n);
        // cout << s << " " << t;
        int d = 0;
        bool done = false;
        vector<int> v;
        v.push_back(s);
        vector<int> v2;
        while (!v.empty()) {
            d++;
            // cout << "[";
            // for (int i: v) cout << i << " ";
            // cout << "]";
            for (int node: v) {
                if (node >= n) {
                    for (int child=n; child<2*n; child++) {
                        // 2 -> 2
                        if (A[node-n][child-n] && (vis[child] != flag)) {
                            if (child == t) {
                                // cout << " {2->2} " << node << " " << child << " ";
                                cout << d << endl;
                                done = true;
                                break;
                            }
                            // cout << child << ",";
                            v2.push_back(child);
                            vis[child] = flag;
                        }
                        // 2 -> 1
                        if (A[node-n][child-n] && (vis[child-n] != flag)) {
                            if (child-n == t) {
                                // cout << " {2->1} " << node << " " << child << " ";
                                cout << d << endl;
                                done = true;
                                break;
                            }
                            // cout << child << ",";
                            v2.push_back(child-n);
                            vis[child-n] = flag;
                        }
                    }
                } else { // n < 0 ???
                    for (int child=0; child<n; child++) {
                        // 1 -> 1
                        if (A[node][child] && (vis[child] != flag)) {
                            if (child == t) {
                                // cout << " {1->1} " << node << " " << child << " ";
                                cout << d << endl;
                                done = true;
                                break;
                            }
                            // cout << child << ",";
                            v2.push_back(child);
                            vis[child] = flag;
                        }
                        // 1 -> 2
                        if (A[node][child] && (vis[child+n] != flag)) {
                            if (child+n == t) {
                                // cout << " {1->2} " << node << " " << child << " ";
                                cout << d << endl;
                                done = true;
                                break;
                            }
                            // cout << child << ",";
                            v2.push_back(child+n);
                            vis[child+n] = flag;
                        }
                    }
                }
                if (done) break;
            }
            if (done) break;
            else {
                swap(v, v2);
                v2.clear();
            }
        }
        if (!done) cout << -1 << endl;
    }
}