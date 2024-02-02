from collections import Counter

def foo(ls):
    s = []
    d = Counter()
    for i in ls:
        while s and s[-1] > i:
            j = min(int(s.pop()) + 1, 9)
            d[j] += 1
        s.append(i)
    d += Counter([int(i) for i in s])
    ans = ''
    for i, count in sorted(d.items()):
        ans += str(i) * count
    return ans

t = int(input())
for _ in range(t):
    ls = input()
    print(foo(ls))