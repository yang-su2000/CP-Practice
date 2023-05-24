# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict
import math

def foo(n, ls):
    needs = n
    pows = []
    for i, val in enumerate(ls):
        ilog = int(math.log2((i+1) & -(i+1)))
        if ilog > 0:
            pows.append(ilog)
        vlog = int(math.log2(val & -val))
        needs -= vlog
    # print(needs, pows)
    if needs <= 0:
        return 0
    pows.sort()
    ans = 0
    while needs > 0 and pows:
        needs -= pows.pop()
        ans += 1
    if needs > 0:
        return -1
    return ans

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        ls = [int(i) for i in input().split()]
        print(foo(n, ls))