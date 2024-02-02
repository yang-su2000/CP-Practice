# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

from collections import defaultdict

def foo(n, s):
    ans = 0
    for i in range(n):
        d = defaultdict(int)
        cmax = 0
        for j in range(i, n):
            d[s[j]] += 1
            cmax = max(cmax, d[s[j]])
            if cmax > 10:
                break
            if cmax <= len(d):
                ans += 1
    return ans

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        s = input()
        print(foo(n, s))