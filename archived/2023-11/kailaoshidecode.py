# 10**7
# 2x10**5
# hashmap: only remove an element once
# set: remove all identical element
# .remove() has run-time n

from collections import defaultdict

num = int(input())

for i in range(num):
    n, x = [int(i) for i in input().split()]
    a = [int(i) for i in input().split()]
    a.sort()
    b = defaultdict(int)
    for i in a:
        b[i] += 1
    ans = 0
    for key in sorted(b.keys()):
        if key * x in b:
            val = min(b[key], b[key * x])
            b[key] -= val
            b[key * x] -= val
        ans += b[key]
    print(ans)