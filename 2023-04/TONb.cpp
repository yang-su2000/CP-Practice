#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, n, tmp;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> ls;
        bool valid = true;
        while (n != 1) {
            if (n % 2 == 0) {
                valid = false;
                break;
            }
            if (ls.size() == 40) {
                valid = false;
                break;
            }
            if (((n + 1) / 2) % 2) {
                n = (n + 1) / 2;
                ls.push_back(1);
            } else {
                n = (n - 1) / 2;
                ls.push_back(2);
            }
            // cout << n << ",";
        }
        if (valid) {
            cout << (int) ls.size() << endl;
            for (int i=(int)ls.size()-1; i>=0; i--) {
                cout << ls[i] << " \n"[i == 0];
            }
        } else {
            cout << -1 << endl;
        }
    }
}