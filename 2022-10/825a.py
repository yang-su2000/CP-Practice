# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(n, a, b):
    ans1 = 0
    for i in range(n):
        if a[i] != b[i]:
            ans1 += 1
    a.sort()
    b.sort()
    ans2 = 1
    for i in range(n):
        if a[i] != b[i]:
            ans2 += 1
    return min(ans1, ans2)

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = [int(i) for i in input().split()]
        b = [int(i) for i in input().split()]
        print(foo(n, a, b))