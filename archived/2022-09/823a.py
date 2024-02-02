from collections import Counter

def foo(n, c, ls):
    ans = 0
    d = Counter(ls)
    for a, count in d.items():
        if count > c:
            ans += c
        else:
            ans += count
    return ans

t = int(input())
for _ in range(t):
    n, c = [int(i) for i in input().split()]
    ls = [int(i) for i in input().split()]
    print(foo(n, c, ls))