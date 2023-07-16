#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<string> v(3);
        cin >> v[0] >> v[1] >> v[2];
        char c = '-';
        vector<char> can {'X', 'O', '+'};
        for (char cc: can) {
            for (int i=0; i<3; i++) {
                int rcount = 0;
                for (int j=0; j<3; j++) {
                    if (v[i][j] == cc) rcount++;
                }
                if (rcount == 3) c = cc;
            }
            for (int j=0; j<3; j++) {
                int ccount = 0;
                for (int i=0; i<3; i++) {
                    if (v[i][j] == cc) ccount++;
                }
                if (ccount == 3) c = cc;
            }
            int count1 = 0, count2 = 0;
            for (int i=0; i<3; i++) {
                if (v[i][i] == cc) count1++;
                if (v[i][3-i-1] == cc) count2++;
            }
            if (count1 == 3 || count2 == 3) c = cc;
        }
        if (c == '-') cout << "DRAW" << endl;
        else cout << c << endl;
    }
}