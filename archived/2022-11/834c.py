# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(l, r, x, a, b):
    if a == b:
        return 0
    if abs(a - b) >= x:
        return 1
    if min(a, b) - l >= x or r - max(a, b) >= x:
        return 2
    if r - min(a, b) >= x and max(a, b) - l >= x:
        return 3
    return -1

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        l, r, x = [int(i) for i in input().split()]
        a, b = [int(i) for i in input().split()]
        print(foo(l, r, x, a, b))