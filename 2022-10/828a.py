# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(n, ls, s):
    d = {}
    for i in range(n):
        if ls[i] in d:
            if d[ls[i]] != s[i]:
                return False
        else:
            d[ls[i]] = s[i]
    return True

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        ls = [int(i) for i in input().split()]
        s = input()
        if foo(n, ls, s):
            print("YES")
        else:
            print("NO")