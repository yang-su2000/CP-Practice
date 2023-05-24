#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> first(n);
        vector<int> second(n);
        first[0] = 2*n;
        second[n-1] = 2*n-1;
        bool is_first = true;
        for (int i=2*n-2, j=n-2; i>n; i--, j--) {
            if (is_first) first[j] = i;
            else second[j] = i;
            is_first = !is_first;
        }
        is_first = true;
        for (int i=n, j=n-1; i>=1; i--, j--) {
            if (is_first) first[j] = i;
            else second[j] = i;
            is_first = !is_first;
        }
        for (int i=0; i<n; i++) cout << first[i] << " \n"[i == n - 1];
        for (int i=0; i<n; i++) cout << second[i] << " \n"[i == n - 1];
    }
}