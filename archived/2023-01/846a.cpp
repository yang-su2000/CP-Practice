#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

void foo(int n, vector<int>& ls) {
    vector<int> even;
    vector<int> odd;
    for (int i=0; i<n; i++) {
        if (ls[i] % 2) odd.emplace_back(i);
        else even.emplace_back(i);
        if (even.size() >= 2 and odd.size() >= 1) {
            printf("YES\n%d %d %d\n", even[0]+1, even[1]+1, odd[0]+1);
            return;
        } else if (odd.size() >= 3) {
            printf("YES\n%d %d %d\n", odd[0]+1, odd[1]+1, odd[2]+1);
            return;
        }
    }
    printf("NO\n");
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
        foo(n, ls);
    }
}