#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    vector<vector<vector<int>>> v(205, vector<vector<int>>(205, vector<int>(4))); // 0 - unvisited, -1 - wall, 1 visited
    vector<string> s {"left", "down", "right", "up"};
    vector<vector<int>> d {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<int> r {2, 3, 0, 1};
    string in;
    int x = 101, y = 101;
    while (1) {
        bool done = false;
        int x2, y2, i2;
        for (int i=0; i<4; i++) {
            int xn = x + d[i][0], yn = y + d[i][1];
            if (v[xn][yn][r[i]] == 0 && v[x][y][i] == 0) {
                done = true;
                x2 = xn, y2 = yn, i2 = i;
                break;
            }
        }
        if (!done) {
            for (int i=0; i<4; i++) {
                int xn = x + d[i][0], yn = y + d[i][1];
                if (v[x][y][i] == 0) {
                    done = true;
                    x2 = xn, y2 = yn, i2 = i;
                    break;
                }
            }
        }
        if (!done) {
            cout << "no way out" << endl;
            break;
        }
        // cout << x2 << ", " << y2 << ", " << i2 << endl;
        cout << s[i2] << endl;
        cin >> in;
        if (in == "ok") {
            v[x][y][i2] = 1;
            x = x2, y = y2;
        } else if (in == "wall") {
            v[x][y][i2] = -1;
        } else if (in == "solved") {
            break;
        }
    }
}