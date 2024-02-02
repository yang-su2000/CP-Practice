# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(n, a):
    ans = [0] * n
    ans[0] = 1
    for i in range(1, n):
        ans[i] = min(ans[i-1] + 1, i + 1, a[i])
    return sum(ans)

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = [int(i) for i in input().split()]
        print(foo(n, a))