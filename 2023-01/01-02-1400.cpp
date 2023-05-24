#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int main() {
    int q;
    cin >> q;
    int flag;
    set<pii> s;
    priority_queue<pii> pq; // flag = 3
    queue<pii> qu; // flag = 2
    bool is_first = true;
    int label = 0;
    for (int i=0; i<q; i++) {
        cin >> flag;
        if (flag == 1) {
            label++;
            int m;
            cin >> m;
            pii p = make_pair(m, -label);
            s.insert(p);
            pq.push(p);
            qu.push(p);
        } else if (flag == 2) {
            while (!s.count(qu.front())) qu.pop();
            pii p = qu.front();
            qu.pop();
            s.erase(p);
            if (is_first) is_first = false;
            else printf(" ");
            printf("%d", -p.second);
        } else if (flag == 3) {
            while (!s.count(pq.top())) pq.pop();
            pii p = pq.top();
            pq.pop();
            s.erase(p);
            if (is_first) is_first = false;
            else printf(" ");
            printf("%d", -p.second);
        }
    }
}