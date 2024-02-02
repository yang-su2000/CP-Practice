#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a < b) swap(a, b);
        int n = a + b;
        int l = n / 2;
        vector<int> ls;
        if (n % 2 == 0) { // even
            for (int i=a-l; i<=3*l-a; i+=2) ls.push_back(i);
            
        } else { // odd
            for (int i=a-l-1; i<=3*l+2-a; i++) ls.push_back(i);
        }
        cout << ls.size() << endl;
        bool is_first = true;
        for (int &i: ls) {
            if (is_first) is_first = false;
            else cout << " ";
            cout << i;
        }
        cout << endl;
    }
}