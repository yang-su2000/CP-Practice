# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

import bisect

def foo(n, k, h, p):
    h2 = []
    p2 = []
    for hi, pi in sorted(zip(h, p), reverse=True):
        h2.append(hi)
        if p2:
            p2.append(min(p2[-1], pi))
        else:
            p2.append(pi)
    # print(h2, p2)
    ck = 0
    while k > 0:
        ck += k
        # print(ck, end=' ')
        if ck >= h2[0]:
            # print()
            return True
        l = 0
        r = n-1
        while l < r:
            mid = (l+r+1) // 2
            if h2[mid] > ck:
                l = mid
            else:
                r = mid-1
        k -= p2[l]
    # print()
    return False

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, k = [int(i) for i in input().split()]
        h = [int(i) for i in input().split()]
        p = [int(i) for i in input().split()]
        if foo(n, k, h, p):
            print('Yes')
        else:
            print('No')