#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int foo(int n, vector<int>& ls) {
    int ans = accumulate(ls.begin(), ls.end(), 0);
    int flag = -4;
    for (int i=1; i<n; i++) {
        if (ls[i] == -1 and ls[i-1] == -1) flag = max(flag, 4);
        else if (ls[i] + ls[i-1] == 0) flag = max(flag, 0);
    }
    return ans + flag;
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