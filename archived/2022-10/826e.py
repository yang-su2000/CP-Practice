# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(n, ls):
    flags = [False] * (n)
    for i in range(n):
        # left
        if i - ls[i] == 0:
            flags[i] = True
        elif i > ls[i] and flags[i - ls[i] - 1]:
            flags[i] = True
        # right
        if i + ls[i] < n and (i == 0 or flags[i-1]):
            flags[i + ls[i]] = True
    # print(flags)
    return flags[-1]

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        ls = [int(i) for i in input().split()]
        if foo(n, ls):
            print('YES')
        else:
            print('NO')