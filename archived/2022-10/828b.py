# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(n, q, ls, qs):
    even = 0
    odd = 0
    s = sum(ls)
    ans = []
    for i in ls:
        if i % 2:
            odd += 1
        else:
            even += 1
    for type, i in qs:
        if type == 0:
            s += even * i
            if i % 2:
                odd, even = odd + even, 0
            else:
                odd, even = odd, even
        else:
            s += odd * i
            if i % 2:
                odd, even = 0, odd + even
            else:
                odd, even = odd, even
        ans.append(s)
    return ans

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, q = [int(i) for i in input().split()]
        ls = [int(i) for i in input().split()]
        qs = []
        for _ in range(q):
            qs.append([int(i) for i in input().split()])
        for s in foo(n, q, ls, qs):
            print(s)