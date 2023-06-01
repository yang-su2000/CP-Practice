#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mt make_tuple // tie(a, b, c, d) = mt(d, c, b, a)
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int sum() { return 0; }
template<typename T, typename... Args>
T sum(T a, Args... args) { return a + sum(args...); }

// __builtin_ffs: 1 + (index of first 1 from right), __builtin_popcount: (# of 1s)
// __builtin_clz: (# of 0s from left), __builtin_ctz: # of 0s from right

ll binpow(ll a, ll b, ll m) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return ret;
}

ll inv(ll a, ll m) {
    return binpow(a, m-2, m);
}

class DataStructures_Fundamentals {
public:
	DataStructures_Fundamentals() {}
};

class MinStack_MaxQueue : DataStructures_Fundamentals {
public:
	MinStack_MaxQueue() {}

	static void stackModify() {

	}
};

int main() {
    MinStack_MaxQueue::stackModify();
}