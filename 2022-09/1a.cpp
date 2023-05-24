#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long foo(long long n, long long m, long long a) {
    long long i = n / a;
    if (n % a) i++;
    long long j = m / a;
    if (m % a) j++;
    return i * j;
}

int main() {
    long long n, m, a;
    cin >> n >> m >> a;
    cout << foo(n, m, a) << endl;
}