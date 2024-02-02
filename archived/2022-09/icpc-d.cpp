#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> foo(long long n, vector<long long>& A, vector<long long>& B, vector<long long>& C) {
    vector<long long> ans(n);
    long long modulo = 998244353;
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            C[i] = C[i] * (A[i] + B[k]) % modulo;
        }
        for (int i=0; i<n; i++) {
            ans[k] += C[i];
        }
        ans[k] %= modulo;
    }
    return ans;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> A(n), B(n), C(n);
    for (int i=0; i<n; i++) cin >> A[i];
    for (int i=0; i<n; i++) cin >> B[i];
    for (int i=0; i<n; i++) cin >> C[i];
    vector<long long> ans = foo(n, A, B, C);
    for (int i=0; i<n; i++) {
        cout << ans[i];
        if (i<n-1) cout << ' ';
        else cout << endl;
    }
}