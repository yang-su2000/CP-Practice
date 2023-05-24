# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(n, k, ls):
    for i in ls:
        if i == 1:
            return True
    return False

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, k = [int(i) for i in input().split()]
        ls = [int(i) for i in input().split()]
        if foo(n, k, ls):
            print('YES')
        else:
            print('NO')