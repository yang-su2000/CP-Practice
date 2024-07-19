#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

class Union {
public:
    vector<int> p, size;
    Union(int n) {
        p.resize(n);
        size.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    void link(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (size[x] < size[y]) {
                p[x] = y;
                size[y] += size[x];
            } else {
                p[y] = x;
                size[x] += size[y];
            }
        }
    }
};

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