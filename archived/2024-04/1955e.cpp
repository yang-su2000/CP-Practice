#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int ans = 0;
        for (int k=1; k<=n; k++) {
            deque<int> d;
            string s2 = s;
            bool valid = true;
            for (int i=0; i<n; i++) {
                while (!d.empty() and d.front() < i) d.pop_front();
                char c = s[i];
                if (((int) d.size() % 2 and c == '1') or ((int) d.size() % 2 == 0 and c == '0')) {
                    int j = i + k - 1;
                    if (j >= n) {
                        valid = false;
                        break;
                    }
                    d.push_back(j);
                }
            }
            if (valid) ans = k;
        }
        cout << ans << endl;
    }
}