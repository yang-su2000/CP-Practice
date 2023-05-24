#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t;
    string s;
    string pi = "314159265358979323846264338327";
    cin >> t;
    while (t--) {
        cin >> s;
        int ans = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == pi[i]) ans++;
            else break;
        }
        cout << ans << endl;
    }
}