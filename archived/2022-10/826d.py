# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def dfs(ls, l, r):
    if l + 1 == r:
        if ls[l] < ls[r]:
            return 0, ls[l], ls[r]
        else:
            return 1, ls[r], ls[l]
    mid = (l + r) // 2
    ans1, lo1, hi1 = dfs(ls, l, mid)
    ans2, lo2, hi2 = dfs(ls, mid+1, r)
    if ans1 == -1 or ans2 == -1:
        return -1, -1, -1
    if hi1 < hi2:
        if hi1 + 1 == lo2:
            return ans1 + ans2, lo1, hi2
        return -1, -1, -1
    else:
        if hi2 + 1 == lo1:
            return 1 + ans1 + ans2, lo2, hi1
        return -1, -1, -1

def foo(n, ls):
    if n == 1:
        return 0
    ans, lo, hi = dfs(ls, 0, n-1)
    return ans

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        ls = [int(i) for i in input().split()]
        print(foo(n, ls))