#include <bits/stdc++.h>
using namespace std;

vector<int> get_factors(int bound) {
    vector<int> factors {2};
    for (int i=3; i<=bound; i++) {
        bool is_f = true;
        for (int &f: factors) {
            if (i % f == 0) {
                is_f = false;
                break;
            }
        }
        if (is_f) factors.push_back(i);
    }
    // for (int &f: factors) {
    //     printf("%d ", f);
    // }
    // printf("\n");
    return factors;
}

int foo(int n, vector<int>& ls, vector<int>& factors) {
    vector<int> ls_bin(n);
    for (int i=0; i<n; i++) { // n
        int b=1;
        for (int &f: factors) { // 11
            if (ls[i] % f == 0) ls_bin[i] |= b;
            b <<= 1;
        }
    }
    for (int ans=2*n-2; ans>=0; ans--) { // 2n
        int i=min(n-1, ans);
        int j=ans-i;
        while (i>=0 and j>=0 and j<n) {
            if ((ls_bin[i] & ls_bin[j]) == 0) return ans + 2;
            i--, j++;
        }
    }
    return -1;
}

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    vector<int> factors = get_factors(1000);
    int t, n, tmp;
    vector<int> ls;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        ls.clear();
        ls.resize(n);
        for (int i=0; i<n; i++) {
            cin >> tmp;
            ls[i] = tmp;
        }
        cout << foo(n, ls, factors) << endl;
    }
}