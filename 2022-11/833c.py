# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

from collections import defaultdict

def foo(n, ls):
    ans = 0
    csum = 0
    i = 0
    while i < n:
        if ls[i] == 0:
            break
        csum += ls[i]
        if csum == 0:
            ans += 1
        i += 1
        # print(ans, end=' ')
    while i < n:
        i += 1
        d = defaultdict(int)
        d[0] = 1
        csum = 0
        while i < n and ls[i] != 0:
            csum += ls[i]
            d[csum] += 1
            i += 1
        ans += max(d.values())
        # print(ans, end=' ')
    return ans

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        ls = [int(i) for i in input().split()]
        print(foo(n, ls))