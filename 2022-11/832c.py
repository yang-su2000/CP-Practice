# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(n, ls):
    target = ls[0]
    has = min(ls[1:])
    if has < target:
        return 'Alice'
    return 'Bob'

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        ls = [int(i) for i in input().split()]
        print(foo(n, ls))