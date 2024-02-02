# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

import enum


def foo(n, c, ls):
    cs = []
    gs = []
    for i, val in enumerate(ls):
        if val == c:
            cs.append(i)
        if val == 'g':
            gs.append(i)
    # print(cs, gs)
    ans = 0
    gi = 0
    for ci, idx in enumerate(cs):
        while gi < len(gs) and gs[gi] < idx:
            gi += 1
        cur = float('inf')
        # print(idx, gs[0], end=' ')
        if gs and idx >= gs[0]:
            cur = min(cur, n - idx + gs[0])
            # print(cur, end=' ')
        if gi < len(gs):
            cur = min(cur, gs[gi] - idx)
            # print(cur, end=' ')
        ans = max(ans, cur)
        # print(ans)
    return ans

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, c = [i for i in input().split()]
        n = int(n)
        ls = input()
        print(foo(n, c, ls))