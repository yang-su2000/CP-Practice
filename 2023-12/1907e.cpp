#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    map<int, map<pair<int, int>, ll>> m; // num -> carry, digit sum -> count
    for (int a=0; a<10; a++) {
        for (int b=0; b<10; b++) {
            for (int c=0; c<10; c++) {
                int sum = a + b + c;
                m[sum % 10][make_pair(sum / 10, sum)]++;
            }
        }
    }
    // for (auto [num, p]: m) {
    //     cout << num << ": ";
    //     for (auto [carry, count]: p) {
    //         cout << "(" << carry.first << ", " << carry.second << ") -> " << count << "; ";
    //     }
    //     cout << endl;
    // }
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int n2 = n;
        int dsum = 0;
        while (n2 > 0) {
            dsum += n2 % 10;
            n2 /= 10;
        }
        map<pair<int, int>, ll> dp; // num, dsum -> val
        dp[make_pair(n, dsum)] = 1;
        ll ans = 0;
        while (!dp.empty()) {
            map<pair<int, int>, ll> dp2;
            for (auto [p, val]: dp) {
                int num = p.first;
                int dsum = p.second;
                if (num == 0) {
                    if (dsum == 0) ans += val;
                    continue;
                }
                int last = num % 10;
                int first = num / 10;
                for (auto [p, count]: m[last]) {
                    int carry = p.first;
                    int ddiff = p.second;
                    int num2 = first - carry;
                    int dsum2 = dsum - ddiff;
                    if (num2 >= 0 and dsum2 >= 0) {
                        dp2[make_pair(num2, dsum2)] += val * count;
                    }
                }
            }
            // for (auto [p, val]: dp2) {
            //     cout << "(" << p.first << ", " << p.second << ") -> " << val << endl;
            // }
            swap(dp, dp2);
        }
        // for (auto [p, val]: dp) {
        //     cout << "(" << p.first << ", " << p.second << ") -> " << val << endl;
        // }
        cout << ans << endl;
    }
}